#include<bits/stdc++.h>
#define ll long long
#define N ((int)2e6 + 5)
#define MOD ((int)1e9 + 7)

using namespace std;

void insertion(int arr[],int l,int r)
{

///  1 2 3 3 4 3 5
///  1 2 3 4 5 6 7 (position)



    for(int i = l ; i<=r ; i++){
        int tmp = arr[i]; /// tmp = 3
        for(int j = i-1 ; j>0 ; j--){
            if(arr[j] > tmp){
                arr[j+1] = arr[j];
            }
            else{
                arr[j+1] = tmp;
                break;
            }
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
    insertion(arr,1,n);  
    for(int i = 1 ; i<=n ; i++){
      cout<<arr[i]<<" ";
    }
    return 0;
}
