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

int dis[1005][1005];

bool vis[1005][1005];

string str[1005] , ans , dir;

int dxx[] = {1,0,0,-1};
int dyy[] = {0,-1,1,0};

void dfs(int row , int col , int rem)
{
    if(rem == 0) return;
    for(int i = 0 ; i<4 ; i++){
        int x = row + dxx[i] , y = col + dyy[i];
        if(dis[x][y] != -1 && dis[x][y] <= rem-1){
            ans += dir[i];
            dfs(x,y,rem-1);
            return;
        }
    }
}

void bfs(int row , int col)
{
    memset(dis,-1,sizeof dis);
    dis[row][col] = 0;
    queue < pair < int , int > > que;
    que.push({row,col});
    while(!que.empty())
    {
        pair < int , int > p = que.front();
        row = p.first , col = p.second;
        que.pop();
        for(int i = 0 ; i<4 ; i++)
        {
            int x = row + dxx[i] , y = col + dyy[i];
            if(dis[x][y] == -1 && str[x][y] != '*')
            {
                dis[x][y] = dis[row][col] + 1;
                que.push({x,y});
            }
        }
    }
}

int main()
{
    dir = "DLRU";
    fastio;
    int n , m , k;
    cin>>n>>m>>k;
    for(int i = 1 ; i<=n ; i++){
        cin>>str[i];

        /// from here i am trying to create a boundary of '*'; the whole grid will be bounded by '*'

        str[i] += "**";
        for(int j = m ; j>0; j--) str[i][j] = str[i][j-1];
        str[i][0] = '*';
    }
    str[0] = str[n+1] = "";
    for(int j = 0 ; j<=m+1 ; j++){
        str[0] += "*";
        str[n+1] += "*";
    }

    /// boundary has been created

    for(int i = 1; i<=n ; i++){
        for(int j = 1 ; j<=m ; j++){
            if(str[i][j] == 'X'){
                bfs(i,j);
                dfs(i,j,k);
                if(ans.size() < k) ans = "IMPOSSIBLE";
                cout<<ans<<endl;
                return 0;
            }
        }
    }
    return 0;
}
