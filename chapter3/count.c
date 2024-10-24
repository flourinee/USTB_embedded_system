#include<stdio.h>
int a,b,c;
double tmp;
int main(){
    for(int i=1;i<=20;i++){
        scanf("%lf",&tmp);
        if(tmp<60) c++;
        else if(tmp<80) b++;
        else a++;
    }
    printf("A=%d B=%d C=%d",a,b,c);
    return 0;
}