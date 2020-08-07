#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e3 + 5)
#define MOD ((int)1e9 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)


using namespace std;

int arr[105][105];

int dxx[] = {0,0,1,-1};
int dyy[] = {1,-1,0,0};

bool vis[105][105];

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        int n , m;
        cin>>n>>m;
        for(int i = 1 ; i<=n ; i++){
            for(int j = 1 ; j<=m ; j++){
                cin>>arr[i][j];
                vis[i][j] = 0;
            }
        }
        priority_queue < pair < int , pair < int , int > > > pqq;
        for(int i = 1 ; i<=n ; i++){
            pqq.push({-arr[i][1],{i,1}});
            vis[i][1] = 1;
            pqq.push({-arr[i][m],{i,m}});
            vis[i][m] = 1;
        }
        for(int j = 1 ; j<=m ; j++){
            pqq.push({-arr[1][j],{1,j}});
            vis[1][j] = 1;
            pqq.push({-arr[n][j],{n,j}});
            vis[n][j] = 1;
        }
        int ans = 0;
        while(!pqq.empty()){
            pair < int , pair < int , int > > p = pqq.top();
            pqq.pop();
            int x = p.second.first, y = p.second.second , hig = -p.first;
            for(int i = 0 ; i<4 ; i++){
                int a = x + dxx[i] , b = y + dyy[i];
                if(min(a,b) < 1 || a > n || b > m || vis[a][b] == 1) continue;
                vis[a][b] = 1;
                if(arr[a][b] < hig){
                    ans += hig - arr[a][b];
                    arr[a][b] = hig;
                }
                pqq.push({-arr[a][b],{a,b}});
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
