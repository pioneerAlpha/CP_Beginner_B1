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
    int t;
    cin>>t;
    while(t--){
        string x , y;
        cin>>x>>y;
        int k = 0;
        for(int i = x.length(), j = y.length() ; i>=0 && j>=0 ; i-- , j--){
            if(x[i] == '1' && y[j] == '1') break;
            else if(x[i] == '0' && y[j] == '1'){
                k++;
                j++;
            }
        }
        cout<<k<<endl;
    }
    return 0;
}
