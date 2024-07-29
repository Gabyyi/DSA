#include <iostream>
#include "mystack.h"
#include "mycircularqueue.h"
using namespace std;

//-----Exercise 1-----

template <typename T>
void baseConver(T n){
    Stack<T> number;
    while(n!=0){
        number.push(n%2);
        n/=2;
    }
    while(!number.isEmpty())
        cout<<number.pop();
}

//-----Exercise 3-----

template <typename T>
class QueuedStack{
private:
    Queue<T>Q1;
    Queue<T>Q2;
public:
    QueuedStack(){}
    void push(T value){
        Q2=Q1;
        Q1.emptyQueue();
        Q1.enqueue(value);
        while(!Q2.isEmpty()){
            Q1.enqueue(Q2.dequeue());
        }
        Q2.emptyQueue();
    }
    T pop(){
        if(Q1.isEmpty()){
            cout<<"The Queued Stack is empty";
            return -1;
        }
        return Q1.dequeue();
    }
    bool isEmpty(){
        return Q1.isEmpty();
    }
    ~QueuedStack(){}
};

//-----Exercise 4-----

template <typename T>
class StackedQueue{
    private:
    Stack<T>S1;
    Stack<T>S2;
public:
    StackedQueue(){}
    void enqueue(T value){
        S1.push(value);
    }
    T dequeue(){
        while(!S1.isEmpty()){
            S2.push(S1.pop());
        }
        T copy=S2.pop();
        while(!S2.isEmpty()){
            S1.push(S2.pop());
        }
        return copy;
    }
    bool isEmpty(){
        return S1.isEmpty();
    }
    ~StackedQueue(){}
};

int main()
{
    //-----Exercise 1-----

    baseConver(18);

    //-----Exercise 2-----

    cout<<endl;
    Queue<int> queue;
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.dequeue();
    queue.enqueue(10);
    while(!queue.isEmpty()){
        cout<<queue.dequeue()<<" ";
    }

    //-----Exercise 3-----

    cout<<endl;
    QueuedStack<int> qs;
    qs.push(5);
    qs.push(4);
    qs.push(2);
    qs.push(6);
    while(!qs.isEmpty()){
        cout<<qs.pop()<<' ';
    }

    //-----Exercise 4-----

    cout<<endl;
    StackedQueue<int> sq;
    sq.enqueue(5);
    sq.enqueue(4);
    sq.enqueue(3);
    sq.enqueue(2);
    sq.enqueue(1);
    while(!sq.isEmpty()){
        cout<<sq.dequeue()<<' ';
    }
}