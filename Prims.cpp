#include <bits/stdc++.h>
using namespace std;

int findMinVertex(int* weights,bool * visited,int n){
    
    int minVertex=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex])){
            minVertex=i;
        }
    }
    return minVertex;
}


void prims(int **output,int n){
    
    int* parent =new int[n];
    int* weights=new int[n];
    bool* visited =new bool[n];
    
   for(int i=0;i<n;i++){
       visited[i]=false;
       weights[i]=INT_MAX;
   }
    
    parent[0]=-1;
    weights[0]=0;
    
    for(int i=0;i<n;i++){
        //we have to find the min vertex
        int minVertex=findMinVertex(weights,visited,n);
        visited[minVertex]=true;
        
        //explore the unvisited vertex
        for(int j=1;j<n;j++){
            if(output[minVertex][j]!=0 && !visited[j]){
                if(weights[j] > output[minVertex][j]){
                    weights[j]= output[minVertex][j];
                    parent[j]= minVertex;
                }
            }
        }
    }
    
    for(int i=1;i<n;i++){
        if(parent[i]<i){
            cout<< parent[i] <<" "<<i<<" "<<weights[i]<<endl;
        }else{
             cout<<i<<" "<<parent[i]<<" "<<weights[i]<<endl;
        }
    } 
}

int main() {
    // Write your code here
   int n,e;
    cin>>n>>e;
    
    int **output=new int*[n];
    for(int i=0;i<n;i++){
        output[i]=new int[e];
        for(int j=0;j<e;j++){
            output[i][j]=0;
        }
    }
    
    for(int i=0;i<e;i++){
        int f,s,weight;
        cin>>f>>s>>weight;
        
        output[f][s]=weight;
        output[s][f]=weight;
    }
    
    prims(output,n);
    
    for(int i=0;i<n;i++){
        delete [] output[i];
    }
    
    delete [] output;
}