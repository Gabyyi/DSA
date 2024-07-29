#include <iostream>
using namespace std;

//-----Exercise 5-----

class complex
{
private:
    double re;
    double im;

public:
    complex(){};
    complex(double param_re, double param_im)
    {
        this->re=param_re;
        this->im=param_im;
    }
    double getRe()
    {
        return re;
    }
    double getIm()
    {
        return im;
    }
    complex complex_conjugate()
    {
        complex conjugate(re,-im);
        return conjugate;
    }
    complex add(complex other)
    {
        complex result(re+other.re,im+other.im);
        return result;
    }
    complex multiply(complex other)
    {
        complex result((re*other.re)-(im*other.im),(re*other.im)+(im*other.re));
        return result;
    }
};

//-----Bonus Exercise 1-----

struct Polynomial
{
    int coef;
    unsigned int exp;
};
void read(Polynomial P[],int n){
    for(int i=n;i>=0;i--){
        cin>>P[i].coef;
        P[i].exp=i;
    }
}
void write(Polynomial P[],int n){
    for(int i=n;i>0;i--)
        if(P[i].coef!=0)
            cout<<P[i].coef<<" * x^"<<i<<" + ";
    cout<<P[0].coef<<endl;
}
void add(Polynomial P1[],int n,Polynomial P2[],int m,Polynomial P[]){
    int k=0;
    k=max(m,n);
    for(int i=min(n,m);i>=0;i--){
        P[i].coef=P1[i].coef+P2[i].coef;
        P[i].exp=i;
    }
    if(n>min(n,m))
        for(int i=n;i>min(n,m);i--){
            P[i].coef=P1[i].coef;
        P[i].exp=i;
        }
    else if(m>min(n,m))
        for(int i=m;i>min(n,m);i--){
            P[i].coef=P2[i].coef;
            P[i].exp=i;
        }
}
void multiply(Polynomial P1[],int n,Polynomial P2[],int m,Polynomial P[]){
    for(int i=0;i<m+n-1;i++)  
        P[i].coef=0;
    for(int i=n;i>=0;i--)
        for(int j=m;j>=0;j--){
            P[i+j].coef+=P1[i].coef*P2[j].coef;
            P[i+j].exp=i+j;
        }
}


//-----Bonus Exercise 2-----

class BankAccount {
private:
    string name;
    string address;
    string IBAN;
    double balance;

public:
    BankAccount(string n, string addr, string iban, double initialBalance):
        name(n),address(addr),IBAN(iban),balance(initialBalance){}
    void deposit(double amount){
        if(amount>0){
            balance+=amount;
            cout<<"Deposit successful. New balance: "<<balance<<endl;
        }else cout<<"Invalid deposit amount."<<endl;
    }
    void withdraw(double amount){
        if(amount>0 && amount<=balance){
            balance-=amount;
            cout<<"Withdrawal successful. New balance: "<<balance<<endl;
        }
        else cout<<"Invalid withdrawal amount or insufficient funds."<<endl;
    }
    void displayBalance(){
        cout<<"Current balance: "<<balance<<endl;
    }
    void displayOwner(){
        cout<<"Account owner: "<<name<<endl;
    }
};

int main()
{

    //-----Exercise 1-----

    complex x(2.0,3.0);
    complex y(1.0,-2.0);
    complex sum=x.add(y);
    complex product=x.multiply(y);
    if(sum.getIm()==0)
        cout<<"Sum: "<<sum.getRe()<<endl;
    else if(sum.getIm()>0)
        cout<<"Sum: "<<sum.getRe()<<" + "<<sum.getIm()<<"i"<<endl;
    else cout<<"Sum: "<<sum.getRe()<<" - " <<sum.getIm()*(-1)<<"i"<<endl;
    if(product.getIm()==0)
        cout<<"Product: "<<product.getRe()<<endl;
    else if(product.getIm()>0)
        cout<<"product: "<<product.getRe()<<" + "<<product.getIm()<<"i"<<endl;
    else cout<<"Product: "<<product.getRe()<<" - "<<product.getIm()*(-1)<<"i"<<endl;

    //-----Bonus Exercise 1-----

    int n,m;
    Polynomial P1[50],P2[50],P[100];
    cin>>n;
    read(P1,n);
    write(P1,n);
    cin>>m;
    read(P2,m);
    write(P2,m);
    add(P1,n,P2,m,P);
    write(P,max(m,n));
    multiply(P1,n,P2,m,P);
    write(P,m+n-1);


    //-----Bonus Exercise 2-----

    BankAccount myAccount("John","Uni Street","RO2384632874",100000);
    myAccount.displayOwner();
    myAccount.displayBalance();
    myAccount.deposit(5000);
    myAccount.withdraw(20000);
    myAccount.displayBalance();
}