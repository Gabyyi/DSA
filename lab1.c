#include <stdio.h>
#include <stdlib.h>
float min(float a, float b, float c){
    if(a<b && a<c) return a;
    if(b<a && b<c) return b;
    return c;
}

int sumd(int x){
    int s=0;
    while(x!=0){
        s=s+x%10;
        x/=10;
    }
    return s;
}
int sum(int a,int b){
    int s=0;
    if(a<b)
        for(int i=a;i<=b;i++)
            s=s+sumd(i);
    else
        for(int i=b;i<=a;i++)
            s=s+sumd(i);
    return s;
}

int palindrom(int x){
    int y=x;
    int n=0;
    while(y!=0){
        n=n*10+y%10;
        y/=10;
    }
    if(n==x) return 1;
    return 0;
}
int main()
{
    /*
    printf("Hello World\n");
    int x=10;
    printf("An integer variable: %d \n",x);
    char c='a';
    printf("A character variable: %c \n",c);
    char f[]="Message";
    printf("the string is: %s \n ",f);


    float a,b;
    scanf("%f %f",&a ,&b);
    // scanf("%f",&b);
    float avg=0;
    avg=(a+b)/2;
    printf("%.2f\n",avg);

    float a,b,c;
    scanf("%f %f %f",&a,&b,&c);
    printf("%.2f\n",min(a,b,c));
    return 0;


    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",sum(a,b));
*/

    int x;
    scanf("%d",&x);
    if(palindrom(x)) printf("%s\n", "true");
    else printf("%s\n","false");
}