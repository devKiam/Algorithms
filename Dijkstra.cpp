#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

void dijkstra(vector<ll> adjList[], vector<ll> cost[], vector<ll> &distanceFromSource, vector<ll> &parent, ll source)
{
    priority_queue< pair<ll, ll>, vector<pair<ll, ll>>, greater<> > pq;
    pq.push(make_pair(0, source)); distanceFromSource[source] = 0;
    while(!pq.empty())
    {
        ll u = pq.top().second; pq.pop();
        for(ll i=0; i<adjList[u].size(); i++)
        {
            ll v = adjList[u][i];
            if(cost[u][i] + distanceFromSource[u] < distanceFromSource[v])
            {
                distanceFromSource[v] = cost[u][i] + distanceFromSource[u];
                pq.push(make_pair(distanceFromSource[v], v));
                parent[v] = u;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
//    memset(dp, -1, sizeof(dp));
    ll numOfNodes, numOfEdges; cin>>numOfNodes>>numOfEdges;
    vector<ll> adjList[numOfNodes+1];
    vector<ll> cost[numOfNodes+1];
    vector<ll> distanceFromSource(numOfNodes+1, LLONG_MAX);
    vector<ll> parent(numOfNodes+1, -1);

    for(ll i = 0; i<numOfEdges; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        adjList[u].push_back(v);
//        adjList[v].push_back(u);
        cost[u].push_back(w);
//        cost[v].push_back(w);
    }
    ll source, destination; cin>>source>>destination;

    dijkstra(adjList, cost, distanceFromSource, parent, source);


    //printing source to destination path
    vector<ll> v;
    ll temp = destination;
    while(true)
    {
        if(parent[temp] > -1)
        {
            v.push_back(temp);
            temp = parent[temp];
        }
        else break;
    }
    v.push_back(source);
    reverse(v.begin(), v.end());
    for(ll i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}
