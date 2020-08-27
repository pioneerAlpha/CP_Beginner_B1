#include<bits/stdc++.h>

using namespace std;


/// set < data type > name;
/// to declare an iterator : set < data type > :: iterator name;
/// to insert an element : name.insert();

/// to erase : name.erase(value);

/// to clear all elements : name.clear();

int main()
{
    set < int > sss;
    set < int > :: iterator it;
    int arr[] = {5 , 6 , -6 , 3 , 4 , 10 , -1 , 6};
    int n = 8;
    for(int i = 0 ; i<n ; i++ ) sss.insert(arr[i]);

    for(it = sss.begin() ; it != sss.end() ; it++){

        printf("%d\n",*it);

    }

   it = sss.begin();

    it++;

    sss.erase(it);

    printf("after erasing\n");

    for(it = sss.begin() ; it != sss.end() ; it++){

        printf("%d\n",*it);

    }



    return 0;
}
