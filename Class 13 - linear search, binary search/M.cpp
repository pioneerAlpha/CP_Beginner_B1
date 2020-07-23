#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(2e3 + 5))
#define MAX ((int)(1e9 + 5))
#define MOD ((int)(7901 + 0))
#define thr (1e-10)


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

double peri(double len , double wid)
{
    double rad = sqrt(len*len + wid*wid);
    double theta = 2*asin(wid/rad);
    double ans = rad*theta + 2*len;
    return ans;
}


int main()
{
    //fastio;
    int t , caseno = 1;
    cout<<setprecision(15)<<fixed;
    cin>>t;
    while(t--){
        int a , b;
        char c;
        cin>>a>>c>>b;
        //cout<<a<<c<<b<<endl;
        double l = 0 , r = 400 , iter = 0;
        while(r-l > thr && iter <= 100){
            iter++;
            double mid = (r+l)/2;
            if(peri(mid,b*mid/a) - 400 > thr) r = mid;
            else l = mid;
        }
        cout<<"Case "<<caseno++<<": "<<l<<" "<<b*l/a<<endl;
    }
    return 0;
}
