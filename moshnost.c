#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    int i;
    int j;
    int z;
    int k;
    int *arr;
    int max;
    int min;
    int maxx;
    scanf("%d", &n);
    arr = malloc(n * sizeof(int));
    for(i=1; i<n; i++){
            scanf("%d", &arr[i]);
            if(i==1){
                printf("0");
            }

            max=arr[1];
            maxx=arr[1];

            for(j=1; j<i-1; j++){
                    if (arr[j]>maxx){
                        maxx=arr[j];
                        z=j;
                    }
            }
            min=arr[z+1];
            for(k=1; k<z-1;k++){
                    if (arr[k]>max){
                        max=arr[k];
                    }
            }
            for(k=z+1; k<i;k++){
                    if (arr[k]<min){
                        min=arr[k];
                    }

            }
            printf("%d\n", (max-min));
    }






    return 0;
}
