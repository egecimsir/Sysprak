#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long fib(int n){
    if(n<=1){
        return n;
    }else{
        return fib(n-1) + fib(n-2);
    }
}

int main(int argc, char **argv){

    int opt;
    int num;

    while((opt = getopt(argc, argv, "f:")) != -1){
        switch(opt){
            case 'f':
                num = atoi(optarg);
                break;
        }
    }

    long f = fib(num);
    printf("%ld is %dth fib num\n",f,num);


    return 0;
}