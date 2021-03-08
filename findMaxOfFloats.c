#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

FILE* openFile(char *name){
    char dataName[100];
    FILE *data = NULL;

    if((data = fopen(dataName, "r")) != NULL){
        perror("Error by opening the file\n");

    }else{
        return data;
    }
}

int getFloats(char *name, float **arr){

    FILE *data = openFile(name);
    if(data == NULL) return EXIT_FAILURE;
    char line[256];
    int num = 0;

    while(fgets(line, 256, data) != NULL){
        float temp;
        sscanf(line, "%f\n", &temp);

        //arraning the array
        *arr = (float*) realloc(*arr, (num+1)*sizeof(float));
        (*arr)[num] = temp;
        num++;
    }
    fclose(data);
    return num;
}

int main(int argc, char **argv){

    float max;
    char *dataName = NULL;

    if(argc < 2){
        printf("You need to pass a file.\n");
    }else{
        dataName = argv[1];
    }

    float *floatArray = NULL;
    int num = getFloats(dataName, &floatArray);

    max = floatArray[0];
    for(int i=0; i<num; i++){
        if(floatArray[i] > max){
            max = floatArray[i];
        }
    }

    printf("Max of floats: %f", max);
    if(floatArray != NULL) free(floatArray);

    return EXIT_SUCCESS;
}