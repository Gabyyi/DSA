#include <iostream>
using namespace std;
#define Nmax 100
template <typename T>
class Queue
{
private:
    T queueArray[Nmax];
    int head, tail;

public:
    void enqueue(T x)
    {
        if (tail >= Nmax)
        {
            fprintf(stderr, "Error 101 - The queue is full!\n");
            return;
        }
        queueArray[tail] = x;
        tail++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            //fprintf(stderr, "Error 102 - The queue is empty!\n");
            T x;
            return x;
        }
        T x = queueArray[head];
        head++;
        return x;
    }
    T peek()
    {
        if (isEmpty())
        {
            fprintf(stderr, "Error 103 - The queue is empty!\n");
            T x;
            return x;
        }
        return queueArray[head];
    }

    int isEmpty()
    {
        return (head == tail);
    }

    Queue()
    {
        head = tail = 0; // the queue is empty in the beginning
    }
};