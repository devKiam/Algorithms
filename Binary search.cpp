#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;


bool binarySearch(vector<int> &v, int val)
{
    int lo = 0, hi = v.size()-1, mid;
    while(lo < hi){
        mid = (lo + hi + 1) / 2;
        if(val >= v[mid]) lo = mid;
        else hi = mid - 1;
    }
    if(v[lo] == val) return true;
    else return false;
}


int binarySearch_Right_MostSmallest(vector<int> &v, int val)
{
    int lo = 0, hi = v.size()-1, mid;
    while(lo < hi){
        mid = (lo + hi + 1) / 2;
        if(val >= v[mid]) lo = mid;
        else hi = mid - 1;
    }
    if(v[lo] > val) return lo;
    else return lo + 1;
}


int binarySearch_Left_MostGreatest(vector<int> &v, int val)
{
    int lo = 0, hi = v.size()-1, mid;
    while(lo < hi){
        mid = (lo + hi) / 2;
        if(val <= v[mid]) hi = mid;
        else lo = mid + 1;
    }
    if(v[lo] < val) return hi;
    else return hi - 1;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int vectorInput; cin>>vectorInput; v.push_back(vectorInput);
    }
    cout<<binary_search(v.begin(), v.end(), 8)<<endl; // stl built-in function
    cout<<binarySearch(v, 7)<<endl; // my implementation
    
    
    int q; cin>>q;
    int smaller = binarySearch_Left_MostGreatest(v, q);
    int greater = binarySearch_Right_MostSmallest(v, q);
    if(smaller > -1 && smaller < v.size()) cout<<v[smaller]<<" ";
    if(greater > -1 && greater < v.size()) cout<<v[greater]<<endl;

}
