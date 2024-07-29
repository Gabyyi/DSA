#include <iostream>
using namespace std;
template<typename T> class maxHeap
{
public:
    T *H;
    int currentDim, maxDim;

    maxHeap(int maxDim)
    {
        this->maxDim = maxDim;
        H = new T[this->maxDim];
        currentDim = -1;
    }

    void insertElement(T x)
    {
        if (currentDim == maxDim-1)
        {
            cout<< "Error!"<<endl;
            return;
        }
        currentDim++;
        H[currentDim] = x;
        filterUp(currentDim);
    }

    T peek()
    {
        if (currentDim == -1)
        {
            cout<< "Error!"<<endl;
            T x;
            return x;
        }

        return H[0];
    }

    T deleteElement()
    {
        if (currentDim == -1)
        {
            cout<< "Error!"<<endl;
            T x;
            return x;
        }

        T minValue = H[0];
        H[0] = H[currentDim];
        currentDim--;
        if (currentDim > 0)
            filterDown();

        return minValue;
    }

    void filterUp(int l)
    {
        int parent;
        T vaux;

        parent = (l-1) / 2;
        while (l > 0 && H[parent] < H[l])
        {
            vaux = H[parent];
            H[parent] = H[l];
            H[l] = vaux;

            l = parent;
            parent = (l-1) / 2;
        }
    }
    void filterDown()
    {
        int l = 0;
        T vaux;

        while (1)
        {
            if (2 * l + 1 > currentDim)
            {
                if (2 * (l+1) > currentDim)
                    break;
                else if (H[2 *(l+1)] > H[l])
                {
                    vaux = H[2 * (l+1)];
                    H[2 * (l+1)] = H[l];
                    H[l] = vaux;
                    l = 2 * (l+1);
                }
                else
                    break;
            }
            else
            {

                if (H[2 * (l+1) ] >= H[2 * l + 1] && H[2 * (l+1) ] > H[l])
                {
                    vaux = H[2 * (l+1)];
                    H[2 * (l+1)] = H[l];
                    H[l] = vaux;
                    l = 2 * (l+1);
                }
                else if (H[2 * l + 1] >= H[2 * (l+1)] && H[2 * l + 1] > H[l])
                {
                    vaux = H[2 * l + 1];
                    H[2 * l + 1] = H[l];
                    H[l] = vaux;
                    l = 2 * l + 1;
                }
                else
                    break;
            }
        }
    }
    

    int parrent(int poz);
    int leftSubTree(int poz);
    int rightSubTree(int poz);
    T maxElement();
};


