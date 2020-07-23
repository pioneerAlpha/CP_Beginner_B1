#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(2e5 + 5))
#define MAX ((int)(1e9 + 5))
#define MOD ((int)(7901 + 0))
#define thr (1e-8)


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

double okk(double d , double x , double y)
{
    double verx = sqrt(x*x-d*d) , very = sqrt(y*y-d*d);
    double c = verx*very/(verx + very);
    return c;
}

int main()
{
    //fastio;
    int t , caseno = 1;
    cout<<setprecision(10)<<fixed;
    cin>>t;
    while(t--){
        double x, y , c;
        cin>>x>>y>>c;
        double l = 0 , r = min(x,y);
        while(r - l > thr){
            double mid = (l+r)/2;
            if(okk(mid,x,y)-c > thr) l = mid;
            else r = mid;
        }
        cout<<"Case "<<caseno++<<": "<<l<<endl;
    }
    return 0;
}
