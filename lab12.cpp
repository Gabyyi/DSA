#include <iostream>
#include <stdlib.h>
#include "hash.h"
#define VMAX 17
#define P 13
using namespace std;

//-----Exercise 1 A-----

int hfunc(int key){
    return key%11;
}

Hashtable<int,int> table(11,hfunc);

void linearProbing(Hashtable<int,int> &table, int key, int value){
    int index;
    index=hfunc(value);
    while(table.hasKey(index)){
        index++;
    }
    table.put(index,value);
}

//-----Exercise 2-----

int cnp_hash_function(const string& cnp){
    int sum=0;
    for(char c : cnp){
        sum+=static_cast<int>(c);
    }
    return sum%10000;
}

int main() {

    //-----Exercise 1 A-----

    int values[]={113,117,97,100,114,108,116,105,99};
    int nr_keys=11;
    int keys[]={0,1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<11;i++){
        // table.put(keys[i],values[i]);
        linearProbing(table,keys[i],values[i]);
    }
    for(int i=0;i<11;i++)
        cout<<"The value of "<<keys[i]<<" is: "<<table.get(keys[i])<<endl;
    cout<<endl;

    //-----Exercise 1 B-----

    Hashtable<int,int> hashTable(11, hfunc);
    for(int i=0;i<11;i++){
        hashTable.put(hfunc(values[i]),values[i]);
    }
    for(int i=0;i<11;i++)
        cout<<"The value of "<<i<<" is: "<<hashTable.get(i)<<endl;
    cout<<endl;
	
    //-----Exercise 2-----
    
    string cnp1="1234567890123";
    string cnp2="9876543210987";

    cout<<"Hash value for CNP1: "<<cnp1<<" is: "<<cnp_hash_function(cnp1)<<endl;
    cout<<"Hash value for CNP2: "<<cnp2<<" is: "<<cnp_hash_function(cnp2)<<endl;


    return 0;
}

