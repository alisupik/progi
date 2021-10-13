#include <stdio.h>
void boop(int m, int n, int i, int j, double a[m][n]);
void boop(int m, int n, int i, int j, double a[m][n]){
    double t;
    for (int c=0; c<m; c++){
        t=a[c][i];
        a[c][i]=a[c][j];
        a[c][j]=t;
    }

}
int main(){
    int m, n;
    int i, j;
    printf("Enter m:\n");
    scanf("%d", &m);
    printf("Enter n:\n");
    scanf("%d", &n);
    double  a[m][n];
    printf("Enter %d elements:\n", m*n);
    for(int c=0; c<m; c++){
        for (int b=0; b<n; b++){
            scanf( "%lf", &a[c][b]);
            }
        }
    printf("Enter i:\n");
    scanf("%d", &i);
    printf("Enter j:\n");
    scanf("%d", &j);

    boop(m, n, i, j, a);
    for(int c=0; c<m; c++){
        for (int b=0; b<n; b++){
            printf("%lf", a[c][b]);
            }
        printf("\n");
        }
    return 0;
}
