#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e3 + 5)
#define MOD ((int)1e9 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)


using namespace std;

int dxx[] = {0,0,1,-1};
int dyy[] = {1,-1,0,0};

int key[30];

string mov , str[25];

bool vis[25][25] , chk[22][22];

int n , m;

bool dfs(int x , int y , int desx , int desy)
{
    if(min(x,y)<0 || x>=n || y>=m || chk[x][y] == 1 || str[x][y] == '0') return 0;
    chk[x][y] = 1;
    if(x == desx && y == desy) return 1;
    for(int i = 0 ; i<4; i++){
        int a = x + dxx[i] , b = y + dyy[i];
        if( dfs(a,b,desx,desy) == 1 ) return 1;
    }
    return 0;
}

queue < pair < int , int > > leaf;

int deg[25][25];

pair < string , pair < int , int > > fun()
{
    pair < int , int > pos = leaf.front();
    leaf.pop();
    int x = pos.first , y = pos.second;
    if(leaf.empty()){
        return {"",pos};
    }
    for(int i = 0 ; i<4 ; i++){
        int a = x + dxx[i], b = y + dyy[i];
        if(min(a,b)<0 || a>=n || b>=m || str[a][b] == '0' || vis[a][b] == 1) continue;
        deg[a][b]--;
        if(deg[a][b] < 2){
            leaf.push({a,b});
            vis[a][b] = 1;
        }
    }
    pair < string , pair < int , int > > ans = fun();
    string tmp = ans.first;
    for(int i = 0 ; i<tmp.length(); i++){
        int k = key[tmp[i]-'A'];
        x = x + dxx[k] , y = y + dyy[k];
        if(min(x,y) < 0 || x>=n || y>=m || str[x][y] == '0') x = x-dxx[k], y = y-dyy[k];
    }
    int xx = ans.second.first , yy = ans.second.second;
    while(x != xx || y != yy){
        memset(chk,0,sizeof chk);
        chk[x][y] = 1;
        for(int i = 0 ; i<4 ; i++){
            if(dfs(x+dxx[i],y+dyy[i],xx,yy) == 1){
                x = x + dxx[i], y = y + dyy[i] , xx = xx + dxx[i], yy = yy + dyy[i];
                if(min(xx,yy) < 0 || xx >= n || yy >= m || str[xx][yy] == '0') xx = xx-dxx[i] , yy = yy-dyy[i];
                tmp += mov[i];
                break;
            }
        }
    }
    return {tmp,{x,y}};
}

int main()
{
    fastio;
    key['U'-'A'] = 3;
    key['D'-'A'] = 2;
    key['L'-'A'] = 1;
    key['R'-'A'] = 0;
    mov = "RLDU";
    cin>>n>>m;
    for(int i = 0 ; i<n; i++){
        cin>>str[i];
    }
    for(int i = 0 ; i<n; i++){
        for(int j = 0 ; j<m; j++){
            if(str[i][j] == '1'){
                int cnt = 0;
                for(int k = 0 ; k<4; k++){
                    int x = i + dxx[k] , y = j + dyy[k];
                    if(min(x,y)<0 || x>=n || y>=m || str[x][y] == '0') continue;
                    cnt++;
                }
                deg[i][j] = cnt;
                if(cnt < 2){
                    leaf.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
    }
    string ans = fun().first;
    cout<<ans<<endl;
    return 0;
}
