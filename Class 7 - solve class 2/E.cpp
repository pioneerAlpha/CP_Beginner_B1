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
   // fastio;  /// lightoj sometimes gives runtime error verdict for using fastio;
    int t  , caseno = 1;
    cin>>t;
    while(t--){
        string str;
        int mod;
        cin>>str>>mod;
        mod = abs(mod);
        int ans = 0 , mul = 1;
        for(int i = str.length() - 1 ; i>=0 ; i--){
            if(str[i] == '-') break;
            int num = str[i] - '0';   /// i-th digit
            ans = (ans + 1LL*num*mul)%mod;
            mul = 10LL*mul%mod;
        }
        cout<<"Case "<<caseno++<<": ";
        if(ans == 0) cout<<"divisible\n";
        else cout<<"not divisible\n";
    }
    return 0;
}
