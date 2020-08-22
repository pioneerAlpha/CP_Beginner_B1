#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

vector < int > vec[N];

int dia[N] , dep[N];  /// dia[i] = diameter of subtree of node i
/// dep[i] = farthest leaf from node i in the subtree of node i

void dfs(int n , int par)
{
    dia[n] = 0;
    int mxx1 = 0, mxx2 = 0;
    for(int a:vec[n]){
        if(a != par){
            dfs(a,n);
            dia[n] = max(dia[n] , dia[a]);
            int val = dep[a] + 1;
            if(val > mxx2 && val <= mxx1) mxx2 = val;
            else if(val > mxx1){
                mxx2 = mxx1;
                mxx1 = val;
            }
        }
    }
    dia[n] = max( dia[n] , mxx1 + mxx2 );
    dep[n] = mxx1;

}

int main()
{
    fastio;
    int n;
    cin>>n;
    for(int i = 1 ; i<n ; i++){
        int a , b;
        cin>>a>>b;
        vec[b].push_back(a);
        vec[a].push_back(b);
    }
    int root , q;
    cin>>root>>q;
    dfs(root,0);
    while(q--){
        int node;
        cin>>node;
        cout<<dia[node]<<endl;
    }
    return 0;
}
