#include<bits/stdc++.h>
#define f(a,b) for(int i = a ; i<=b ; i++)
#define N ((int)(1e6 + 5))
#define ll long long

using namespace std;

bool mark[N];

vector < int > prime;

void sieve(int n)
{

    for(int i = 1 ; i<=n ; i++)
        mark[i] = 0;

    for(int i = 3 ; i*i<=n ; i += 2)
    {
        if(mark[i] == 0)
        {
            for(int j = i*i ; j<=n ; j += i+i)
            {
                mark[j] = 1;
            }
        }
    }


//    cout<<"prime\n";

    prime.clear();

    prime.push_back(2);

//    cout<<"2 ";

    for(int i = 3 ; i<=n ; i += 2) /// n/2
    {
        if(mark[i] == 0)
        {
            prime.push_back(i);
//            cout<<i<<" ";
        }
    }
//    cout<<endl<<endl;

}



int main()
{
    /// prime factorization
    ll a;
    cin>>a ; /// a<=10^10 , root ( a ) = 10^5;

    sieve(1e5); /// 10^10

    /// a = 25 ; root(25) = 5

    vector < int > ans;

    for(int i = 0 ; i<prime.size() ; i++){
        if(a%prime[i] == 0){
            ans.push_back(prime[i]);

            while(a%prime[i] == 0){ /// a = 3*4
                a = a/prime[i];
            }

        }
    }

    if(a > 1){
        ans.push_back(a);
    }

    return 0;s



}
