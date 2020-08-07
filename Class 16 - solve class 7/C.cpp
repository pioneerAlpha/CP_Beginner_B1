#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)
#define MOD ((int)1e9 + 7)
#define MAXP ((int)2e6 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)


using namespace std;

///sieve of eratosthenes
int status[(MAXP/32)+2];  /// MAXP = maximum prime
vector < int > prime;
bool Check(int n,int pos){
    return (bool)(n & (1<<pos));
}
int Set(int n,int pos){
    return (n | (1<<pos));
}
void sieve(int n){
     for(int i = 3; i*i <= n; i += 2){
		 if( Check(status[i>>5],i&31)==0){
	 		 for(int j = i*i; j <= n; j += (i<<1) ){
				 status[j>>5]=Set(status[j>>5],j & 31);
	 		 }
		 }
	 }
	 prime.push_back(2);
	 for(int i=3;i<=n;i+=2) if( Check(status[i>>5],i&31)==0) prime.push_back(i);
}

int cnt;

bool vis[N];

vector < int > vec[N];

void dfs(int n)
{
    if(vis[n] == 1) return;
    cnt++;
    vis[n] = 1;
    for(int a:vec[n]){
        dfs(a);
    }
}

int main()
{
    sieve(2e6);
//    cout<<prime.size()<<endl;
    fastio;
    int t;
    cin>>t;
    while(t--){
        memset(vis,0,sizeof vis);
        int n , m;
        cin>>n>>m;
        for(int i = 1 ; i<=n ; i++){
            vec[i].clear();
        }
        while(m--){
            int a , b;
            cin>>a>>b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        int ans = 0;
        for(int i = 1 ; i<=n ; i++){
            cnt = 0;
            dfs(i);
            ans = max(ans,cnt);
        }
        ans = prime[ans-1];
        if(ans == 2) ans = -1;
        cout<<ans<<endl;
    }
    return 0;
}
