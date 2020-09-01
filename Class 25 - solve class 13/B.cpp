#include<bits/stdc++.h>
#define ll long long
#define N ((int)2e3 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

vector < pair < int , int > > com;

vector < int > vec[N];

int dpp[N][N/2] , col[N];

bool vis[N];

pair < int , int > dfs(int nod)
{
    vis[nod] = 1;
    int val = !col[nod];
    pair < int , int > ans = {0,0};
    if(col[nod]) ans.first++;
    else ans.second++;
    for(int a:vec[nod]){
        if(vis[a] == 0){
            col[a] = val;
            pair < int , int > tmp = dfs(a);
            if(tmp.first == -1) return {-1,-1}; /// we can't color the graph
            ans.first += tmp.first;
            ans.second += tmp.second;
        }
        else if(col[a] != val) return {-1,-1}; /// we can't color the graph
    }
    return ans;
}

bool call(int idx , int rem)
{
    if(rem < 0) return 0;
    if(idx >= com.size()){
        if(rem == 0) return 1;
        return 0;
    }

    if(dpp[idx][rem] != -1) return dpp[idx][rem] ;
    return dpp[idx][rem] = call(idx+1,rem - com[idx].first) | call(idx+1,rem - com[idx].second);
}

int main()
{
//    freopen("tour.in","r",stdin);
//    freopen("tour.out","w",stdout);
    fastio;
    int t;
    cin>>t;
    while(t--){
        int b , c, m;
        cin>>b>>c>>m;
        int n = b+c;
        for(int i = 1 ; i<=n ; i++) vec[i].clear();
        while(m--){
            int a , b;
            cin>>a>>b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        memset(vis,0,sizeof vis);
        com.clear();  /// here we will store the count of two groups in each connected component
        for(int i = 1 ; i<=n ; i++){
            if(vis[i] == 0){
                col[i] = 0;
                pair < int , int > tmp = dfs(i);
                if(tmp.first == -1){ /// that means we can't color the graph
                    com.clear();
                    com.push_back(tmp);
                    break;
                }
                com.push_back(tmp);
            }
        }
        if(com.size() == 1 && com[0].first == -1) cout<<"no\n";
        else{
            memset(dpp,-1,sizeof dpp);
            if(call(0,b)) cout<<"yes\n";
            else cout<<"no\n";
        }
    }
    return 0;
}
