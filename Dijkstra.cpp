#include <bits/stdc++.h>
using namespace std;

int mindistanceVertex(int* distance,bool* visited,int n){
    int minVertex=-1;
    
    for(int i=0;i<n;i++){
        if((!visited[i]) && (minVertex== -1 || (distance[i] < distance[minVertex]))){
            minVertex=i;
        }
    }
    return minVertex;
}

void Dijkstra(int **output,int n){
    
    bool* visited=new bool[n];
    int* distance=new int[n];
    
    for(int i=0;i<n;i++){
        visited[i]=false;
        distance[i]=INT_MAX;
    }
    distance[0]=0;
    
    
    for(int i=0;i<n-1;i++){
        int minVertex=mindistanceVertex(distance,visited,n);
        visited[minVertex]=true;
        //explore other part of vertex
        for(int j=0;j<n;j++){
            if(output[minVertex][j]!=0 && !visited[j]){
                int dist = distance[minVertex] + output[minVertex][j];
                if(dist<distance[j]){
                    distance[j]=dist;
                }
            }
        }
    }
    
    for(int i=0;i<n;i++){
           cout<<i<<" "<<distance[i]<<endl;  
    }
    
    
    delete [] visited;
    delete [] distance;
}

int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;
    
    int** output=new int*[n];
    for(int i=0;i<n;i++){
        output[i]=new int[n];
        for(int j=0;j<n;j++){
            output[i][j]=0;
        }
    }
    
    for(int i=0;i<e;i++){
        int f,s,w;
        cin>>f>>s>>w;
        
        output[s][f]=w;
        output[f][s]=w;
    }
    
    Dijkstra(output,n);

    for(int i=0;i<n;i++){
        delete [] output[i];
    }
    delete [] output;
}