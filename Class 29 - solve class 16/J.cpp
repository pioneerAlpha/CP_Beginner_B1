#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)
#define MOD ((int)1e8 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e10 + 7)
#define MAXP ((int)1e6 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

pair < int, int > arr[N];

int dpp[N] , val[N] , tmp[N];

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i = 1 ; i<=n ; i++)
        {
            cin>>arr[i].first;
        }
        for(int i = 1 ; i<=n ; i++)
        {
            cin>>arr[i].second;
        }
        sort(arr+1,arr+n+1);
        for(int i = 1 ; i<=n ; i++)
            tmp[i] = arr[i].second;
        for(int i = 1 ; i<=n ; i++)
            val[i] = MAX;
        val[0] = -MAX;
        for(int i = 1 ; i<=n ; i++)
        {
            int lef = 0, rig = n;
            while(lef < rig)
            {
                int mid = (lef + rig)>>1;
                if(val[mid] <= tmp[i])
                    lef = mid+1;
                else
                    rig = mid;
            }
            dpp[i] = lef;
            val[lef] = tmp[i];
        }
        int lis = 0;
        for(int i = 1 ; i<=n ; i++)
            lis = max(lis, dpp[i]);
        cout<<lis<<endl;
    }
    return 0;
}
