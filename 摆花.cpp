#include <bits/stdc++.h>
using namespace std;
const int N=110,mod=1e6+7;
int n,m;
int a[N],s[N];
int f[N];
int main(void)
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	f[0]=1;
	for(int i=0;i<=m;i++) s[i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) s[j]=(s[j-1]+f[j]+mod)%mod;
		for(int j=m;j>=1;j--)
		{
			int t=j-min(j,a[i])-1;
			if(t<0) f[j]=(f[j]+s[j-1]+mod)%mod;
			else f[j]=(f[j]+s[j-1]-s[t]+mod)%mod;
		}
	}
	cout<<f[m]<<endl;
	return 0;
}
