#include<stdio.h>
#include<stdlib.h>
#define gcx getchar_unlocked
#define pcx putchar_unlocked
typedef long int lint;

static inline lint getValue(){
    lint n = 0;
    int c = gcx();
    while(c<'0' || c>'9') c = gcx();
    while(c>='0' && c<='9'){
        n = n*10 + c-'0';
        c=gcx();
    }
    return n;
}
int isPrime(int num){
    int i=0;
    int chkPrime = 1;
    for(i=2;i<=num/2;i++){
        if(num%i==0){
            chkPrime = 0;
            break;
        }
    }
    return chkPrime;
}
int main(){
    lint num = getValue();
    int i,sum=2,count=0;
    for(i=3;i<num+1;i++){
        // printf("i:%d  is prime? %d\n",i,isPrime(i));
        if(isPrime(i)==1){
            sum+=i;
            if(isPrime(sum)==1)
                count++;
        }
        if(sum>num){
            break;
        }
    }
    printf("%d",count);
}