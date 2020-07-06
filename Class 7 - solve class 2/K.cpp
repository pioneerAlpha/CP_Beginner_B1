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
    fastio;
    int t;
    t = 1;
    while(t--){
        string a , b;
        cin>>a>>b;
        if(a == b) cout<<a<<endl;
        else cout<<"1\n";
    }
    return 0;
}
