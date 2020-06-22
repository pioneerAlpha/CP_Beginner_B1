#include<bits/stdc++.h>

using namespace std;

map < pair < int , int > , int > mmm;

/// pair < data1 , data2 > name;

//pair < int , float > arr[100];

int main()
{

    int q;

//    map < int , int > m;
//
//    m[1] = 5;
//
//    printf("%d\n",m[1]);


    scanf("%d",&q);


    while(q--){

        pair < int , int > pp;
        scanf("%d %d",&pp.first,&pp.second);

        mmm[pp]++;

//        int ans;
//        if ( mmm[pp] == 1 ) ans = 1;
//        else{
//            ans = 0;
//            mmm[pp] = 1;
//        }

        printf("%d\n",mmm[pp]);


    }

    mmm.clear();

    return 0;

//    mmm[10000000000] = 4;
//
//    printf("%d\n",mmm[10000000000]);

}
