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

int dis[2][105];

vector < int > vec[105];

void bfs(int src , int idx)
{
    dis[idx][src] = 0;
    queue < int > que;
    que.push(src);
    while(!que.empty())
    {
        int a = que.front();
        que.pop();
        for(int b:vec[a])
        {
            if(dis[idx][b] == -1)
            {
                dis[idx][b] = dis[idx][a] + 1;
                que.push(b);
            }
        }
    }
}

int main()
{
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;

        for(int i = 1 ; i<=n ; i++) vec[i].clear();

        while(m--){
            int a , b;
            cin>>a>>b;
            a++;
            b++;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        int src , des;
        cin>>src>>des;
        src++;
        des++;
        memset(dis,-1,sizeof dis);
        bfs(src,0);  /// dis[0][i] = distance of node i from src
        bfs(des,1);  /// dis[1][i] = distance of node i from des

        int ans = 0;

        for(int i = 1 ; i<=n ; i++){
            ans = max(ans , dis[0][i] + dis[1][i]);
        }
        cout<<"Case "<<caseno++<<": "<<ans<<endl;
    }
    return 0;
}
