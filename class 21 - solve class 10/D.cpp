#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

bool vis[N] , col[N];

vector < pair < int , int > > vec[N];
vector < int > glob[2];

pair < int , int > dfs(int nod , int val)
{
    vis[nod] = 1;
    col[nod] = val;
    pair < int , int > ans = {0,0};
    if(val == 0) ans.first++;
    else ans.second++;


    glob[val].push_back(nod);

    for(auto p:vec[nod]){
        int a = p.first, tmp = p.second^val;
        if(vis[a] == 0){
            pair < int , int > sum = dfs(a,tmp);
            if(sum.first == -1) return {-1,-1};
            ans.first += sum.first;
            ans.second += sum.second;
        }
        else if(tmp != col[a]) return {-1,-1};
    }
    return ans;
}

vector < int > fun(int n)
{
    vector < int > ans;
    memset(vis,0,sizeof vis);
    for(int i = 1 ; i<=n ; i++){
        if(vis[i] == 0){
            glob[0].clear();
            glob[1].clear();
            pair < int , int > tmp = dfs(i,0);
            if(tmp.first == -1){
                ans.clear();
                ans.push_back(-1);
                break;
            }
            int cur = 0;
            if(tmp.second < tmp.first) cur = 1;
            for(int a:glob[cur]) ans.push_back(a);
        }
    }
    return ans;
}



int main()
{
//    freopen("tour.in","r",stdin);
//    freopen("tour.out","w",stdout);
    fastio;
    int n , m;
    cin>>n>>m;
    while(m--){
        int a , b;
        char c;
        cin>>a>>b>>c;
//        cout<<a<<b<<c<<endl;
        if(c == 'R') c = 'A';
        vec[a].push_back({b,c-'A'});   /// for color 'A' edge type is set 0
        vec[b].push_back({a,c-'A'});   /// for color 'B' edge type is set 1
    }

    vector < int > ans[2];

    ans[0] = fun(n);

    /// now we will change the edge type and run the algorithm again
    for(int i = 1; i<=n ; i++){
        for(int j = 0 ; j<vec[i].size() ; j++) vec[i][j].second = !vec[i][j].second;

    }

    ans[1] = fun(n);

    if(min ( ans[0].size() , ans[1].size() ) == 0) cout<<"0\n";
    else if(ans[0][0] == -1 && ans[1][0] == -1) cout<<"-1\n";
    else{
        int cur = 0;
        if(ans[0][0] == -1 || (ans[1][0] != -1 && ans[1].size() < ans[0].size())) cur = 1;
        cout<<ans[cur].size()<<endl;
        for(int a:ans[cur]) cout<<a<<" ";
        cout<<endl;
    }


    return 0;
}
