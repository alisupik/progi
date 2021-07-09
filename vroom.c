#include <stdlib.h>
#include <stdio.h>
int divs(int x);
int sravn(int a, int b);
void sort(int *arr,int n);

int divs(int x){
    int res;
    int i;
    res=2;
    if (x==1){
        res=1;
    }
    for(i=2; i<x/2+1; i++){
        if (x%i==0){
            res=res+1;
        }
    }
    return res;
}
int sravn(int a, int b){
    int res;
    res=divs(b)-divs(a);
    if (res!=0){
        return res;
    }
    else{
        return (a-b);
    }
}
void sort(int *arr, int n){
    int t = 0;
    int f = 1;
    int i;
    int j;


    while (n > 0 && f) {
        f = 0;

        for (int j = 0; j < n - 1; j++) {
            if (sravn(arr[j], arr[j + 1]) > 0) {
                f = 1;

                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
        n--;
    }
}

int main(){
    FILE *in;
    int n=0;
    int i;
    int a;
    int *arr;
     if(!(in=fopen("in.txt","r"))){
        printf("Can't open!\n");
        return -1;
    }

    while (!feof(in) && fscanf(in,"%d ",&a)){
        n++;
    }

    if(!feof(in)){
        printf("Bad input!\n");
        fclose(in);
        return -1;
    }
    rewind(in);

    if(!(arr=(int*)malloc(n*sizeof(int)))){
        printf("Not enough memory\n");
        fclose(in);
        return -1;
    }

    for(i=0; i<n; i++){
        fscanf(in,"%d",&arr[i]);
    }
    sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    fclose(in);
    free(arr);

    return 0;
}
