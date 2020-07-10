#include<bits/stdc++.h>
#define N ((int)(1e6 + 5))

using namespace std;

/// calculate phi for all numbers from 1 to 1e6

int phi[N];

int main()
{
    int n;
    cin>>n;
    for(int i = 1 ; i<=n ; i++) phi[i] = i;
    /// phi ( n ) = n*(p-1)/p * (q-1)/q * (r-1)/r  where n has prime factor p , q , r;
    vector < int > prime ; /// this vector stores all the prime number from 1 to 1e6
    for(int p:prime){
        for(int j = p ; j<=n ; j += p){
            phi[j] = phi[j]/p;
            phi[j] = phi[j]*(p-1);
        }
    }
    /// complexity : O(n*ln(n))
    return 0;
}
