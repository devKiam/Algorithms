#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll dirRow[] = {-1, 1, 0, 0, -1, 1, -1, 1};
ll dirCol[] = {0, 0, 1, -1, -1, 1, 1, -1};

ll sizeOfRow = 10e9, sizeOfColumn = 10e9;

int bfs(map< pair<int,int>, int> &distance, int startRow, int startColumn, int destinationRow, int destinationColumn)
{
    queue<int> rowQ;
    queue<int> columnQ;
    rowQ.push(startRow); columnQ.push(startColumn);
    distance[{startRow, startColumn}] = 1;

    while(!rowQ.empty())
    {
        int rU = rowQ.front(), cU = columnQ.front();
        rowQ.pop(); columnQ.pop();

        for(int i=0; i<8; i++)
        {
            int rV = rU + dirRow[i], cV = cU + dirCol[i];

            if(rV >= sizeOfRow || cV >= sizeOfColumn || rV < 0 || cV < 0) continue;
            if(distance[{rV, cV}] == 0)
            {
                distance[{rV, cV}] = distance[{rU, cU}] + 1;
                rowQ.push(rV); columnQ.push(cV);
            }
            if(distance[{destinationRow, destinationColumn}] != 0) return distance[{destinationRow, destinationColumn}] - 1; // -1 for using map, starting distance was 1 already
        }
    }

}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
//    memset(dp, -1, sizeof(dp));
    int startRow, startColumn, destinationRow, destinationColumn; cin>>startRow>>startColumn>>destinationRow>>destinationColumn;
    map< pair<int,int>, int> distance;

    cout<<bfs(distance, startRow, startColumn, destinationRow, destinationColumn);
}
