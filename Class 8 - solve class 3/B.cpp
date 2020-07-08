#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(47e3 + 5))
#define MOD ((int)(1e9 + 7))

using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

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

int power(int n, ll p)
{
    if(p == 0) return 1;
    int ans = power(n,p>>1);
    ans = 1LL*ans*ans%MOD;
    if(p&1) ans = 1LL*ans*n%MOD;
    return ans;
}

int fun(int r , ll n)
{
    int ans = power(r,n) - 1 + MOD;
    ans = 1LL*ans*power(r-1,MOD-2)%MOD;
    return ans;
}


int main()
{
   // fastio; sad sad
    sieve(N-5);
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int n , m , ans = 1;
        cin>>n>>m;
        for(int i = 0 ; i<prime.size() ; i++){
            int p = prime[i] ;
            ll cnt = 0;
            while(n % p == 0){
                cnt++;
                n /= p;
            }
            cnt *= m;
            if(cnt>0) ans = 1LL*ans*fun(p,cnt+1)%MOD;
        }
        if(n > 1) ans = 1LL*ans*fun(n,1LL+m)%MOD;
        cout<<"Case "<<caseno++<<": "<<ans<<endl;
    }
    return 0;
}
