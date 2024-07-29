#include <iostream>
#include "Graph.h"
using namespace std;
Graph<int,int> network(1000);
bool* visited;
void DFS(int u){
    visited[u]=true;
    for(int v=0;v<network.N;v++)
        if(network.A[u][v]==1 && !visited[v])
            DFS(v);
}
bool isConnected(int n){
    DFS(1);
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(network.A[i][j]==1 && !visited[i])
                return false;
    return true;
}
int main(){
    network.N=10;
    int connections[5][2]={{1,2},{2,3},{3,4},{4,5},{5,1}};
    for(int i=0;i<5;i++){
        network.addEdge(connections[i][0],connections[i][1]);
    }
    visited=new bool[network.N];
    for(int i=0;i<network.N;i++)
        visited[i]=false;
    if(isConnected(network.N)) cout<<"true\n";
    else cout<<"false\n";
}