#include <stdio.h>
#include <stdlib.h>
bool prime(int x){
    if(x<2) return false;
    if(x>2 && x%2==0) return false;
    if(x==2) return true;
    for(int i=2;i<x;i++)
        if(x%i==0) return false;
    return true;
}
void primeNumbers(int n){
    int x=2;
    while(n!=0){
        if(prime(x)){
            printf("%d ",x);
            n--;
        }
        x++;
    }
}

int factorial(int n){
    if(n==1) return 1;
    return n*factorial(n-1);
}

int gcd(int a, int b){
    while(a!=b){
        if(a>b) a=a-b;
        else b=b-a;
    }
    return a;
}
bool relativelyPrime(int a, int b){
    if(gcd(a,b)==1) return true;
    return false;
}
int main(){
    int n;
    printf("%s","n=");
    scanf("%d",&n);
    primeNumbers(n);
    printf("\n%s","n=");
    scanf("%d",&n);
    printf("%d",factorial(n));
    int a,b;
    printf("\n%s","a=");
    scanf("%d",&a);
    printf("%s","b=");
    scanf("%d",&b);
    if(relativelyPrime(a,b)==true){
        printf("%s","The numbers ");
        printf("%d",a);
        printf("%s"," and ");
        printf("%d",b);
        printf("%s"," are relatively prime");
    }
    else{
        printf("%s","The numbers ");
        printf("%d",a);
        printf("%s"," and ");
        printf("%d",b);
        printf("%s"," are not relatively prime");
    }
}