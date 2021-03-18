#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

void compare(int r, int ans){
    if(ans < r){
        printf("go up\n");
    }
    if(ans > r){
        printf("go down\n");
    }
    if(ans == r){
        printf("You found it!\n");
    }
}

int zahlenraten(){

    srand(time(NULL));
    int r = rand()%100;
    int ans;
    int turn = 1;

    while(true){
        printf("Your %dth guess: ",turn);
        scanf("%d", &ans);
        compare(r,ans);
        if(ans == r) break;
        turn++;
    }
    return turn;
}


int main(){

    int turn = zahlenraten();
    char name[20];

    printf("You guessed in %d turn\nYour name: ", turn);
    scanf("%s\n", &name);

    return 0;
}