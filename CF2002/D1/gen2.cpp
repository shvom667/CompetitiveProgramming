#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cout<<"1\n65535 50000\n";
	for(int i=2;i<=65534;i++) cout<<i/2<<" ";
	cout<<65535/2<<"\n";
	for(int i=1;i<=65534;i++) cout<<i<<" ";
	cout<<"65535\n";
	int nx=1,ny=1;
	while(nx*2<=65535) nx*=2;
	while(ny*2+1<=65535) ny=(ny*2+1);
	for(int i=1;i<=(int)5e4;i++)
	{
		cout<<nx<<" "<<ny<<"\n";
	}
}
