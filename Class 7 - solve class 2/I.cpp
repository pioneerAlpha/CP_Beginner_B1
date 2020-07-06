#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(1e5 + 5))

using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

int arr[N] , add[N] , sub[N];

int main()
{
    //fastio;
    int t;
    cin>>t;
    for(int tcc = 1 ; tcc<=t ; tcc++){
        int n , q;
        cin>>n>>q;
        ll sum = 0;
        for(int i = 0 ; i<n ; i++){
            cin>>arr[i];
            add[i] = n-i-1;
            sub[i] = i;
            sum += 1LL*arr[i]*(add[i] - sub[i]);  /// this is called "contribution technique" 
                                            /// for each element we just need to know how much it contributes to the sum, that is "add[i] - sub[i]" 
        }
        cout<<"Case "<<tcc<<":\n";
        while(q--){
            int typ;
            cin>>typ;
            if(typ) cout<<sum<<endl;
            else{
                int idx , val;
                cin>>idx>>val;
                sum -= 1LL*arr[idx]*(add[idx] - sub[idx]);
                arr[idx] = val;
                sum += 1LL*arr[idx]*(add[idx] - sub[idx]);
            }
        }
    }
    return 0;
}
