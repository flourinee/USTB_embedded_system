extern int FindMax(int* Array,int ArraySize){
    int max=Array[0];
    int i;
    for(i=1;i<ArraySize;i++){
        if(max<Array[i]){
            max=Array[i];
        }
    }
    return max;
}