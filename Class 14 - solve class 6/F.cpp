#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)2e5 + 5)
#define MAX ((int)1e9 + 5)
#define MAXL ((ll)1e18 + 5)
#define MOD ((int)7901 + 0)
#define thr (1e-10)


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

int arr[N];


int my_sqrt(int val)
{
    int l = 0 , r = 1e5;
    while(l<r){
        int mid = (l+r)/2;
        if(1LL*mid*mid<val) l = mid+1;
        else r = mid;
    }
    return l;
}

bool cmp(int a, int b)
{
    return a>b;
}

int main()
{
    fastio;
    int n , cnt = 0;
    cin>>n;
    vector < int > vec;
    for(int i = 1 ; i<=n ; i++){
        cin>>arr[i];
        int tmp = my_sqrt(arr[i]);
        if(tmp*tmp == arr[i]){
            cnt++;
            vec.push_back(arr[i]);
        }
    }
    sort(vec.begin(),vec.end(),cmp);
    ll ans = 0;
    if(cnt > n/2){
        for(int a:vec){
            if(a == 0) ans += 2;
            else ans++;

            cnt--;
            if(cnt == n/2) break;
        }
    }
    else{
        int rem = n - cnt - n/2;
        vec.clear();
        for(int i = 1 ; i<=n ; i++){
            int tmp = my_sqrt(arr[i]);
            if(tmp*tmp > arr[i]){
                int val = tmp*tmp , val1 = (tmp-1)*(tmp-1);
                vec.push_back(min(val-arr[i],arr[i]-val1));
            }
        }
        sort(vec.begin(),vec.end());
        for(int a:vec){
            if(rem == 0) break;
            ans += a;
            rem--;
        }
    }
    cout<<ans<<endl;

    return 0;
}
