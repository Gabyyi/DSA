#include<iostream>
#include<cstring>
using namespace std;

//-----Exercise 1-----

void displayArray(int *arr){
    int k;
    while(k<6){
        cout<<*(arr+k)<<' ';
        k++;
    }
    cout<<endl;
}

//-----Exercise 2-----

void reverseArray(int *arr){
    for(int i=5;i>=0;i--)
        cout<<*(arr+i)<<' ';
    cout<<endl;
}

//-----Exercise 3-----

void replaceArray(int *arr, int &i){
    swap(arr[i],arr[6-i-1]);
    for(int i=0;i<6;i++)
        cout<<*(arr+i)<<' ';
    cout<<endl;
}

//-----Exercise 4-----

char *getCounty(char *p){
    char *pointer;
    pointer=strtok(p,".");
    pointer=strtok(NULL,".");
    return pointer;
}

//-----Bonus-----

void replaceSemicolon(char *p){
    for(int i=0;i<strlen(p);i++)
        if(p[i]==';') p[i]=' ';
}
int main(){

    //-----Exercise 1 2 3-----

    int arr[6];
    for(int i=0;i<6;i++)
        cin>>arr[i];
    int *a=arr;
    displayArray(a);
    reverseArray(a);
    int i=1;
    replaceArray(a,i);

    //-----Exercise 4-----

    char s[100]="Slatina.OT";
    char *p=s;
    char *b=getCounty(p);
    cout<<endl<<b;

    //-----Bonus-----

    char str[100]="College;of;London";
    char *pp=str;
    replaceSemicolon(pp);
    cout<<endl<<pp;
}