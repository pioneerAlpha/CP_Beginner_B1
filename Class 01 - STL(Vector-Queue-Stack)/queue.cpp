#include<bits/stdc++.h>

using namespace std;

/// queue < data type > name;

/// to push an element : name.push(data);

/// to access the top element : name.front();

/// to remove the top element : name.pop();

/// to check size : name.size();

/// to check empty : name.empty();

int main()
{

    queue < int > que;

    que.push(5);
//    que.push(-5);
//    que.push(0);
//    que.push(0);


    if(que.empty() == 0) printf("%d\n",que.front());

    if(que.empty() == 0) que.pop();

    if(que.empty() == 0) printf("%d\n",que.front());


    que.pop();




}
