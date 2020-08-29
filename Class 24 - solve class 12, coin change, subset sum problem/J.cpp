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

int k , dep[N] , path , par[N];

bool vis[N];

void cycle(int n , int p) /// printing the cycle from n to a
{
    cout<<"2\n";
    cout<<dep[n]-dep[p]+1<<endl;
    while(1){
        cout<<n<<" ";
        if(n == p) break;
        n = par[n];
    }
    exit(0); /// this will terminate the program
}

void dfs(int n)
{
    dep[n] = dep[par[n]]+1;
    vis[n] = 1;
    for(int a:vec[n]){
        if(vis[a] == 0){
            par[a] = n;
            dfs(a);
        }
        else if(a != par[n] && dep[n] >= dep[a]){  /// this is a back edge
            if(dep[n]-dep[a]+1 <= k){ /// length of the cycle = dep[n]-dep[a]+1
                cycle(n,a);
            }
            else path = n;  /// we got a cycle of length greater than k
        }
    }
}

int main()
{
    fastio;
    int n , m ;
    cin>>n>>m>>k;
    while(m--){
        int a, b;
        cin>>a>>b;
        vec[b].push_back(a);
        vec[a].push_back(b);
    }
    path = -1;
    par[1] = 0;
    dfs(1);
    int tot = (k+1)/2;
    cout<<"1\n";
    if(path != -1){
        while(tot>0){  /// starting form the node 'path' we will print
            /// the 1st , 3rd , 5th ... node
            cout<<path<<" ";
            tot--;
            path = par[path];
            path = par[path];
        }
    }
    else{ /// there is no cycle. so if we take all nodes of even depth
        /// or all node of odd depth, we will get the independent set
        vector < int > ans[2];
        for(int i = 1 ; i<=n ; i++){
            if(dep[i]%2 == 1) ans[1].push_back(i);
            else ans[0].push_back(i);
        }
        int cur = 0;
        if(ans[cur].size() < tot) cur = 1;
        for(int a:ans[cur]){
            if(tot == 0) break;
            tot--;
            cout<<a<<" ";
        }
    }
    return 0;
}
