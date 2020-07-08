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

int fun(int n)  /// increases n to the nearest power of 2
{
    while( (n&(n-1)) != 0 ){
        n++;
    }
    return n;
}

int main()
{
    fastio;
    int n;
    cin>>n;
    sieve(n);
    vector < int > vec;

    int mxx = 0 , opp = 0 , ans = 1;

    for(int i = 0 ; i<prime.size(); i++){
        int p = prime[i];
        int cnt = 0;
        while(n%p == 0){
            n /= p;
            cnt++;
        }
        if(cnt > 0){
            vec.push_back(cnt);
            ans *= p;
        }
    }

    for(int i = 0 ; i<vec.size() ; i++){
        mxx = max(mxx,fun(vec[i]));
    }
    for(int i = 0 ; i<vec.size() ; i++){
        if(mxx>vec[i]) opp = 1;
    }

    while(mxx>1){
        opp++;
        mxx /= 2;
    }

    cout<<ans<<" "<<opp<<endl;

    return 0;
}
