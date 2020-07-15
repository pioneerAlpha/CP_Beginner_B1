#include<bits/stdc++.h>
#define ll long long
#define N ((int)2e6 + 5)
#define MOD ((int)1e9 + 7)

using namespace std;

void bubble(int arr[],int l,int r)
{

    /// 1 2 2 6 5
    /// 1 2 2 5 6

    while(1){
        bool flag = 1;  /// no swap
        for(int i = l ; i<r ; i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
                flag = 0;
            }
        }
        if(flag == 1) break;
    }

    /// complexity : O(n*n)
}

int arr[100];

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <=n ; i++){
      cin>>arr[i];
    }
    bubble(arr,1,n);  
    for(int i = 1 ; i<=n ; i++){
      cout<<arr[i]<<" ";
    }
    return 0;
}
