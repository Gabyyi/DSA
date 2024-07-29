#include<iostream>
#include<fstream>
#include "mycircularqueue.h"
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
struct Oasis{
    int water;
    int distanceToNext;
};
int main(){
    Queue<Oasis> queueInit;
    int w=0,D=0,noOasis,consumptionRate;
    fin>>noOasis>>consumptionRate;
    Oasis oasis[noOasis];
    for(int i=0;i<noOasis;i++){
        fin>>oasis[i].water>>oasis[i].distanceToNext;
        queueInit.enqueue(oasis[i]);
    }
    int i=0;
    bool ok=false;
    while(i<=noOasis){
        Queue<Oasis> queueAux=queueInit;
        while(!queueAux.isEmpty()){
            w=w+queueAux.peek().water;
            D=100*w/consumptionRate;
            if(D>=queueAux.peek().distanceToNext) queueAux.dequeue();
            else break;
        }
        if(queueAux.isEmpty()){
            fout<<i<<" is the oasis from where we can start our journey";
            ok=true;
            return 0;
        }
        i++;
        Oasis x=queueInit.dequeue();
        queueInit.enqueue(x);
    }
    if(!ok) fout<<"We cannot make the jurney";
}