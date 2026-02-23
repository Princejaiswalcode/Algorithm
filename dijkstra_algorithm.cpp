#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<climits>
using namespace std;

class Edge{
    public :
        int v;//node
        int wt;//weight of node

        Edge(int v,int wt){
            this->v=v;
            this->wt=wt;
        }
};

void dijkstra_algorithm(int src,vector<vector<Edge>>g,int V){
    vector<int>dist(V,INT_MAX);//all values initillized to infinite
    dist[src]=0;//0|infinite|infinite|infinite|infinite|infinite|
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;//pair is <dist[u],u>
    pq.push({0,src});//dist[u],u
    
    while(pq.size()>0){//till the priortity queue gets empty
        int u=pq.top().second;//second element of pq.top i.e. u not dist[u]
        int curdist=pq.top().first;
        pq.pop();//remove that from queue
        if(curdist>dist[u]) continue;//for passing the distances that are bigger than the shorter one

        //edge relaxation step
        for(Edge e :g[u]){
            if(dist[e.v]>dist[u]+e.wt)
            {
                dist[e.v]=dist[u]+e.wt;
                pq.push({dist[e.v],e.v});
            }
        }
    }
    cout<<"---------------------------------------------"<<endl<<endl;
    cout<<"shortest distance from "<<src<<" to all node "<<endl;
    for(int i=0;i<V;i++)
    {
        cout<<src<<" to Node "<<i<<" -> "<<dist[i]<<endl;
    }
    cout<<"---------------------------------------------"<<endl;
    cout<<endl<<endl;
}

int main()
{
    int V=5;
    vector<vector<Edge>>g(V);//graph structure
    g[0].push_back(Edge(1,6));
    g[0].push_back(Edge(3,1));

    g[1].push_back(Edge(2,5));
    g[1].push_back(Edge(4,2));

    g[3].push_back(Edge(1,2));
    g[3].push_back(Edge(4,1));

    g[4].push_back(Edge(2,5));
    dijkstra_algorithm(0,g,V);
    return 0;
}