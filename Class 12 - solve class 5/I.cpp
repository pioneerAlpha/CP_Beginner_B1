#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(3e5 + 5))
#define MOD ((int)(1e9 + 7))


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/




int main()
{
    fastio;
    int n;
    cin>>n;
    if(n == 2) cout<<"-1\n";
    else{
        cout<<"6\n";
        ll val = 10;
        for(int i = 2 ; i<n ; i++){
            cout<<val<<"\n";
            val *= 2;
        }
        cout<<15<<endl;
    }
    return 0;
}
