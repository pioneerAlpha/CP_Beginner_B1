#include<bits/stdc++.h>

using namespace std;

/// declare : deque < data type > name;

/// to insert an element from left end : name.push_front(value);;
/// to insert an element from right end : name.push_back(value);;

/// to access :name.front() and name.back();

int main()
{
    deque < int > dq;

    dq.push_front(5);

    dq.push_back(-5);
    dq.push_back(0);
    dq.push_front(1);

    printf("%d\n",dq.front());
    printf("%d\n",dq.back());

    dq.pop_back();

    printf("%d\n",dq.front());
    printf("%d\n",dq.back());

    dq.pop_front();

    printf("%d\n",dq.front());
    printf("%d\n",dq.back());

}
