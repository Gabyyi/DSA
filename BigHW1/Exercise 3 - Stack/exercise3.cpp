#include<iostream>
#include<fstream>
#include "mystack.h"
#include<string.h>
#include<string>
ifstream fin("input.txt");
ofstream fout("output.txt");
char expression[100]="";
bool error=true;
// int k=0;
using namespace std;
struct Pair{
    char variable;
    int value;
};
class Calculator{
private:
    Stack<char> expressionStack;
    Pair arr[];
public:
    Calculator(){}
    bool isValidVariable(char v){
        if(v>='A' && v<='Z') return 1;
        return 0;
    }
    bool isValidOperator(char op){
        if(op=='+' || op=='-' || op=='*' || op=='/' || op=='%') return 1;
        return 0;
    }

    void readInput(){
        string line;
        int k=0;
        while(getline(fin,line)){
            if(isValidVariable(line[0]) && isValidVariable(line[1])){
                fout<<"Wrong format";
                error=false;
                return;
            }
            if(isValidVariable(line[0]) && line[1]=='='){
                arr[k].variable=line[0];
                for(int j=0;j<line.size();j++)
                    line[j]=line[j+2];
                int num;
                arr[k].value=stoi(line);
                k++;   
            }
            
            else if(!isValidVariable(line[0]) && line[0]!='('){
                fout<<"The variable '"<<line[0]<<"' is invalid";
                error=false;
                return;
            }
            else if(isValidVariable(line[0]) && line[1]!='='){
                fout<<"The operator '"<<line[1]<<"' is invalid";
                error=false;
                return;
            }
            else if(line[0]!='(' || line[line.size()-1]!=')'){
                error=false;
                fout<<"Invalid expression0";
                return;
            }
            else if(isValidVariable(line[1]) || line[1]=='(' || line[0]=='('){
                bool ok=false;
                int open=0,close=0;
                for(int i=0;i<line.size();i++){
                    if(line[i]=='(') open++;
                    if(line[i]==')') close++;
                    if(isValidVariable(line[i]) || isValidOperator(line[i]) 
                        || line[i]=='(' || line[i]==')'){
                            ok=true;
                    }
                    else if(!isValidVariable(line[i]) || !isValidOperator(line[i]) 
                        || line[i]!='(' || line[i]!=')'){
                            ok=false;
                            fout<<"Invalid expression1";
                            error=false;
                            return;
                    }
                    if(isValidVariable(line[i]) && line[i+1]=='('){
                        ok=false;
                        fout<<"Invalid expression2";
                        error=false;
                        return;
                    }
                    else if(isValidOperator(line[i]) && line[i+1]==')'){
                        ok=false;
                        fout<<"Invalid expression3";
                        error=false;
                        return;
                    }
                    else if((isValidVariable(line[i]) && isValidVariable(line[i+1])) || 
                            (isValidOperator(line[i]) && isValidOperator(line[i+1]))){
                                ok=false;
                                fout<<"Invalid expression4";
                                error=false;
                                return;
                    }
                    // else{
                    //     cout<<"Invalid expression";
                    //     return;
                    // }
                }
                if(open!=close){
                    ok=false;
                    fout<<"Invalid expression5";
                    error=false;
                    return;
                }
                if(ok){
                    /*
                    for(int i=0;i<line.size();i++){
                        // cout<<line[i];
                        if(isValidVariable(line[i])){
                            for(int j=0;j<k;j++)
                                if(arr[j].variable==line[i]){
                                    string n=to_string(arr[j].value);
                                    strcat(expression,n.c_str());
                                }
                        }
                        else{
                            expression[strlen(expression)]=line[i];
                        }
                    }*/
                    for(int i=0;i<line.size();i++){
                        //cout<<line[i];
                        bool yes=false;
                        if(isValidVariable(line[i])){
                            for(int j=0;j<k;j++)
                                if(arr[j].variable==line[i])
                                    {expression[i]=line[i];yes=true;break;}
                            if(yes==false) {fout<<"Variable used in expression is not defined";error=false;return;}
                        }
                        else expression[i]=line[i];
                    }
                    // cout<<expression<<endl;
                    // return;
                }
            }
        }
        // for(int j=0;j<k;j++){
        //     cout<<arr[j].variable<<'='<<arr[j].value<<endl;
        // }
    }

    int execute(){
        char A;
        char IE[100]="";
        // cout<<IE<<endl;
        strcpy(IE,expression);
        cout<<IE<<endl;
        char PE[50];
        int i=0,j=0,k,nr,val,nr1,nr2;
        int n=strlen(IE);
        for(i=0;i<n;i++){
            if(isalnum(IE[i]))
                PE[j++]=IE[i];
            else
                switch(IE[i]){
        		    case '(': expressionStack.push(IE[i]);break;
        		    case ')':
                        while(expressionStack.peek()!='(' && !expressionStack.isEmpty()){
                            A=expressionStack.peek();
        			        if(A!='(') PE[j++]=A;
        			        expressionStack.pop();
        			    }
        			    // expressionStack.pop();
        			    // while(!expressionStack.isEmpty()){
                        //     A=expressionStack.peek();
                        //     if(A!='(') PE[j++]=A;
                        //     expressionStack.pop();
                        // }
        			    break;
        		    default: expressionStack.push(IE[i]);
                }
        }
        cout<<PE;
        // cout<<endl;
        while(!expressionStack.isEmpty()){
            expressionStack.pop();
        }
        n=strlen(PE);
        for(i=0;i<n;i++){
            if(isalnum(PE[i])){
                for(int l=0;l<=30;l++)
                    if(PE[i]==arr[l].variable){
                        nr=arr[l].value;
                        break;
                    }
                cout<<nr<<endl;
                expressionStack.push(nr);
            }
        	else{
        		if(PE[i]=='/' || PE[i]=='+' || PE[i]=='-' || PE[i]=='*'){
        	   		nr1=expressionStack.pop();cout<<"---"<<nr1<<' ';
               		nr2=expressionStack.pop();cout<<nr2<<endl;
                    switch(PE[i]){
        	   	        case '+':{val=nr2+nr1;break;}
        	   	        case '-':{val=nr2-nr1;break;}
        	   	        case '*':{val=nr2*nr1;break;}
        	   	        case '/':{
                            if(nr1==0){
                                return -1000000;
                            }
                            val=nr2/nr1;break;
                        }
        	        }
                    cout<<"==="<<val<<endl;
        	        expressionStack.push(val);
                    cout<<"==="<<(int)expressionStack.peek()<<endl;
        	    }
            }
        }
        int C=expressionStack.pop();
        return C;
    }

    void writeOutput(){
        if(execute()!=-1000000) {fout<<"Result="<<execute();}
        else fout<<"Division by zero";
    }
    ~Calculator(){}
};

int main(){
    Calculator c;
    c.readInput();
    // cout<<c.execute();
    if(error) c.writeOutput();
}