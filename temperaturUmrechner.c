#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <float.h>

typedef struct{
    char *from;
    char *to;
    float value;
    char *f;
    char *t;
}convertion_s;

void printUsage(){
    printf("Type the source unit with -f\n");
    printf("Type the destination unit with -t\n");
    printf("Celcius: c\nDelise: d\nFahrenheit: f\nKelvin: k\nRankine: r\n");
    printf("Type the value that you want to convert with -v\n");
}

float convert(convertion_s conv){
    char *from = conv.from;
    char *to = conv.to;
    float val = conv.value;
    float ret=-1;

    switch(*from){
        case 'c':
            switch(*to){
                case 'c':
                    ret = val;
                    break;
                case 'd':
                    ret = (100-val)*1.5;
                    break;
                case 'f':
                    ret = val*1.8 + 32;
                    break;
                case 'k':
                    ret = val + 273.15;
                    break;
                case 'r':
                    ret = val*1.8 + 491.67;
                    break;
                default:
                    printf("Error getting 'from'\n");
                    printUsage();
                    break;
            }
            break;
        case 'd':
            switch(*to){
                case 'c':
                    ret = (100-val)*2/3;
                    break;
                case 'd':
                    ret = val;
                    break;
                case 'f':
                    ret = 212 - val*(1.2);
                    break;
                case 'k':
                    ret = 373.15 - val*2/3;
                    break;
                case 'r':
                    ret = 671.67 - val*1.2;
                    break;
                default:
                    printf("Error getting 'from'\n");
                    printUsage();
                    break;
            }
            break;
        case 'f':
            switch(*to){
                case 'c':
                    ret = (val-32)*5/9;
                    break;
                case 'd':
                    ret = (212-val)*5/6;
                    break;
                case 'f':
                    ret = val;
                    break;
                case 'k':
                    ret = (val + 459.67)*5/9;
                    break;
                case 'r':
                    ret = val + 459.67;
                    break;
                default:
                    printf("Error getting 'from'\n");
                    printUsage();
                    break;
            }
            break;
        case 'k':
            switch(*to){
                case 'c':
                    ret = val - 273.15;
                    break;
                case 'd':
                    ret = (373.15-val)*1.5;
                    break;
                case 'f':
                    ret = val*1.8 - 459.67;
                    break;
                case 'k':
                    ret = val;
                    break;
                case 'r':
                    ret = val * 1.8;
                    break;
                default:
                    printf("Error getting 'from'\n");
                    printUsage();
                    break;
            }
            break;
        case 'r':
            switch(*to){
                case 'c':
                    ret = val*5/9 -273.15;
                    break;
                case 'd':
                    ret = (671.67 - val)*5/6;
                    break;
                case 'f':
                    ret = val - 459.67;
                    break;
                case 'k':
                    ret = val*5/9;
                    break;
                case 'r':
                    ret = val;
                    break;
                default:
                    printf("Error getting 'from'\n");
                    printUsage();
                    break;
            }
            break;
        default:
            printf("Error getting 'from'\n");
            printUsage();
            break;
    }
    return ret;
}

int main(int argc, char **argv){

    int opt;
    float ret;
    convertion_s conv;

    printUsage();

    while((opt = getopt(argc, argv, "f:t:v:")) != -1){
        switch(opt){
            case 'f':
                conv.from = optarg;
                switch(*optarg){
                    case 'c':
                        conv.f = "Celcius";
                        break;
                    case 'd':
                        conv.f = "Delise";
                        break;
                    case 'f':
                        conv.f = "Fahrenheit";
                        break;
                    case 'k':
                        conv.f = "Kelvin";
                        break;
                    case 'r':
                        conv.f = "Rankine";
                        break;
                    default:
                        break;
                }
                break;
            case 't':
                conv.to = optarg;
                switch(*optarg){
                    case 'c':
                        conv.t = "Celcius";
                        break;
                    case 'd':
                        conv.t = "Delise";
                        break;
                    case 'f':
                        conv.t = "Fahrenheit";
                        break;
                    case 'k':
                        conv.t = "Kelvin";
                        break;
                    case 'r':
                        conv.t = "Rankine";
                        break;
                    default:
                        break;
                }
                break;
            case 'v':
                conv.value = atof(optarg);
                break;
            default:
                printf("Error occured\n");
                break;
        }
    }

    ret = convert(conv);

    printf("%f %s is %f %s\n",conv.value, conv.f, ret, conv.t);

    return 0;
}