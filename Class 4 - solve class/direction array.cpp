#include<bits/stdc++.h>
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);

using namespace std;

dx[] = {0,0,1,-1};
dy[] = {1,-1,0,0};
/// direction:
/// 0: up
/// 1: down
/// 2: right
/// 3: left

int main()
{
    fastio;
    int x , y;
    cin>>x>>y;

    for(int i = 0 ; i<4 ; i++){
        int newx = x + dx[i] , newy = y + dy[i];
    }
    return 0;
}
