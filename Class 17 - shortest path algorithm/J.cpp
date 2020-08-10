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

int dis[1005];

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




void bfs(int src)
{
    memset(dis,-1,sizeof dis);
    dis[src] = 0;
    queue < int > que;
    que.push(src);
    while(!que.empty()){
        int a = que.front();
        que.pop();
        ///for(int b:vec[a]){
        ///
        ///}

        for(int i = 0 ; i<vec[a].size() ; i++){
            int b = vec[a][i];
            if(dis[b] == -1){
                dis[b] = dis[a] + 1;
                que.push(b);
            }
        }
    }
}


int main()
{
    sieve(1e3);
    for(int i = 4 ; i<=1000 ; i++){
        int a = i;
        for(int j = 0 ; j<prime.size() ; j++){
            int p = prime[j];
            if(p*p > a) break;
            if(a%p == 0){
                while(a%p == 0) a = a/p;

                if(i + p <= 1000){
                    vec[i].push_back(i + p);
                }
            }
        }
        if(a > 1 && a < i){
            if(i + a <= 1000) vec[i].push_back(i + a);
        }
    }
    fastio;
    int caseno = 1 , t;
    cin>>t;
    while(t--){
        int src , des;
        cin>>src>>des;
        bfs(src);
        cout<<"Case "<<caseno++<<": "<<dis[des]<<endl;
    }
    return 0;
}
