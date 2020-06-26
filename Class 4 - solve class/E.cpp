#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ll long long
#define endl "\n"

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
    int cnt = 0;
    for(int i = 0 ; n > 0 ; i++){
        if((n&(1<<i)) != 0){ /// i'th bit on
            n -= (1<<i);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
