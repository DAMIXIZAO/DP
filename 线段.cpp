#include <bits/stdc++.h>
using namespace std;
const int N=2e4+10,INF=0x3f3f3f3f; 
int n;
int l[N],r[N];
int f[N][2];
int main(void)
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
	l[1]=1,r[n]=n;
	int lx,rx;
	for(int i=1;i<=n;i++)
	{
		int sum=r[i]-l[i];
		if(i==1)
		{
			f[1][1]=sum;
			f[1][0]=sum*2;
			lx=l[1],rx=r[1];
		}
		else
		{
			int a=abs(r[i]-lx)+sum;
			int b=abs(r[i]-rx)+sum;
			int c=abs(l[i]-lx)+sum;
			int d=abs(l[i]-rx)+sum;
			f[i][0]=min(f[i-1][0]+a,f[i-1][1]+b);
			f[i][1]=min(f[i-1][0]+c,f[i-1][1]+d);
			lx=l[i],rx=r[i];
		}
	}
	cout<<f[n][1]+n-1<<endl;
	return 0;
}
