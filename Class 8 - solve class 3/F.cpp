#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(1e5 + 5))
#define MOD ((int)(1e9 + 7))

using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

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

vector < int > vec[N] , pre[N] ; /// vec[i] stores the  prime factors of i
                        /// pre[i] = stores the multiplier of which were "on" . here "i" must be a prime

bool onn[N] ; /// onn[i] = 1 if i-th collider is on

int main()
{
    fastio;
    int n , m;
    cin>>n>>m;
    sieve(n);
    for(int i = 0 ; i<prime.size() ; i++){
        int p = prime[i];
        for(int j = p ; j<=n ; j += p) vec[j].push_back(p);
    }
    while(m--){
        int num ;
        string str;
        cin>>str>>num;
        if(str[0] == '+'){
            if(onn[num]){
                cout<<"Already on\n";
                continue;
            }
            bool flag = 1; /// "num" collides with none
            for(int i = 0 ; i<vec[num].size() && flag == 1 ; i++){
                int p = vec[num][i];
                for(int j = pre[p].size() - 1 ; j>=0 ; j--){
                    int a = pre[p][j];
                    if(onn[a]){
                        flag = 0;  /// "num" collides with "a"
                        cout<<"Conflict with "<<a<<endl;
                        break;
                    }
                    else pre[p].erase(pre[p].end()-1);
                }
            }
            if(flag){
                onn[num] = 1;
                cout<<"Success\n";
                for(int i = 0 ; i<vec[num].size() ; i++){
                    int p = vec[num][i];
                    pre[p].push_back(num);
                }
            }
        }
        else{
            if(!onn[num]) cout<<"Already off\n";
            else{
                onn[num] = 0;
                cout<<"Success\n";
            }
        }
    }
    return 0;
}
