#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 110
int t,n,a[N],flag;
vector<int> g;
int check(){
	for(int i=1;i<g.size();i++){
		if(g[i-1]>=g[i]+1){
			return 0;
		}
	}
	return 1;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		flag=0;
		for(int i=0;i<=n;i++){
			g.clear(); 
			for(int j=1;j<=n;j++){
				if(a[j]>=10&&j<=i){
					g.push_back(a[j]/10);
					g.push_back(a[j]%10);
				}
				else{
					g.push_back(a[j]);
				}
			}
			if(check()){
				cout<<"Yes"<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0){
			cout<<"No"<<endl;
		} 
	}
    return 0;
}