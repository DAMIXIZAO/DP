#include <bits/stdc++.h>
using namespace std;
const int N=400;
int n,m;
int g[N],a,b,c,d;
int f[41][41][41][41];
int main(void)
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>g[i];
	for(int i=1;i<=m;i++) 
	{
		int e;
		cin>>e;
		if(e==1) a++;
		if(e==2) b++;
		if(e==3) c++;
		if(e==4) d++;
	}
	f[0][0][0][0]=g[1];
	for(int i1=0;i1<=a;i1++)
	{
		for(int i2=0;i2<=b;i2++)
		{
			for(int i3=0;i3<=c;i3++)
			{
				for(int i4=0;i4<=d;i4++)
				{
					int len=1+i1+2*i2+3*i3+4*i4;
					if(i1!=0) f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1-1][i2][i3][i4]+g[len]);
					if(i2!=0) f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1][i2-1][i3][i4]+g[len]);
					if(i3!=0) f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1][i2][i3-1][i4]+g[len]);
					if(i4!=0) f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1][i2][i3][i4-1]+g[len]);					
				}
			}
		}
	}
	cout<<f[a][b][c][d]<<endl;
	return 0;
}
