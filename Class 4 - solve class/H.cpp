#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ll long long
#define endl "\n"

using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/
vector < int > vec;

void print()
{
    cout<<"TAK\n";
    for(int i = 0 ; i<vec.size() ; i++) cout<<vec[i]<<" ";
    cout<<endl;
}

int arr[505][505];

int main()
{
    fastio;
    int n , m , ans = 0;
    cin>>n>>m;
    for(int i = 1 ; i<=n ; i++){
        for(int j = 1 ; j<=m ; j++) cin>>arr[i][j];
        ans ^= arr[i][1];
        vec.push_back(1);
    }
    if(ans == 0){
        for(int i = 1 ; i<=n ; i++){
            for(int j = 2 ; j<=m ; j++){
                if(arr[i][j] != arr[i][1]){
                    vec[i-1] = j;
                    print();
                    return 0;
                }
            }
        }
        cout<<"NIE\n";
        return 0;
    }
    print();
    return 0;
}
