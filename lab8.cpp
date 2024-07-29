#include<iostream>
#include "Graph.h"
using namespace std;
Graph<int,int> g(10);
Graph<int,int> G(10);
bool* visited;
bool* visited1;
bool* visited2;
int k=1;

//-----Exercise 1-----

void DFS1(int u){
    visited1[u]=true;
    cout<<u<<" ";
    for(int v=0;v<g.N;v++)
        if(g.A[u][v]==1 && !visited1[v])
            DFS1(v);
}
void DFS2(int u){
    visited2[u]=true;
    cout<<u<<" ";
    for(int v=0;v<g.N;v++)
        if(g.A[u][v]==1 && !visited2[v])
            DFS2(v);
}


void isConnected(int u){
    visited[u]=true;
    // cout<<u<<" ";
    for(int v=0;v<g.N;v++)
        if(g.A[u][v]==1 && !visited[v]){
            k++;
            isConnected(v);
        }
}

//-----Exercise 2-----

void DFS(int u, bool visited[]){
    visited[u]=true;
    cout<<u<<" ";
    for(int v=0;v<G.N;v++)
        if(G.A[u][v]==1 && !visited[v])
            DFS(v,visited);
}
void connectedComponents(){
    for(int i=0;i<G.N;i++){
        if(!visited[i]){
            DFS(i,visited);
            cout<<endl;
        }
    }
}

//-----Exercise 3-----

int degree(int u){
    k=0;
    for(int i=0;i<g.N;i++)
        if(g.A[i][u]==1) k++;
    return k;
}
int hamiltonian(){
    for(int i=0;i<g.N-1;i++)
        if(degree(i)<g.N/2) return 0;
    return 1;
}

//-----Exercise 4-----

int eulerian(){
    for(int i=0;i<g.N-1;i++)
        if(degree(i)%2!=0) return 0;
    return 1;
}

//-----Exercise 5-----

int Hamiltonian(){
    int arr[50];
    for(int i=0;i<g.N-1;i++)
        if(degree(i)<g.N/2) return 0;
    return 1;
}

int main(){

    //-----Exercise 1-----

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.N=5;
    bool ok=1;
    visited1=new bool(g.N);
    for(int i=0;i<g.N;i++)
        visited1[i]=false;
    visited2=new bool(g.N);
    for(int i=0;i<g.N;i++)
        visited2[i]=false;
    DFS1(0);cout<<endl<<"---"<<endl;
    DFS2(0);
    for(int i=0;i<g.N;i++)
        if(visited1[i]!=visited2[i]) ok=0;
    if(ok) cout<<"The graph is connected\n";
    else cout<<"The graph is not connected\n";

    //-----Exercise 2-----

    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(1,3);
    G.addEdge(2,3);
    G.addEdge(4,5);
    G.addEdge(4,6);
    G.addEdge(5,6);
    G.N=7;
    visited=new bool(G.N);
    for(int i=0;i<G.N;i++)
        visited[i]=false;
    connectedComponents();

    visited=new bool(g.N);
    for(int i=0;i<g.N;i++)
        visited[i]=false;
    if(hamiltonian()) cout<<"is hamiltonian";
    else cout<<"is not";

    cout<<endl;
    if(eulerian()) cout<<"is eulerian";
    else cout<<"is not";
    
}