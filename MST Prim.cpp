#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;


ll prim(vector<ll> adjList[], vector<ll> edgeWeight[], vector<bool> &isVisited, vector< pair<ll,ll> > &MSTedges, ll source)
{
    priority_queue< pair<ll, pair<ll,ll> >, vector<pair<ll, pair<ll,ll> > >, greater<> > pq;
    pq.push(make_pair(0, make_pair(-1, source)));
    ll minCost = 0;

    while(!pq.empty())
    {
        ll from = pq.top().second.first;
        ll to = pq.top().second.second;
        ll w = pq.top().first;
        pq.pop();

        if(isVisited[to]) continue;
        isVisited[to] = true;
        minCost += w;

        MSTedges.push_back(make_pair(from, to));

        for(ll i=0; i<adjList[to].size(); i++)
        {
            ll u = to;
            ll v = adjList[to][i];

            if(!isVisited[v])
            {
                pq.push(make_pair(edgeWeight[to][i], make_pair(u, v)));
            }
        }

    }

    return minCost;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll numOfNodes, numOfEdges; cin>>numOfNodes>>numOfEdges;
    vector<ll> adjList[numOfNodes+1], edgeWeight[numOfNodes+1];
    vector<bool> isVisited(numOfNodes+1, false);
    vector< pair<ll, ll> > MSTedges;

    for(ll i=0; i<numOfEdges; i++){
        ll u, v, w; cin>>u>>v>>w;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        edgeWeight[u].push_back(w);
        edgeWeight[v].push_back(w);
    }

    cout<<prim(adjList, edgeWeight, isVisited, MSTedges, 1)<<endl;

    for(int i=1; i<MSTedges.size(); i++) // first MSTedge is imaginary, so start from 1
    {
        cout<<MSTedges[i].first<<" "<<MSTedges[i].second<<endl;
    }
}
