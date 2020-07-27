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

int arr[N] , val[N] , cnt[N];

vector < int > vec[N/3];

bool cmp(int a , int b)
{
    return a>b;
}

int main()
{
    fastio;

    int n;
    cin>>n;
    for(int i = 1 ; i<=n ; i++) cin>>arr[i];

    sort(arr+1,arr+n+1);
    int tot = 0;
    arr[0] = 0;
    for(int i = 1 ; i<=n ; i++){
        if(arr[i] == arr[i-1]){
            cnt[tot]++;
        }
        else{
            tot++;
            cnt[tot] = 1;
            val[tot] = arr[i];
        }
    }

    int l = 0 , r = n;

    while(l<r){
        int mid = (l+r+1)/2;
        int taken = 0;
        for(int i = 1 ; i<=tot; i++) taken += min(mid,cnt[i]);
        if(taken >= mid*3) l = mid;
        else r = mid-1;
    }
    int cur = 1 , taken = 0;
    for(int i = 1 ; i<=tot && taken < 3*l ; i++){
        if(cnt[i] > l) cnt[i] = l;
        while(cnt[i] > 0 && taken < 3*l){
            cnt[i]--;
            vec[cur].push_back(val[i]);
            cur++;
            taken++;
            if(cur > l) cur = 1;
        }
    }
    cout<<l<<endl;
    for(int i = 1 ; i<=l ; i++){
        sort(vec[i].begin(),vec[i].end(),cmp);
        for(int a:vec[i]) cout<<a<<" ";
        cout<<endl;
    }

    return 0;
}
