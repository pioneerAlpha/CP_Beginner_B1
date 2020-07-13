#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(1e6 + 5))
#define MOD ((int)(1e9 + 7))


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

int phi[N];

///sieve of eratosthenes
int status[(N/32)+2];  /// mx = maximum prime
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
    sieve(N);
    for(int i = 1 ; i<N ; i++) phi[i] = i;
    for(int p:prime){
        for(int j = p ; j<N ; j += p) phi[j] = (p-1)*(phi[j]/p);
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<phi[n]<<endl;
    }
    return 0;
}
