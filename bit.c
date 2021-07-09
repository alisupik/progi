#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fd_in;
    FILE *fd_out;
    int x;
    int sum=0;
    int n=0;

    fd_in = fopen("input.txt", "r");
    if (fd_in == NULL) {
        return -1;
    }
    fd_out = fopen("output.txt", "w");
    if (fd_out == NULL) {
        fclose(fd_in);

        return -1;
    }
    while(fscanf(fd_in, "%d", &x)==1){
            sum=sum+x;
            n=n+1;
    }
    fprintf(fd_out,"%d", sum/n);
    return 0;
}
