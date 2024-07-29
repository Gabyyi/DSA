#include<iostream>
#include "Graph.h"
#include "myqueue.h"
using namespace std;
Graph<int,int> g(8);
Graph<int,int> G(8);
Graph<int,int> G1(10);
Graph<int,int> G2(11);
bool* visited;
bool* visited1;
bool* visited2;
int maxdegree;
int part;

//-----Exercise 1-----

void DFS(int u){
    visited[u]=true;
    cout<<u<<" ";
    for(int v=0;v<g.N;v++)
        if(g.A[u][v]==1 && !visited[v])
            DFS(v);
}

void BFS(int startnode){
    Queue<int> queue;
    queue.enqueue(startnode);
    visited[startnode]=true;
    while(!queue.isEmpty()){
        int u=queue.dequeue();
        cout<<u<<" ";
        for(int v=0;v<g.N;v++)
            if(g.A[u][v]==1 && !visited[v]){
                visited[v]=true;
                queue.enqueue(v);
            }
    }
}

//---Exercise 2-----

void dfs(int u,int d){
    visited[u]=true;
    cout<<u<<": "<<d<<endl;
    for(int v=0;v<G.N;v++)
        if(G.A[u][v]==1 && !visited[v] && d<maxdegree)
            dfs(v,d+1);
}

//-----Exercise 3-----

void bipartite(int startnode1, int startnode2){
    Queue<int> queue1;
    queue1.enqueue(startnode1);
    visited1[startnode1]=true;
    int k=0;
    while(!queue1.isEmpty()){
        int u=queue1.dequeue();
        cout<<u<<" ";
        k=0;
        for(int v=0;v<G1.N;v++){
            if(G1.A[u][v]==1 && !visited1[v]){
                visited1[v]=true;
                queue1.enqueue(v);
                k++;
            }
            if(k>2){
                cout<<"G1 is not a bipartite graph\n";
                break;
            }
        }
        if(k>2) break;
    }
    if(k<3) cout<<"G1 is a bipartite graph\n";

    Queue<int> queue2;
    queue2.enqueue(startnode2);
    visited2[startnode2]=true;
    k=0;
    while(!queue2.isEmpty()){
        int u=queue2.dequeue();
        cout<<u<<" ";
        k=0;
        for(int v=0;v<G2.N;v++){
            if(G2.A[u][v]==1 && !visited2[v]){
                visited2[v]=true;
                queue2.enqueue(v);
                k++;
            }
            if(k>2){
                cout<<"G2 is not a bipartite graph\n";
                break;
            }
        }
        if(k>2) break;
    }
    if(k<3) cout<<"G2 is a bipartite graph\n";
}

int main(){
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(4,6);
    g.addEdge(4,7);
    g.addEdge(6,5);
    g.addEdge(5,7);
    g.addEdge(7,3);
    g.addEdge(3,1);
    visited=new bool(g.N);
    for(int i=0;i<g.N;i++)
        visited[i]=false;
    
    //-----Exercise 1-----

    cout<<"DFS: ";
    DFS(4);
    cout<<"\nBFS: ";
    for(int i=0;i<g.N;i++)
        visited[i]=false;
    BFS(4);

    //-----Exercise 2----

    cout<<endl;
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(0,6);
    G.addEdge(2,3);
    G.addEdge(6,4);
    G.addEdge(4,5);
    G.addEdge(5,7);
    cin>>maxdegree;
    visited=new bool(G.N);
    for(int i=0;i<G.N;i++)
        visited[i]=false;
    dfs(0,0);
    
    //-----Exercise 3-----

    G1.addEdge(1,2);
    G1.addEdge(1,3);
    G1.addEdge(4,5);
    G1.addEdge(5,6);
    G1.addEdge(5,7);
    G1.addEdge(2,4);
    G1.addEdge(5,8);
    G1.addEdge(7,9);
    G1.addEdge(4,3);
    G1.addEdge(8,9);

    G2.addEdge(1,2);
    G2.addEdge(1,3);
    G2.addEdge(4,5);
    G2.addEdge(5,6);
    G2.addEdge(5,7);
    G2.addEdge(2,4);
    G2.addEdge(5,8);
    G2.addEdge(7,9);
    G2.addEdge(4,3);
    G2.addEdge(8,9);
    G2.addEdge(4,7);
    visited1=new bool(G1.N);
    visited2=new bool(G2.N);
    for(int i=0;i<G1.N;i++)
        visited1[i]=false;
    for(int i=0;i<G2.N;i++)
        visited2[i]=false;
    bipartite(1,1);
}