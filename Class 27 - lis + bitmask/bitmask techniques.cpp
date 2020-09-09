#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e4 + 5)
#define MOD ((int)1e8 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e10 + 7)
#define MAXP ((int)1e6 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;



int main()
{

    int n;
    cin>>n;
    for(int i = 0 ; i<n ; i++) cin>>arr[i];
    for(int mask = 0 ; mask < (1<<n) ; mask++){

        /// checking if j-th element exists in the sub set/mask
        for(int j = 0 ; j<n ; j++){
            if((mask&(1<<j)) != 0){
                cout<<"on\n";
            }
            else{
                cout<<"off\n";
            }
        }
        /// checking


        /// inserting j-th element in the subset
        /// turning j-th bit on
        for(int j = 0 ; j<n ; j++){
            int tmp = mask;
            tmp = tmp|(1<<j);
        }
        /// inserting


        /// turning j-th bit off
        /// excluding j-th element from the subset
        for(int j = 0 ; j<n ; j++){
            int tmp = mask;
            if((tmp&(1<<j)) != 0){
                tmp = tmp^(1<<j);
            }
        }
        /// excluding


        /// iterating over all possible sub mask
        for(int sub = 0 ; sub < (1<<n) ; sub++){
            if((sub|mask) == mask){
                cout<<"YES sub mask\n"
            }
            else cout<<"NO\n";
        }
        /// iterating (4^n)


        /// iterating over all possible sub mask (3^n)
        for(int sub = mask ;  ; sub = (sub-1)&mask){
            ///

            if(sub == 0) break;
        }
        /// iterating


    }
}
