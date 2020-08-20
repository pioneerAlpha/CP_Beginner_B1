#include<bits/stdc++.h>
#define ll long long
#define N ((int)3e5 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

vector < int > vec[N];

pair < int , int > dfs(int n , int par , int dis)
{
    pair < int , int > ans = {dis,n};
    for(int a:vec[n]){
        if( a != par ){
            pair < int , int > tmp = dfs(a,n,dis+1);
            if(tmp.first > ans.first) ans = tmp;
        }
    }

    return ans;
}


int main()
{
    fastio;
    int n;
    cin>>n;
    int m = n-1 ; /// in a tree the number of edges is n-1;
    while(m--){
        int a , b;
        cin>>a>>b;
        vec[b].push_back(a);
        vec[a].push_back(b);
    }
    pair < int , int > tmp = dfs(1,-1,0);
    int a = tmp.second;
    tmp = dfs(a,-1,0);
    int dia = tmp.first, b = tmp.second;
    cout<<"length of diameter : "<<dia<<"\nand the endpoints are "<<a<<" "<<b<<endl;
    return 0;


}
