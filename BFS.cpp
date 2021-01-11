#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;


void bfs(vector<ll> adjList[], vector<ll> &distance, vector<ll> &parent, ll source)
{
    queue<ll> q;
    q.push(source);
    distance[source] = 0;

    while (!q.empty())
    {
        ll u = q.front();
        q.pop();

        for(int i=0; i < adjList[u].size(); i++)
        {
            int v = adjList[u][i];

            if(distance[v] == -1)
            {
                distance[v] = distance[u] + 1;
                parent[v] = u;
                q.push(v);
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
    vector<ll> distance(numOfNodes+1, -1);
    vector<ll> parent(numOfNodes+1, -1);

    for(int i=1; i<=numOfEdges; i++)
    {
        ll u, v; cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    ll source; cin>>source;

    bfs(adjList, distance, parent, source);

    int destination, copyDestination; cin>>destination; copyDestination = destination;
    vector<int> result;
    while(parent[destination] != source)
    {
        result.push_back(parent[destination]);
        destination = parent[destination];
    }
    reverse(result.begin(), result.end());

    cout<<source<<" ";
    for(int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<copyDestination<<" ";

}
