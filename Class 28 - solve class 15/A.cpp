#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e6 + 5)
#define MOD ((int)1e8 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e10 + 7)
#define MAXP ((int)1e6 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int arr[22] , dpp[2+(1<<20)] , n ;

int call(int mask , int sum)
{
  
  if(dpp[mask] != -1) return dpp[mask];
  if(mask == 0) return dpp[mask] = 0;
  int ans = MAX;
  for(int i = 0 ; i<n; i++){
    if((mask&(1<<i)) == 0) continue;
    int tmp = mask , sumt = sum;
    tmp ^= 1<<i;
    sumt -= arr[i];
    int j = (i+1)%n;
    if((tmp&(1<<j)) != 0){
      tmp ^= 1<<j;
      sumt -= arr[j];
    }
    j = (j+1)%n;
    if((tmp&(1<<j)) != 0){
      tmp ^= 1<<j;
      sumt -= arr[j];
    }
    ans = min(ans , call(tmp,sumt) + sumt);
  }
  return dpp[mask] = ans;
}

int main()
{
  int sum = 0;
  cin>>n;
  for(int i = 0 ; i<n; i++){ 
   cin>>arr[i];
   sum += arr[i];
  }
  memset(dpp,-1,sizeof dpp);
  cout<<call((1<<n)-1 , sum)<<endl;
  return 0;
}
