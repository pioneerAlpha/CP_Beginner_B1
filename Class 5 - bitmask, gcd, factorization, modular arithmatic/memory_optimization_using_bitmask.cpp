#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ll long long
#define endl "\n"
#define MAX ((int)(1e9 + 7))

using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

int arr[MAX>>5];

int main()
{
//    fastio;
    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        int idx = num>>5 , pos = num&31; /// idx = num/32 , pos = num%32
        if( arr[idx]&(1<<pos) ){
            cout<<"1\n";
        }
        else{
            cout<<"0\n";
            arr[idx] = arr[idx]|(1<<pos);
            /// 1<<2 = 100
            /// arr[idx] = arr[idx] | (100)
        }
    }
    return 0;
}
