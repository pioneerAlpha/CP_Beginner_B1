#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ll long long
#define endl "\n"
#define N ((int)(1e6 + 5))

using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/
vector < int > div1[N];

int main()
{
    int n;
    
    /// factorizing n in root(n) time complexity  
    
    cin>>n; /// n<=10^9
    vector < int > div;
    for(int i = 1 ; i*i<=n ; i++){
        if(n%i == 0){
            div.push_back(i);
            if(i != n/i) div.push_back(n/i);
        }
    }
    
    
    /// factorizing each number from 1 to n in n*ln(n) time complexity

    /// n = 10^6
    /// root(n) = 10^3
    /// 1 to n =>n*root(n) = 10^9
    
    cin>>n;

    for(int i = 1 ; i<=n ; i++){
        for(int j = i ; j<=n ; j += i){
            div1[j].push_back(i);
        }
    }
    
    return 0;


}
