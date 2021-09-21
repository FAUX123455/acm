#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<deque>
#define ll long long
using namespace std;
int n,m;
ll a[200010];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
    sort(a+1,a+1+n);
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        ll x,y;cin>>x>>y;
        if(a[n]<=x)
        {
            ll ans=x-a[n];
            if(sum-a[n]<y)ans+=y-(sum-a[n]);
            cout<<ans<<"\n";
            continue;
        }
        int l=1,r=n;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(a[mid]>=x)r=mid;
            else l=mid+1;
        }
        if(sum-a[l]>=y){cout<<"0\n";continue;}
        ll ans=y-(sum-a[l]);
        if(a[l]==x){cout<<ans<<"\n";continue;}
        if(l!=1)
        {
            ll s=x-a[l-1];
            if(sum-a[l-1]<y)s+=y-(sum-a[l-1]);
            ans=min(ans,s);
        }
        cout<<ans<<"\n";
    }
    return 0;
}