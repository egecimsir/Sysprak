#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

int main(){

    int A[SIZE][SIZE], B[SIZE][SIZE], ERG[SIZE][SIZE];

    // Generating random numbers
    srand(time(NULL));

    // initializing A and B
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            B[i][j] = rand()%10;
            A[i][j] = rand()%10;
        }
    }

    // A x B
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            int temp = 0;
            for(int n=0; n<SIZE; n++){
                temp += A[i][n] * B[n][j];
            }
            ERG[i][j] = temp;
        }
    }

    // Printing out
    for (int i=0; i < SIZE; i++) {
        for (int j=0; j < SIZE; j++) printf("%i ", A[i][j]);
        if (i == SIZE/2) printf("* "); else printf("  ");
        for (int j=0; j < SIZE; j++) printf("%i ", B[i][j]);
        if (i == SIZE/2) printf("= "); else printf("  ");
        for (int j=0; j < SIZE; j++) printf("%3d ", ERG[i][j]);
        printf("\n");
    }

    return 0;
}