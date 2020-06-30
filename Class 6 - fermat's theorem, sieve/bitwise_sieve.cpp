#include<bits/stdc++.h>

#define N ((int)(1e8 + 5))

using namespace std;

int mark[N/32];

vector < int > prime;

void sieve(int n)
{

    for(int i = 0 ; i<=n/32 ; i++)
        mark[i] = 0;

    for(int i = 3 ; i*i<=n ; i += 2)
    {
        int idx = i>>5 , pos = i&31;
        if(( mark[idx]&(1<<pos) ) == 0)
        {
            for(int j = i*i ; j<=n ; j += i<<1)
            {
                idx = j>>5 , pos = j&31;
                mark[idx] = mark[idx] | (1<<pos);
            }
        }
    }


//    cout<<"prime\n";

    prime.clear();

    prime.push_back(2);

//    cout<<"2 ";

    for(int i = 3 ; i<=n ; i += 2) /// n/2
    {
        int idx = i>>5 , pos = i&31;
        if( (mark[idx]&(1<<pos)) == 0)
        {
            prime.push_back(i);
//            cout<<i<<" ";
        }
    }
//    cout<<endl<<endl;

}

int main()
{

    while(1)
    {
        int n;
        cin>>n;
        sieve(n);
    }
    return 0;
}
