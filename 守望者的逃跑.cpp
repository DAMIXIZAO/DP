#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int m,s,t;
int f[N];//f[i]表示i时刻走了多远。 
int main(void)
{
	cin>>m>>s>>t;
	int mm=m;
	for(int i=1;i<=t;i++)
	{
		if(mm>=10)
		{
			mm-=10;
			f[i]=f[i-1]+60;
		} 
		else
		{
			f[i]=f[i-1];
			mm+=4;
		}
	}
	for(int i=1;i<=t;i++)
	{
		if(f[i]<f[i-1]+17)
		{
			f[i]=f[i-1]+17;
		}
		if(f[i]>=s)
		{
			cout<<"Yes"<<endl;
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	cout<<f[t]<<endl;
	return 0;
}
