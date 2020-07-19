#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(3e5 + 5))
#define MAX ((int)(1e9 + 5))
#define MOD ((int)(1e9 + 7))


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

int arr[2005] , brr[2005];

int main()
{
    int n , k;
    cin>>k>>n;
    for(int i = 1 ; i<=k ; i++){
        cin>>arr[i];
        arr[i] += arr[i-1];
    }
    sort(arr+1,arr+k+1);
    for(int i = 1 ; i<=n ; i++) cin>>brr[i];
    sort(brr+1,brr+n+1);
    vector < int > vec;
    for(int i = 1 ; i<=k ; i++){
        int val = arr[i] - brr[1];
        map < int , bool > mmm;
        for(int j = i+1 ; j<=k ; j++) mmm[arr[j]-arr[i]] = 1;
        vec.push_back(val);
        for(int j = 2 ; j<=n ; j++){
            if(mmm[brr[j]-brr[1]] == 0){
                vec.erase(vec.end() - 1);
                break;
            }
        }
    }
    sort(vec.begin(),vec.end());
    int pre = -MAX , ans = 0;
    for(int a:vec){
        if( a != pre ) ans++;
        pre = a;
    }
    cout<<ans<<endl;
    return 0;
}
