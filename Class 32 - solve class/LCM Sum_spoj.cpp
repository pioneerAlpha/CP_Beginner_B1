#include<bits/stdc++.h>
#define N ((int)1e6 + 5)
#define MOD ((int)998244353 + 0)
#define ll long long
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAX ((int)1e6 + 5)
#define endl "\n"

using namespace std;

int phi[N];

ll ans[N];


///sieve of eratosthenes
int status[(N/32)+2];
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



int main()
{
    fastio;
    sieve(N-1);
    for(int i = 1 ; i<N ; i++) phi[i] = i;
    for(int p:prime){
        for(int j = p ; j<N ; j += p){
            phi[j] = phi[j]/p;
            phi[j] = phi[j]*(p-1);
        }
    }
    /// using vector to store the divisors gives TLE. too many divisors
    for(int i = 2 ; i<N ; i++){
        for(int j = i ; j<N ; j += i){
            ans[j] += 1LL*i*phi[i];
        }
    }
    for(int i = 1 ; i<N ; i++) ans[i] = (ans[i]*i + i*2)/2;
//    return 0;

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}
