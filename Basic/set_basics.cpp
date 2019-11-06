#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    long long int sum=0;
    scanf("%d",&t);
    while(t--)
    {
        int n;
         scanf("%d",&n);
         map<ll,ll> m;
          while(n--)
        {
            int q,val;
             scanf("%d %d",&q,&val);
            if(q==1)
            {
                m[val]++;
                sum+=m[val];
            }
            else
            {
                if(m[val]>0)
                {
                 sum-=m[val];
                  m[val]--;
                }

            }


            printf("%ld",sum);
        }
    }
}
