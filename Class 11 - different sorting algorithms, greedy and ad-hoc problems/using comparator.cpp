#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(3e5 + 5))
#define MOD ((int)(1e9 + 7))


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

struct info{
    int a, b;
    ll c;

};

info arr[100];

bool cmp(info ele1 , info ele2) /// c boro , a choto
{
    if(ele1.c > ele2.c || (ele1.c == ele2.c && ele1.a < ele2.a)) return 1;  /// 1 return korle age ele1 k rakhbe
    else return 0; /// 0 return korle age ele2 k rakhbe
}


int main()
{
    int n;
    cin>>n;
    for(int i = 1 ; i<=n ; i++) cin>>arr[i].a>>arr[i].b>>arr[i].c;

    sort(arr+1,arr+n+1,cmp);
    /// sort(name + starting index , name + ending index + 1)

    return 0;
}
