#include<iostream>
#include "Heap.h"
#include "maxHeap.h"
using namespace std;

//-----Exercise 2-----

template <typename T>
int Heap<T>::parrent(int poz){
    if(poz<=0 || poz>currentDim)
        return -1;
    return H[(poz-1)/2];
}
template <typename T>
int Heap<T>::leftSubTree(int poz){
    int leftChild=2*poz+1;
    if(leftChild>=0 && leftChild<=currentDim)
        return H[leftChild];
    return -1;
}
template <typename T>
int Heap<T>::rightSubTree(int poz){
    int rightChild=2*(poz+1);
    if(rightChild>=0 && rightChild<=currentDim)
        return H[rightChild];
    return -1;
}

//-----Exercise 3-----

template <typename T>
T Heap<T>::maxElement(){
    T maxElem=H[(currentDim+1)/2];
    for(int i=(currentDim+1)/2;i<=currentDim;i++){
        if(H[i]>maxElem)
            maxElem=H[i];
    }
    return maxElem;
}

// template <typename T>
// void heapSort(T arr[],int n){
//     maxHeap<T> mheap(n);
//     for(int i=0;i<n;i++)
//         mheap.insertElement(arr[i]);
// }

int main(){

    //-----Exercise 1-----
    
    Heap<int> heap(9);
    heap.insertElement(25);
    heap.insertElement(17);
    heap.insertElement(36);
    heap.insertElement(2);
    heap.insertElement(3);
    heap.insertElement(100);
    heap.insertElement(1);
    heap.insertElement(19);
    heap.insertElement(17);
    cout<<"min heap: ";
    while(heap.currentDim!=-1)
        cout<<heap.deleteElement()<<' ';
    

    Heap<int> heap2(9);
    heap2.insertElement(25);
    heap2.insertElement(17);
    heap2.insertElement(36);
    heap2.insertElement(2);
    heap2.insertElement(3);
    heap2.insertElement(100);
    heap2.insertElement(1);
    heap2.insertElement(19);
    heap2.insertElement(17);
    
    //-----Exercise 2-----
    
    cout<<endl;
    int x=2;
    cout<<"parrent of "<<x<<" is: "<<heap2.parrent(x)<<endl;
    cout<<"left child "<<x<<" is: "<<heap2.leftSubTree(x)<<endl;
    cout<<"right child "<<x<<" is: "<<heap2.rightSubTree(x)<<endl;

    //-----Exercise 3-----

    cout<<"max element: "<<heap2.maxElement();

    //-----Exercise 4-----

    maxHeap<int> mheap(9);
    mheap.insertElement(25);
    mheap.insertElement(17);
    mheap.insertElement(36);
    mheap.insertElement(2);
    mheap.insertElement(3);
    mheap.insertElement(100);
    mheap.insertElement(1);
    mheap.insertElement(19);
    mheap.insertElement(17);
    // int n=9;
    // int arr[]={25,17,36,2,3,100,1,19,17};
    // heapSort<int>(arr,n);
    // for(int i=0;i<n;i++)
    //     cout<<arr[i];
    cout<<endl<<"max heap: ";
    while(mheap.currentDim!=-1)
        cout<<mheap.deleteElement()<<' ';
}