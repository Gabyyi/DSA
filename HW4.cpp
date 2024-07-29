#include<iostream>
#include "myqueue.h"
using namespace std;
int main(){
    Queue<int> queue[10];
    int arr[6]={25,13,13,51,49,90};
    int n=1,size=100;
    while(n<size){
        for(int j=0;j<=9;j++){
            for(int i=0;i<6;i++){
                if(arr[i]/n%10==j){
                    queue[arr[i]%10].dequeue();
                    queue[j].enqueue(arr[i]);
                }
            }
        }
        n*=10;
    }
    for(int i=0;i<10;i++)
        while(!queue[i].isEmpty()){
            cout<<queue[i].dequeue()<<" ";
        }
}