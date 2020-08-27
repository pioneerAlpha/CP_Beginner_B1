#include<bits/stdc++.h>

using namespace std;

/// priority_queue < data type > name ;

/// to access the top element : name.top();
/// to erase the top element : name.pop();


int main()
{

    priority_queue < int > pqq;

    int arr[] = {5 , 6 , 4 , 10 , 9 , -9 , -1};

   int n = 7;
    printf("max heap\n");
   for(int i = 0 ; i<n ; i++) pqq.push(arr[i]); /// max heap

    while(!pqq.empty()){

        printf("%d\n",pqq.top());
        pqq.pop();
    }

    printf("min heap\n");


    for(int i = 0 ; i<n ; i++) pqq.push(-arr[i]); /// min heap

    while(!pqq.empty()){

        printf("%d\n",-pqq.top());
        pqq.pop();
    }

    return 0;
}
