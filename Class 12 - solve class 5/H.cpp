#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(1e5 + 5))
#define MAX ((int)(1e9 + 5))
#define MOD ((int)(7901 + 0))


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/



int main()
{
    int t;
    t = 1;
    while(t--){
        int arr[5][5];
        for(int i = 1 ; i<4 ; i++){
            for(int j = 1 ; j<4 ; j++) cin>>arr[i][j];
        }
        int b[5] , a[5];
        a[1] = 0;
        for(int i = 1 ; i<4 ; i++) b[i] = arr[1][i] - a[1];
        for(int i = 2 ; i<4 ; i++){
            a[i] = arr[i][1] - b[1];
            for(int j = 2 ; j<4 ; j++){
                if( a[i] + b[j] != arr[i][j] ){
                    cout<<"No\n";
                    return 0;
                }
            }
        }
        cout<<"Yes\n";
    }
    return 0;
}
