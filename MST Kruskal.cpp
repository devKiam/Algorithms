#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

vector<int> parent;

int find(int i)
{
    if(parent[i] == i)
        return i;

    int result = find(parent[i]);
    parent[i] = result;
    return result;
}


int kruskal(vector< pair<ll,pair<ll,ll> > > &edgeList, int numOfEdges)
{
    int MSTCount = 0, MSTweigh = 0;
    for(int i=0; i<edgeList.size(); i++)
    {
        int u = edgeList[i].second.first;
        int v = edgeList[i].second.second;
        int w = edgeList[i].first;

        int rootU = find(u), rootV = find(v);

        if(rootU != rootV)
        {
            parent[rootV] = rootU;
            MSTCount++;
            MSTweigh += w;
            if(MSTCount == numOfEdges - 1) break;
        }
    }
    return MSTweigh;

}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int numOfNodes, numOfEdges; cin>>numOfNodes>>numOfEdges;

    vector< pair<ll,pair<ll,ll> > > edgeList;

    for(int i=0; i<numOfEdges; i++)
    {
        int u, v, w; cin>>u>>v>>w;
        edgeList.push_back(make_pair(w, make_pair(u, v)));
    }
    sort(edgeList.begin(), edgeList.end());

    for(int i=0; i<=numOfNodes; i++){
        parent.push_back(i);
    }

    cout<<kruskal(edgeList, numOfEdges)<<endl;
}
