#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
 
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        map<int,int> m;
        for(int i=0;i<n;i++){
            cin>>a[i];
            m[a[i]]++;
        }
        int ans=0,mx=0;
        for(auto [f,ff]:m){
            if((f-mx)*n>=k){
                ans+=k;
                k=0;
                break;
            }
            ans+=(f-mx)*n;
            k-=(f-mx)*n;
            mx=f;
            ans+=ff;
            n-=ff;
        }
        cout<<ans<<endl;
    }
    return 0;
}