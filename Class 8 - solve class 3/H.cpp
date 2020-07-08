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

bool mark[N]; /// mark[i] = 1 if "i" is special prime

int cum[N] ; /// cum[i] stores number of special primes from 0 to i

bool zero(int n) /// returns 1 if n has a 0 digit in its decimal representation
{
    while(n != 0){
        if(n%10 == 0) return 1;
        n /= 10;
    }
    return 0;
}

int main()
{
    fastio;
    sieve(1e6);
    for(int i = 0 ; i<prime.size(); i++){
        int p = prime[i];
        if(zero(p)==0){
//            if(p<3) cout<<p<<endl;
            int num = 0 , mul = 1 , tmp = p;
            while(tmp/10 != 0){
                num += mul*(tmp%10);
                mul *= 10;
                tmp /= 10;
            }
            if(num == 0 || mark[num] == 1) mark[p] = 1;
        }
    }
    cum[0] = mark[0];
    for(int i = 1 ; i<=1e6 ; i++) cum[i] = cum[i-1] + mark[i];
//    cout<<mark[0]<<" "<<mark[1]<<" "<<mark[2]<<endl;
//    cout<<cum[0]<<" "<<cum[1]<<" "<<cum[2]<<endl;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<cum[n]<<endl;
    }
    return 0;
}
