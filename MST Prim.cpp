#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll prim(vector<ll> adjList[], vector<ll> cost[], vector<ll> &parent, ll source)
{
    priority_queue< pair<ll, pair<ll,ll> >, vector<pair<ll, pair<ll,ll> >>, greater<> > pq;
    pq.push(make_pair(0, make_pair(-2, source)));
    ll minCost = 0;

    while(!pq.empty())
    {
        ll u = pq.top().second.second;
        ll from = pq.top().second.first;
        ll c = pq.top().first;
        pq.pop();

        if(parent[u] > -1) continue;
        minCost += c;
        parent[u] = from;

        for(ll i=0; i<adjList[u].size(); i++)
        {
            ll v = adjList[u][i];
            if(parent[v] == -1)
            {
                pq.push(make_pair(cost[u][i], make_pair(u,v)));
            }
        }
    }
    return minCost;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
//    memset(dp, -1, sizeof(dp));
    ll numOfNodes, numOfEdges; cin>>numOfNodes>>numOfEdges;
    vector<ll> adjList[numOfNodes+1];
    vector<ll> cost[numOfNodes+1];
    vector<ll> parent(numOfNodes+1, -1);

    for(ll i = 0; i<numOfEdges; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    ll source; cin>>source;

    cout<<prim(adjList, cost, parent, source)<<endl;

}
