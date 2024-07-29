#include<iostream>
using namespace std;
#define nmax 5
template<typename T> 
class Queue {
    private:
        T queueArray[nmax];
        int head, tail, size;
    public:
        void enqueue(T x) {
            if (size == nmax) {
                fprintf(stderr, "Error 101 - The queue is full!\n");
                return;
            }
            queueArray[tail] = x;
            tail = (tail + 1) % nmax;
            size++;
        }
        T dequeue() {
            if (isEmpty()) {
                fprintf(stderr, "Error 102 - The queue is empty!\n");
                T x;
                return x;
            }
            T x = queueArray[head];
            head = (head + 1) % nmax;
            size--;
            return x;
        }
        T peek() {
            if (isEmpty()) {
                fprintf(stderr, "Error 103 - The queue is empty!\n");
                T x;
                return x;
            }
            return queueArray[head];
        }
        void emptyQueue(){
            while(!isEmpty()){
                this->dequeue();
            }
        }
        int isEmpty() {
            return (size == 0);
        }

    Queue() {
        head = tail = size = 0;
    }
};
