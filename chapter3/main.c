#include<stdio.h>
#include"FindMax.h"
#include"FindMax.c"
int main(){
    int Array[]={1,2,3,4,5};
    printf("max: %d\n",FindMax(Array,5));
    return 0;
}