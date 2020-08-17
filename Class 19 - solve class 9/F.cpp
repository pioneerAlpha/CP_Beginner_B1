#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e4 + 5)
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

int dis[N] , par[N];

bool mark[11];

void bfs(int src)
{
    memset(dis,-1,sizeof dis);
    dis[src] = 0;
    par[src] = -1;
    queue < int > que;
    que.push(src);
    while(!que.empty())
    {
        int a = que.front();
        que.pop();
        for(int b:vec[a]){
            if(dis[b] == -1){
                dis[b] = dis[a]+1;
                que.push(b);
                par[b] = a;
            }
        }
    }
}

int main()
{
    //fastio;
    int n , m , caseno = 1;
    while(scanf("%d %d",&n,&m) != EOF){
        memset(mark,0,sizeof mark);
        while(m--){
            int a;
            cin>>a;
            mark[a] = 1;
        }
        for(int mod = 1 ; mod<n; mod++) vec[mod].clear();
        for(int mod = 1 ; mod<n; mod++){
            for(int i = 0 ; i<10 ; i++){
                if(mark[i] == 0){
                    int new_mod = (mod*10 + i)%n;
                    vec[mod].push_back(new_mod);
                }
            }
        }
        int ans = MAX, src = -1;
        for(int i = 1 ; i<10 ; i++){
            if(mark[i] == 0){
                bfs(i%n);
                if(dis[0] != -1 && dis[0] < ans){
                    ans = dis[0];
                    src = i;
                }
            }
        }

        cout<<"Case "<<caseno++<<": ";

        if(src == -1) cout<<"-1\n";
        else{
            bfs(src%n);
            string ans;
            int cur = 0;
             /// we finish at 0. from 0 we will go to the parent of 0. let the parent be a.
             /// we can determine which digit was padded at the end to go to 0 from a.
             /// that will be the last digit of the answer
             /// this process will continue until we reach the source
            /// parent of the source is -1
            while(par[cur] != -1){
                int a = par[cur];
                for(int i = 0 ; i<10 ; i++){
                    if(mark[i] == 0){
                        if((a*10 + i)%n == cur){
                            ans += '0'+i;
                            break;
                        }
                    }
                }
                cur = a;
            }
            /// now we add src to our answer. it was the first digit we started our bfs from
            ans += src + '0';

            reverse(ans.begin(),ans.end()); /// reverses the whole string
            cout<<ans<<endl;
        }

    }
    return 0;
}
