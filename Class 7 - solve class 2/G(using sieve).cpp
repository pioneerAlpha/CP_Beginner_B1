#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(1e6 + 5))

using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

///sieve of eratosthenes
int status[(N/32)+2];
vector < int > prime;
bool Check(int n,int pos){
    return (n & (1<<pos));
}
int Set(int n,int pos){
    return (n | (1<<pos));
}
void sieve(int n){
     for(int i = 3; i*i <= n; i += 2){
		 if( Check(status[i>>5] , i&31) == 0 ){
	 		 for(int j = i*i; j <= n; j += (i<<1) ){
				 status[j>>5] = Set(status[j>>5] , j & 31);
	 		 }
		 }
	 }
	 prime.push_back(2);
	 for(int i = 3 ; i <= n;i += 2) if( Check(status[i>>5] , i&31) == 0 ) prime.push_back(i);
}


ll power(ll p , int cnt)
{
    ll ans = 1;
    while(cnt>0){
        cnt--;
        ans = ans*p;
    }
    return ans;
}

int main()
{
    fastio;
    int t;
    cin>>t;
    sieve(1e6);
    for(int tcc = 1 ; tcc<=t ; tcc++){
        ll a , b , L;
        cin>>a>>b>>L;
        ll lcm = a*b/__gcd(a,b);
        cout<<"Case "<<tcc<<": ";
        if(L%lcm != 0){
            cout<<"impossible\n";
        }
        else{
            vector < pair < ll , int > > arr1 , arr2;  /// arr1 for L , arr2 for lcm
            for(int i = 0 ; i<prime.size() ; i++){
                int p = prime[i];
                int cnt = 0;
                while(L%p == 0){
                    cnt++;
                    L /= p;
                }
                if(cnt > 0) arr1.push_back({p,cnt});

                cnt = 0;
                while(lcm % p == 0){
                    cnt++;
                    lcm /= p;
                }
                if(cnt > 0) arr2.push_back({p,cnt});

            }

            if( L > 0 ) arr1.push_back({L,1});
            if( lcm > 0 ) arr2.push_back({lcm,1});

            ll ans = 1;

            int idx1 = 0 , idx2 = 0; /// idx1 for arr1 , idx2 for arr2
            while(idx1<arr1.size() && idx2<arr2.size()){
                if(arr1[idx1] == arr2[idx2]){
                    /// do nothing
                    idx1++;
                    idx2++;
                }
                else if(arr1[idx1]<arr2[idx2]){
                    if(arr1[idx1].first == arr2[idx2].first && arr1[idx1].second < arr2[idx2].second) /// which is not possible
                    {
                        /// do nothing
                    }
                    else{ /// here arr1[idx1].first < arr2[idx2].first
                        ans = ans*power(arr1[idx1].first , arr1[idx1].second);
                        idx1++;
                    }
                }
                else{ /// here arr1[idx1]>arr2[idx2
                    if(arr1[idx1].first == arr2[idx2].first && arr1[idx1].second > arr2[idx2].second){
                        ans = ans*power(arr1[idx1].first , arr1[idx1].second);
                        idx1++;
                        idx2++;
                    }
                    else{  /// here arr1[idx1].first > arr2[idx2].first
                        idx2++;
                    }
                }
            }

            while(idx1<arr1.size()){
                ans = ans*power(arr1[idx1].first,arr1[idx1].second);
                idx1++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
