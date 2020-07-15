#include<bits/stdc++.h>
#define ll long long
#define N ((int)2e6 + 5)
#define MOD ((int)1e9 + 7)

using namespace std;

void selec(int arr[],int l,int r)
{
    for(int i = l ; i<=r; i++){
        for(int j = i + 1 ; j<=r ; j++){
            if(arr[i]>arr[j]) swap(arr[i],arr[j]);
        }
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
    selec(arr,1,n);  
    for(int i = 1 ; i<=n ; i++){
      cout<<arr[i]<<" ";
    }
    return 0;
}
