#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,i,c;
	for(cin>>T;T>0;T--)
	{
		cin>>n>>s;
		c=0;
		for(i=0;i<n;i++)
		{
			if(s[i]=='0'&&(i==0||s[i-1]!='0'))c--;
			else if(s[i]=='1')c++;
		}
		if(c>=1)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}