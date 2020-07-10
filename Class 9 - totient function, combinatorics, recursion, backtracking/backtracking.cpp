

#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector < string > vec;

string glob;

/// problem : given a string with distinct characters print all the permutations of the string

void backt(string str)
{
    if(str.size() == glob.size()){
        vec.push_back(str);
        return;
    }
    bool vis[30];
    memset(vis,0,sizeof vis);
    for(int i = 0 ; i<str.length() ; i++){
        int idx = str[i] - 'a';
        vis[idx] = 1;
    }
    for(int i = 0 ; i<glob.length() ; i++){
        int idx = glob[i] - 'a';
        if(vis[idx] == 0){
            string tmp = str;
            tmp += glob[i];
            backt(tmp);
        }
    }
}


int main()
{
    cin>>glob;
    backt("");
    for(string str : vec) cout<<str<<endl;
    return 0;
}
