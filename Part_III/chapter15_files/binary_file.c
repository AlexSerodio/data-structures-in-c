#include <stdio.h>
#include <stdlib.h>

struct point {
    float x;
    float y;
    float z;
};
typedef struct point Point;

//saves an array of points in a binary file
void save (char* file, int n, Point* array)
{  
    FILE* fp = fopen(file,"wb");
    if(fp == NULL) {
        printf("Not able to open the file.\n");
        exit(1);
    }
    fwrite(array,sizeof(Point),n,fp);
    fclose(fp);
}

//saves an array of points from a binary file
void load (char* file, int n, Point* array)
{
    FILE* fp = fopen(file,"rb");
    if(fp == NULL) {
        printf("Not able to open the file.\n");
        exit(1);
    }
    fread(array,sizeof(Point),n,fp);
    fclose(fp);
}