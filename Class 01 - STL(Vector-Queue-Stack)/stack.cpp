#include<bits/stdc++.h>

using namespace std;

/// stack < data type > name;

/// to push an element : name.push(data);

/// to access the top element : name.top();

/// to remove the top element : name.pop();

/// to check size : name.size();

/// to check empty : name.empty();

int main()
{

    stack < int > stc;

    stc.push(5);
    stc.push(-5);
    stc.push(0);
//    stc.push(0);


    if(stc.empty() == 0) printf("%d\n",stc.top());

    if(stc.empty() == 0) stc.pop();

    if(stc.empty() == 0) printf("%d\n",stc.top());


    stc.pop();




}
