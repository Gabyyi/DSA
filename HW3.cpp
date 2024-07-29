#include<iostream>
#include<cstring>
#include "mystack.h"
using namespace std;

//-----Bonus Exercise 1-----

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
        //int top=Smain.getTopLevel();
        //cout<<'\n'<<top<<'\n';
        while(!Saux.isEmpty()){
            if(Saux.getTopLevel()==i) {Smain.push(aux1);Saux.pop();}
            if(Saux.getTopLevel()==j) {Smain.push(aux2);Saux.pop();}
            Smain.push(Saux.pop());
        }
        while(!Smain.isEmpty())
        {
            cout<<Smain.pop()<<'\n';
        }
    }
};

int main(){

    //-----Bonus Exercise 1

    LargeStack<int> stk;
    stk.push(5);
    stk.push(2);   //1
    stk.push(4);
    stk.push(8);   //3
    stk.push(7);
    stk.swap(1,3);

/*  Smain    Saux    Smain
4   7        5       7
3   8 ---    2       2 ***
2   4        4       4
1   2 ***    8       8 ---
0   5        7       5
*/

    //-----Bonus Exercise 2-----
    Stack<char> stack;
    string s;
    getline(cin,s);
    int length=s.length();
    for(int i=0;i<length;i++){
        if(s[i]==' '){
            for(int j=i;j<length;j++)
                s[j]=s[j+1];
            length--;
        }
    }
    for(int i=0;i<length/2;i++)
        stack.push(s[i]);
    int lengthh=length;
    if(length%2!=0) 
        lengthh=length+1;
    for(int i=lengthh/2;i<length;i++)
        if(s[i]!=stack.pop()) cout<<"The string is not palindrome";
    cout<<"The string is palindrome";
}