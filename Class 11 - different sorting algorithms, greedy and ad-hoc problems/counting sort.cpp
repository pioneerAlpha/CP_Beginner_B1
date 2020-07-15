#include<bits/stdc++.h>
#define ll long long
#define N ((int)2e6 + 5)
#define MOD ((int)1e9 + 7)

using namespace std;

int arr[N] , cnt[N];

void counting(int arr[]  , int l , int r)
{
    memset(cnt,0,sizeof cnt);
    for(int i = l ; i<=r ; i++){
        cnt[arr[i]]++;
    }

    /// 1 2 1

    ///cnt[1] = 2
    ///cnt[2] = 1



    int cur = l;

    for(int i = 0 ; i<N; i++){
        while(cnt[i]>0){
            arr[cur] = i;
            cur++;
            cnt[i]--;
        }
    }

    /// 1 1 2

}

int main()
{
    int n;
    cin>>n;
    for(int i = 1 ; i<=n ; i++) cin>>arr[i];

    counting(arr,1,n);
    
    for(int i = 1 ; i<=n ; i++) cout<<arr[i]<<" ";
    return 0;
}
