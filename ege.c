#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#include "ege.h"

//TODO: Debug
bool checkpassword(info_s info){
    int n = 2;
    char *p = malloc(sizeof(info.password));
    bool canEnter = true;
    printf("\nVerify password: ");
    scanf("%s", p);

    while(true){
        if(n == 0){
            printf("\nYou cannot enter\n");
            canEnter = false;
            break;
        }
        if(p == info.password){
            printf("Correct\n");
            canEnter = true;
            break;
        }else{
            if(n==1){
                printf("False! You have %d try left\n\nTry Again: ", n);
            }else{
                printf("False! You have %d tries left\n\nTry Again: ", n);
            }
            scanf("%s", p);
            n--;
        }
    }
    return canEnter;
}

void connectDatabase(){
    printf("Database\n");
}

int main(int argc, char **argv){

    int opt, fd[2];
    info_s info;
    pid_t pid;
    bool canEnter, admin=false;

    while((opt = getopt(argc,argv,"u:p:a:")) != -1){
        switch(opt){
            case 'u':
                info.username = malloc(sizeof(optarg));
                strcpy(info.username, optarg);
                break;
            case 'p':
                info.password = malloc(sizeof(optarg));
                strcpy(info.password, optarg);
                break;
            case 'a':
                printf("Admin rights enabled for ");
                admin = true;

        }
    }
    printf("username: %s\n", info.username);

    //Pipe
    if(pipe(fd) < 0){
        perror("Pipe Error\n");
        return EXIT_FAILURE;
    }

    //fork
    if((pid = fork()) < 0){
        perror("Fork Error\n");
        return EXIT_FAILURE;

    }else if(pid > 0){//Parent process

        if (waitpid(pid, NULL, 0) != pid) {
            perror ("Fehler beim Warten auf Kindprozess\n");
            return EXIT_FAILURE;
        }
        canEnter = true; //temp
        connectDatabase();
    }
    else{ //Child process

        checkpassword(info);
    }


    return EXIT_SUCCESS;
}