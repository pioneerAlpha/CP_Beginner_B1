#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(1e7 + 5))
#define MOD ((int)(1e9 + 7))
#define MAX ((int)(1e9 + 7))

using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

int too_x[] = {2,2,-2,-2};
int too_y[] = {2,-2,2,-2};
int ene_x[] = {1,1,-1,-1};
int ene_y[] = {1,-1,1,-1};

string str[15];

int fun(string str[] , int curx, int cury)
{
    int ans = 0;
    for(int i = 0 ; i<4 ; i++){
        int a = curx+too_x[i], b = cury + too_y[i];
        if(min(a,b)<0 || max(a,b)>9) continue;
        if(str[a][b] == '#'){
            int c = curx + ene_x[i] , d = cury + ene_y[i];
            if(str[c][d] == 'B'){
                str[curx][cury] = '#';
                str[c][d] = '#';
                str[a][b] = 'W';
                ans = max(ans , fun(str,a,b) + 1);
                str[curx][cury] = 'W';
                str[c][d] = 'B';
                str[a][b] = '#';
            }
        }
    }
    return ans;
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        for(int i = 0 ; i<10 ; i++) cin>>str[i];
        int ans = 0;
        for(int i = 0 ; i<10 ; i++){
            for(int j = 0 ; j<10 ; j++){
                if(str[i][j] == 'W') ans = max(ans , fun(str,i,j));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
