#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);
		if(n==1)puts("0");
		else printf("%d\n",(n-2)/(k-1)+1);
	}
	return 0;
}