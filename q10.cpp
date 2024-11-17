#include<bits/stdc++.h>
using namespace std;
#define int long long
int l[200005],r[200005];
signed main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin>>t;

    while(t--)
    {
        int n,k,total=0;
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>l[i];
        for(int i=0;i<n;i++) cin>>r[i];
        for(int i=0;i<n;i++)
        {
            total+=(r[i]-l[i]+1);
        }
        if(total<k) cout<<-1<<'\n';
        else
        {
            int ans=0,tmp;
            int now=0,cnt1=0,pos,tp;
            for(int i=0;i<n;i++)
            {
                if(l[i]==r[i]) cnt1++;
                now+=(r[i]-l[i]+1);
                if(now>=k)
                {
                    pos=i;
                    ans=2*(i+1)+r[i]-(now-k);
                    tp=r[i]-(now-k);
                    break;
                }
            }
            tmp=ans;
            while(cnt1>0&&pos<n)
            {
                tmp-=2;
                cnt1--;
                if(tp+1<=r[pos])
                {
                    tmp++;
                    tp++;
                }
                else if(pos+1==n)
                {
                    break;
                }
                else
                {
                    tmp+=2;
                    tmp+=(l[pos+1]-r[pos]);
                    tp=l[pos+1];
                    pos++;
                    if(l[pos]==r[pos])
                    {
                        cnt1++;
                    }

                }
                ans=min(ans,tmp);
            }
            cout<<ans<<'\n';
        }
    }
}
