#include <iostream>
#include "mystack.h"
using namespace std;

//-----Exercise 1-----

template <typename T>
class Point
{
    private: 
        T n;
        T coord_x, coord_y;
    public:
        Point():n{},coord_x{},coord_y{}{}
        Point(T n,T x,T y):
            n{n},coord_x{x},coord_y{y}{}
        void setN(T n){
            this->n=n;
        }
        void setX(T x){
            coord_x=x;
        }
        void setY(T y){
            coord_y=y;
        }
        T getN(){
            return n;
        }
        T getCoord_x(){
            return coord_x;
        }
        T getCoord_y(){
            return coord_y;
        }
        void reset()
        {
            coord_x = coord_y = 0;
        } 
        void moveX(T x = 1)
        {
            if(coord_x+x>n){
                coord_x=coord_x+x-n;
            }
            else coord_x=coord_x+x;
        }
        void moveY(T y = 1) 
        {
            if(coord_y+y>n){
                coord_y=coord_y+y-n;
            }
            else coord_y=coord_y+y;
        }
        void moveXY(T x = 1, T y = 1)
        {
            if(coord_x+x>n || coord_y+y>n){
                reset();
            }
            else{
                coord_x=coord_x+x;
                coord_y=coord_y+y;
            }
        }
};

//-----Exercise 2-----

template <typename T>
void swapp(T &a, T &b)
{
    swap(a, b);
}
template <typename T>
void sort(T v[], int &n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(v[i]>v[j])
                swapp(v[i],v[j]);
    for(int i=0;i<n;i++)
        cout<<v[i]<<' ';
}

//-----Exercise 4-----

template <typename T>
class LargeStack{
    private:
    Stack<T> Smain,Saux;
    public:
    LargeStack(){}
    void push(T x){
        Smain.push(x);
    }
    T pop(){
        return Smain.pop();
    }
    void swap(int i,int j){
        T aux1,aux2;
        while(!Smain.isEmpty()){
            if(Smain.getTopLevel()==i) aux1=Smain.peek();
            if(Smain.getTopLevel()==j) aux2=Smain.peek();
            Saux.push(Smain.pop());
        }
        //cout<<"\nedwbhdew\n"<<aux1<<'\n'<<aux2;
        int top=Smain.getTopLevel();
        //cout<<'\n'<<top<<'\n';
        while(!Saux.isEmpty()){
            if(Saux.getTopLevel()==i) {Smain.push(aux1);Saux.pop();}
            if(Saux.getTopLevel()==j) {Smain.push(aux2);Saux.pop();}
            Smain.push(Saux.pop());
        }
        while(!Smain.isEmpty())
        {
            cout<<Smain.pop()<<" ";
        }
    }
};

int main()
{
    //-----Exercise 1-----

    Point<int> p;
    p.setN(5);
    p.setX(2);
    p.setY(3);
    p.moveX(8);
    cout<<p.getCoord_x();

    //-----Exercise 2-----

    cout<<endl;
    double v[5];
    int n=5;
    sort<double>;
    for(int i=0;i<5;i++)
        cin>>v[i];
    sort(v,n);
    cout<<endl;

    //-----Exercise 3-----
    //system("cls");

    Stack<int> stack;
    int m,x;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x;
        stack.push(x);
    }
    while(!stack.isEmpty()){
        cout<<stack.pop()<<' ';
    }

    //-----Exercise 4-----

    LargeStack<int> stk;
    stk.push(5);
    stk.push(2);   //1
    stk.push(4);
    stk.push(8);   //3
    stk.push(7);
    stk.swap(1,3);

/*
4   7        5       7
3   8 ---    2       2 ***
2   4        4       4
1   2 ***    8       8 ---
0   5        7       5
*/
}