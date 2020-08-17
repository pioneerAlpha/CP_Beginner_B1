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

int dis[505][505];


int dxx[] = {1,0,0,-1};
int dyy[] = {0,-1,1,0};

string str[505];

void bfs(int row , int col, int n , int m)
{
    memset(dis,-1,sizeof dis);
    dis[row][col] = 0;
    queue < pair < int , int > > que;
    que.push({row,col});
    while(!que.empty())
    {
        pair < int , int > p = que.front();
        row = p.first , col = p.second;
        int val = str[row][col] - '0';
        que.pop();
        for(int i = 0 ; i<4 ; i++)
        {
            int x = row + dxx[i]*val , y = col + dyy[i]*val;
            if(min(x,y) >= 0 && x < n && y < m && dis[x][y] == -1)
            {
                dis[x][y] = dis[row][col] + 1;
                que.push({x,y});
            }
        }
    }
}

int main()
{
    fastio;
    int n , m ;
    cin>>n>>m;
    for(int i = 0 ; i<n ; i++){
        cin>>str[i];
    }

    bfs(0,0,n,m);
    cout<<dis[n-1][m-1]<<endl;
    return 0;
}
