#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e3 + 5)
#define MOD ((int)1e9 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)


using namespace std;

int vis[45][45][25] , n , m;

int dxx[] = {0,0,1,-1};
int dyy[] = {1,-1,0,0};

string str[44];

void dfs(int row, int col , int tot)
{
    if(tot> 20 || vis[row][col][tot] == 1) return;
    vis[row][col][tot] = 1;
    for(int i = 0 ; i<4 ; i++){
        int a = row + dxx[i], b = col + dyy[i];
        if(min(a,b)<0 || a>=n || b>=m || str[a][b] == '#') continue;
        if(str[a][b] == 's') dfs(a,b,tot+1);
        else dfs(a,b,tot);
    }
}

int main()
{
    fastio;
    int atm;
    cin>>n>>m>>atm;
    for(int i = 0 ; i<n ; i++){
        cin>>str[i];
    }
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m; j++){
            if(str[i][j] == 'x') dfs(i,j,0);
        }
    }
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j < m ; j++){
            for(int k = 0; k<=atm ; k++){
                if(str[i][j] == '@' && vis[i][j][k] == 1){
                    if(k+k <= atm){
                        cout<<"SUCCESS\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
    return 0;
}
