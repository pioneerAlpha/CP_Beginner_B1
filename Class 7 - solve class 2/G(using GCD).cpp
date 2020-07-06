#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long

using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/




int main()
{
    fastio;   /// lightoj sometimes gives runtime error verdict for using fastio;
    int t;
    cin>>t;
    for(int tcc = 1 ; tcc<=t ; tcc++){
        ll a , b , l;
        cin>>a>>b>>l;
        ll lcm = a*b/__gcd(a,b);
        cout<<"Case "<<tcc<<": ";
        if(l%lcm != 0){
            cout<<"impossible\n";
        }
        else{
            l /= lcm;
            while(1){
                ll g = __gcd(lcm,l);
                l *= g;
                lcm /= g;
                if(g==1) break;
            }
            cout<<l<<endl;
        }
    }
    return 0;
}
