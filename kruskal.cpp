#include <iostream>
#include<algorithm>
using namespace std;
class Edge{
    public:
     int source;
     int dest;
     int weight;
};
bool compare(Edge e1,Edge e2){
    return e1.weight<e2.weight;
}


int findparent(int v,int *parent){
    if(parent[v]==v){
        return v;
    }
   parent[v] = findparent(parent[v], parent);
   return parent[v];
}
void kruskal(Edge *input,int n,int E){
    sort(input,input+E,compare);
    
    Edge* output=new Edge[n-1];
    int count=0;
    int i=0;
    int *parent=new int[n];
      for (int i = 0; i < n; i++)
        parent[i] = i;
    
    while(count!=n-1){
        Edge currentEdge=input[i];
        
        int SourceParent=findparent(currentEdge.source,parent);
        int destParent=findparent(currentEdge.dest,parent);
        if(SourceParent!=destParent){
            output[count]=currentEdge;
            count++;
            parent[SourceParent]=destParent;
        }
        i++;
    }
        for(int i=0;i<n-1;i++){
            if(output[i].source<output[i].dest){
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
            }else{
                cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
            }
        }
         delete[] output;
    delete[] parent;
    
}

int main() {
   int n,E;
   cin>>n>>E;
   Edge *input=new Edge[E];
   for(int i=0;i<E;i++){
       int s,d,w;
       cin>>s>>d>>w;
       input[i].source=s;
          input[i].dest=d;
          input[i].weight=w;
 }
 
 kruskal(input,n,E);
 delete[] input;

    return 0;
}