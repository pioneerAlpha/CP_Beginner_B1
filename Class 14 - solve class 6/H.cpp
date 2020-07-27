#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)1e5 + 5)
#define MAX ((int)1e9 + 5)
#define MAXL ((ll)1e18 + 5)
#define MOD ((int)7901 + 0)
#define thr (1e-10)


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/


bool solve(int tim, string str)
{
    int n = str.length();
    int cur = -1;
    for(int i = 0 ; i<n ; i++){
        if(str[i] == 'P'){
            int lef = 0;
            for(int j = cur+1 ; j<i ; j++){
                if(str[j] == '*'){
                    lef = i-j;
                    break;
                }
            }
            /// it would give WA if you write like this : rig = max( tim - 2*lef , (tim - lef)/2 );
            int rig = tim - 2*lef;
            if(tim - lef >= 0) rig = max(rig , (tim - lef)/2);
            if(rig<0) return 0;
            cur = i + rig;
        }
    }
    for(int i = cur+1 ; i<n ; i++){
        if(str[i] == '*') return 0;
    }
    return 1;
}


int main()
{
    fastio;

    int n;
    string str;
    cin>>n>>str;
    int l = 0 , r = n+n;
    while(l<r){
        int mid = (l+r)/2;
        if(solve(mid,str)) r = mid;
        else l = mid+1;
    }
    cout<<l<<endl;
    return 0;
}
