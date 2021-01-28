#include<bits/stdc++.h>
using namespace std;
long long a[1000000],b[1000000],c[1000000],d[1000000],n,m,k,x,s,i;
int main(){
cin>>n>>m>>k>>x>>s;
for(int i=0;i<m;i++)cin>>a[i];
for(int i=0;i<m;i++)cin>>b[i];
for(int i=0;i<k;i++)cin>>c[i];
for(int i=0;i<k;i++)cin>>d[i];
long long ans=(n-c[upper_bound(d,d+k,s)-d-1])*x;
for(i=0;i<m;i++)
if(b[i]<=s)ans=min(ans,(n-c[upper_bound(d,d+k,s-b[i])-d-1])*a[i]);
cout<<ans<<endl;}