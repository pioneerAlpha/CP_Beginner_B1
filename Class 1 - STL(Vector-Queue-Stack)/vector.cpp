#include<bits/stdc++.h>

using namespace std;

int arr[100];

/// arr[ 0 ] , arr[ 1 ] , arr[99]


vector < int > vec;

/// vector < data type > name;

/// to check size : name.size();

/// to push an element : name.push_back(element);

/// to erase an element : name.erase(name.begin() + index of the element);
/// to erase several elements : name.erase(name.begin() + index of the 1st element , name.begin() + index of the last element + 1 );

/// to erase all elements : name.clear();

int main()
{
    int n = vec.size();
    printf("%d\n",n);
    vec.push_back(5);
    n = vec.size();
    printf("%d\n",n);

    for(int i = 1 ; i<=10 ; i++) vec.push_back(i);

    printf("%d\n",vec.size());

    printf("1st element : %d\n",vec[0]);

    vec[0] = -1;

    printf("1st element : %d\n",vec[0]);

    /// printing all elements
    printf("all elements :\n");
    for(int i = 0 ; i<vec.size() ; i++){ /// iterating over elements
        printf("%d ",vec[i]);
    }

    printf("\n");

    /// erase elements from index 2 to 5
    vec.erase(vec.begin() + 2 , vec.begin() + 6);
    /// erase elements from index 2 to 2
    vec.erase(vec.begin() + 2 , vec.begin() + 3);


    printf("all elements :\n");

    for(int i = 0 ; i<vec.size() ; i++){
        int a = vec[i];
        printf("%d ",a);
    }

    printf("\n");
    printf("size : %d\n",vec.size());
    return 0;

}
