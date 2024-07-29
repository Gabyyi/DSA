#include<iostream>
#include "LinkedList.h"
#include "DoublyLinkedList.h"
using namespace std;

//-----Exercise 1-----

int sum(LinkedList<int> l){
    int s=0;
    Node<int>* node;
    while(!l.isEmpty()){
        node=l.pfirst;
        s+=l.getInfo(node);
        node=node->next;
        l.removeFirst();
    }
    return s;
}

//-----Exercise 2-----

int biggestel(LinkedList<int> l){
    Node<int>* node=l.pfirst;
    int max=l.getInfo(node);
    node=node->next;
    l.removeFirst();
    while(!l.isEmpty()){
        if(max<l.getInfo(node)) max=l.getInfo(node);
        node=node->next;
        l.removeFirst();
    }
    return max;
}

//-----Exercise 3-----

void printList(LinkedList<int> l, int &n){
    LinkedList<int> l1;
    LinkedList<int> l2;
    Node<int>* node;
    while(!l.isEmpty()){
        node=l.pfirst;
        if(l.getInfo(node)<n) l1.addLast(l.getInfo(node));
        else l2.addLast(l.getInfo(node));
        node=node->next;
        l.removeFirst();
    }
    int size1=0;
    node=l1.pfirst;
    cout<<"First list: ";
    while(node!=NULL){
        // node=l1.pfirst;
        cout<<l1.getInfo(node)<<' ';
        size1++;
        node=node->next;
        // l1.removeFirst();
    }
    cout<<"\nFirst list has "<<size1<<" elements";
    int size2=0;
    node=l2.pfirst;
    cout<<"\nSecond list: ";
    while(node!=NULL){
        // node=l2.pfirst;
        cout<<l2.getInfo(node)<<' ';
        size2++;
        node=node->next;
        // l2.removeFirst();
    }
    cout<<"\nFirst list has "<<size2<<" elements\n";
}

int main(){
    LinkedList<int> l;
    l.addFirst(1);
    l.addLast(4);
    l.addLast(4);
    l.addLast(3);
    l.addLast(7);
    l.addLast(7);
    l.addLast(2);
    l.addLast(4);
    l.addLast(4);
    l.addFirst(100);

    //-----Exercise 1-----

    cout<<sum(l)<<endl;
    
    //-----Exercise 2-----

    cout<<biggestel(l)<<endl;

    //-----Exercise 3-----

    int n=5;
    printList(l,n);

    //-----Exercise 4-----

    l.printDuplicates();

    //-----Exercise 5-----

    cout<<endl;
    Node<int>* node;
    node=l.pfirst;
    while(node!=NULL){
        cout<<l.getInfo(node)<<' ';
        node=node->next;
    }
}