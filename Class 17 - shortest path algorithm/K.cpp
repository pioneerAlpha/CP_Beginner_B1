#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)


using namespace std;

vector < int > vec[1005];

int dis[25][25];

string str[25];

int dxx[] = {0,0,-1,1};  /// direction array to traverse grid
int dyy[] = {1,-1,0,0};

void bfs(int row , int col)
{
    memset(dis,-1,sizeof dis);
    dis[row][col] = 0;
    queue < pair < int , int > > que;
    que.push({row,col});
    while(!que.empty()){
        pair < int , int > p = que.front();
        que.pop();
        row = p.first , col = p.second;
        for(int i = 0 ; i<4; i++){
            int x = row + dxx[i] , y = col + dyy[i];
            if(str[x][y] != '#' && str[x][y] != 'm' && dis[x][y] == -1){
                dis[x][y] = dis[row][col] + 1;
                que.push({x,y});
            }
        }
    }
}


int main()
{
    fastio;
    int caseno = 1 , t;
    cin>>t;
    while(t--){
        int n , m;
        cin>>n>>m;
        for(int i = 1 ; i<=n ; i++){
            cin>>str[i];
            str[i] += " #";
            for(int j = m ; j>0; j--) str[i][j] = str[i][j-1];
            str[i][0] = '#';  /// this way the 1st and the last character of each string is '#'
        }

        /// now I will fill row 0 and row (n+1) with '#'. this way the whole boundary is filled with '#'.

        str[0] = str[n+1] = "";
        for(int i = 0 ; i<=m+1; i++){
            str[0] += "#";
            str[n+1] += "#";
        }
        for(int i = 1 ; i<=n ; i++){
            for(int j = 1 ; j<=m ; j++) if(str[i][j] == 'h') bfs(i,j);
        }
        int ans = 0;
        for(int i = 1 ; i<=n ; i++){
            for(int j = 1 ; j<=m ; j++) if(str[i][j] >= 'a' && str[i][j] <= 'c') ans = max(ans , dis[i][j]);
        }
        cout<<"Case "<<caseno++<<": "<<ans<<endl;
    }
    return 0;
}
