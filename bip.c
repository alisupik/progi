#include <stdio.h>
#include <stdlib.h>
int func();
int fbit(unsigned int x);
int prime(int n);

int func(){
    FILE *in;
    int n=0;
    int i;
    unsigned int a;
    unsigned int sum=0;
    unsigned int sum_prime;
    unsigned int sum_not_prime;
    int kolvo=0;
    int max_prime=0;
    int max_not_prime=0;
    int bit=0;
    int predbit=-1;
    unsigned int res;

    if(!(in = fopen("in.txt","r"))){
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

    fclose(in);
    in = fopen("in.txt","r");

    for (i=0; i<n; i++){
        fscanf(in, "%d", &a);
        bit=fbit(a);
        if (bit==predbit || predbit==-1){
            kolvo++;
            sum=sum+a;
        }
        else{
            if (kolvo>1){
                if(prime(predbit)){
                    if (kolvo > max_prime) {
                        max_prime = kolvo;
                        sum_prime = sum;
                        }
                }
                else {
                    if (kolvo > max_not_prime) {
                        max_not_prime = kolvo;
                        sum_not_prime = sum;
                    }
                }
                kolvo=1;
            }
            sum=a;
        }
        predbit=bit;
    }

    if (kolvo>1){
        if(prime(predbit)){
            if (kolvo > max_prime) {
                max_prime = kolvo;
                sum_prime = sum;
                }
        }
        else {
            if (kolvo > max_not_prime) {
                max_not_prime = kolvo;
                sum_not_prime = sum;
            }
        }
    }

    if (max_not_prime==0 || max_prime==0) {
        printf("bad types of sequences!\n");
        return -1;
    }

    fclose(in);
    res = sum_prime - sum_not_prime;
    return res;
         }
int fbit(unsigned int x){
    int res=0;
    while(x!=0){
        res=res+(x&1);
        x=x>>1;
   }
   return res;

}
int prime(int n){
    int i=0;
    int f=1;
    if (n==1){
        f=0;
    }
    if (n==2){
        f=1;
    }
    if (n>2){
        for (i=2; i<((n/2)+1); i++){
            if(n%i==0){
                f=0;
            }
        }
    }

    return f;
    }
int main(){
    printf("%d", func());
    return 0;
}
