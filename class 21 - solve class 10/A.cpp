#include<bits/stdc++.h>
#define ll long long
#define N ((int)2e5 + 5)
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

int lev[N];

vector < int > bfs(int src, int n)
{
    for(int i = 1 ; i<=n ; i++) lev[i] = -1;
    queue < int > que;
    vector < int > ans[2]; /// ans[0] stores the nodes which have even level
    /// ans[1] stores the nodes which have odd level
    que.push(src);
    lev[src] = 0;
    ans[0].push_back(src);
    while(!que.empty()){
        int a = que.front();
        que.pop();
        for(int b:vec[a]){
            if(lev[b] == -1){
                lev[b] = lev[a]+1;
                ans[lev[b]%2].push_back(b);
                que.push(b);
            }
        }
    }
    if(ans[0].size()<ans[1].size()) return ans[0];
    else return ans[1];
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        int n , m;
        cin>>n>>m;
        for(int i = 1 ; i<=n ; i++) vec[i].clear();
        while(m--){
            int a , b;
            cin>>a>>b;
            vec[b].push_back(a);
            vec[a].push_back(b);
        }

        vector < int > ans = bfs(1,n);
        cout<<ans.size()<<endl;
        for(int a:ans) cout<<a<<" ";
        cout<<endl;

    }

    return 0;
}
