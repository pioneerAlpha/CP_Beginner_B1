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
    int n , k;
    cin>>n>>k;
    priority_queue < int > pqq;
    for(int i = 0 ; n > 0 ; i++)
    {
        if((n&(1<<i)) != 0){ /// i'th bit on
            n -= (1<<i);
            pqq.push((1<<i));
        }
    }
    while(pqq.size() < k){
        int a = pqq.top();
        if((a&1) == 0){
            pqq.pop();
            pqq.push(a/2);
            pqq.push(a/2);
        }
        else break;
    }
    if(pqq.size() != k){
        cout<<"NO\n";
        return 0;
    }

    cout<<"YES\n";

    while(!pqq.empty()){
        int a = pqq.top();
        pqq.pop();
        cout<<a<<" ";
    }
    return 0;
}
