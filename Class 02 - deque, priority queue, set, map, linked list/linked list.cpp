#include<bits/stdc++.h>

using namespace std;

int lef[1005] , rig[1005];

int main()
{
    int n ;
    scanf("%d",&n);

    for(int i = 1 ; i<=n; i++){
        scanf("%d %d",&lef[i],&rig[i]);
    }

    int q;
    scanf("%d",&q);

    /// update1: 1 id1 id2 : chain break
    /// update2: 2 id1 id2
    /// length count: 3 id

    while(q--){
        int typ;
        scanf("%d",&typ);
        if(typ == 1){
            int id1 , id2;
            scanf("%d %d",&id1,&id2);
            rig[id1] = -1;
            lef[id2] = -1;
        }
        else if(typ == 2){
            int id1 , id2;
            scanf("%d %d",&id1,&id2);
            rig[id1] = id2;
            lef[id2] = id1;
        }
        else{
            int idx;
            scanf("%d",&idx);
            int cnt = 1;
            int a = lef[idx];
            while(a != -1){
                cnt++;
                a = lef[a];
            }

            a = rig[idx];
            while(a != -1){
                cnt++;
                a = rig[a];
            }

            printf("%d\n",cnt);

        }
    }

    return 0;

}
