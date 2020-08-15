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


using namespace std;

int dis[N], u[N], v[N], w[N];

vector < int > vec[N];

void bfs(int src , int n)
{
    for(int i = 1 ; i<=n ; i++) dis[i] = -1;
    dis[src] = 0;
    queue < int > que;
    que.push(src);
    while(!que.empty())
    {
        int a = que.front();
        que.pop();
        for(int b:vec[a])
        {
            if(dis[b] == -1)
            {
                dis[b] = dis[a] + 1;
                que.push(b);
            }
        }
    }
}

int main()
{
    fastio;
    freopen("path.in","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, src, L, k;
        cin>>n>>m>>src>>L>>k;

        for(int i = 1 ; i<=n ; i++) vec[i].clear();

        for(int i = 1 ; i<=m ; i++)
        {
            cin>>u[i]>>v[i]>>w[i];
            vec[u[i]].push_back(v[i]);
            vec[v[i]].push_back(u[i]);
        }
        bfs(src,n);
        int ans = 0;
        for(int i = 1 ; i<=m ; i++)
        {
            if(min(dis[u[i]], dis[v[i]]) < k)
                ans = max(ans, w[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
