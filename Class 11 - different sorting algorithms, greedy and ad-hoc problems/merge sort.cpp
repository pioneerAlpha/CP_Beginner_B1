#include<bits/stdc++.h>
#define ll long long
#define N ((int)2e6 + 5)
#define MOD ((int)1e9 + 7)

using namespace std;

int arr[N];

void mergE(int arr[] , int l , int mid , int r) /// O (n)
{
    vector < int > lef , rig;
    for(int i = l ; i<=mid ; i++) lef.push_back(arr[i]);
    for(int i = mid + 1 ; i<=r ; i++) rig.push_back(arr[i]);

    int i = 0 , j = 0, cur = l; /// i => lef , j => rig , cur => arr
    while(i<lef.size() && j<rig.size()){
        if(lef[i] < rig[j]){
            arr[cur] = lef[i];
            i++;
        }
        else{
            arr[cur] = rig[j];
            j++;
        }
        cur++;
    }

    while(i<lef.size()){
        arr[cur] = lef[i];
        i++;
        cur++;
    }

    while(j<rig.size()){
        arr[cur] = rig[j];
        cur++;
        j++;
    }

}

void merge_sort(int arr[] , int l, int r)
{
    if(l<r){
        int mid = (l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        mergE(arr,l,mid,r);
    }
}


int main(){
    int n;
    cin>>n;
    for(int i = 1; i <=n ; i++){
      cin>>arr[i];
    }
    merge_sort(arr,1,n);  
    for(int i = 1 ; i<=n ; i++){
      cout<<arr[i]<<" ";
    }
    return 0;
}
