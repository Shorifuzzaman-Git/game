//dijkstra algorithm
//time complexity = O(E log(v))
#include <bits/stdc++.h>
using namespace std;

const int N=1e3;
int dis[N];
vector<pair<int,int>>g[N];  //g[u(src)] -> (first-> v(node),second -> w(dis))
set<pair<int,int>>s;   //(first->dis , second->node)

void dijkstra(int src){
    // int vis[N];
    // fill(vis,vis+N,0);
    // Or
    vector<int>vis(N,0);

    dis[src]=0;
    s.insert({0,src});
    
    while (!s.empty())
    {
        auto top=*(s.begin());
        int nodeDis=top.first;
        int node=top.second;
        s.erase(s.begin());//remove top element from the set

        // if(vis[node]==1)continue;
        // vis[node]=1;

        //visit neighbour node
        for(auto neighbour:g[node]){
            if(nodeDis+neighbour.second<dis[neighbour.first]){
                dis[neighbour.first]=nodeDis+neighbour.second;   //update distance
                s.insert({dis[neighbour.first],neighbour.first});  //(dis,node)
            }
        }
    }
}

int main(){
    fill(dis,dis+N,INT_MAX);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
        //g[y].push_back({x,w});
    }
    dijkstra(1);
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
}


// Anouther system 

// #include<bits/stdc++.h>
// using namespace std;

// const int N=1e3;
// vector<vector<int>>g[N];
// vector<int>dis(N,INT_MAX);

// void dijkstra(int src){
//     set<vector<int>>s;  //(dis,node)
//     dis[src]=0;
//     s.insert({0,src});

//     while (!s.empty())
//     {
//         auto top=*s.begin();
//         int node=top[1];
//         int nodeDis=top[0];
//         s.erase(top);

//         for(auto neighbour: g[node]){
//             if(nodeDis + neighbour[1]<dis[neighbour[0]]){  // neighbour[0]=node , neighbour[1]= distance (u to v) 
//                 dis[neighbour[0]]=nodeDis+neighbour[1];
//                 s.insert({nodeDis+neighbour[1],neighbour[0]});
//             }
//         }
//     }
    
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     while (m--)
//     {
//         int u,v,w;
//         cin>>u>>v>>w;
//         g[u].push_back({v,w});
//         g[v].push_back({u,w});
//     }
//     dijkstra(1);
//     for(int i=1;i<=n;i++){
//         cout<<dis[i]<<' ';
//     }
// }

// 6 9
// 1 2 1
// 1 3 5
// 2 3 2
// 2 4 2
// 2 5 1
// 3 5 2
// 4 5 3
// 4 6 1
// 5 6 2

//negative value
// 6 9
// 1 2 6
// 1 3 4
// 1 4 5      
// 3 2 -2
// 4 3 -2
// 2 5 -1
// 3 5 3
// 4 6 -1
// 5 6 3

//negative value with negative cycle
// 4 5
// 1 2 1
// 1 3 2
// 2 3 2
// 3 4 2
// 4 2 -5