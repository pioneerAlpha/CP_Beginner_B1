#include<bits/stdc++.h>

#define N ((int)(1e6 + 5))

using namespace std;

bool mark[N];

vector < int > prime;

void sieve(int n)
{

    for(int i = 3 ; i<=n ; i += 2)
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
//    bool a = 5;
//    cout<<a;
    while(1)
    {
        int n;
        cin>>n;
        sieve(n);
    }
    return 0;
}
