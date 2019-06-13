//PRINCE
//Question link
// https://www.spoj.com/problems/ABCDEF/

#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back 
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define ll long long int 
typedef vector<ll> vll;
typedef vector<int> vii;

#define MOD 1000000007
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";

ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll power(ll x,ll n){if(n==0)return 1;if(n%2)return x*power(x*x,(n-1)/2);return power(x*x,n/2);}
ll powerm(ll x,ll n){if(n==0)return 1;if(n%2)return (x*powerm((x*x)%MOD,(n-1)/2))%MOD;return powerm((x*x)%MOD,n/2);}
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int32_t main()
{

    //kiimati 4 line for sublime text
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);//FAST
    ll n;cin>>n;
    int A[n];
    rep(i,0,n)
    {
    	cin>>A[i];
    }
    vector<ll>L,R;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		for(int k=0;k<n;k++)
    		{
    			L.pb((A[i]*A[j])+A[k]);				
    		}
    	}
    }
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		for(int k=0;k<n;k++)
    		{
    			if(A[k]!=0)
    			R.pb((A[i]+A[j])*A[k]);				
    		}
    	}
    }
    ll ans=0;
    sort(R.begin(),R.end());
    for(int i=0;i<L.size();i++)
    {
    	int lb = lower_bound(R.begin(),R.end(),L[i])-R.begin();
    	int ub = upper_bound(R.begin(),R.end(),L[i])-R.begin();
    	if(R[lb]==L[i])
    	{
    		ans+=(ub-lb);
    	}
    	else
    	{
    		ans+=(ub-lb);
    	}
    }
    cout<<ans<<"\n";
    return 0;
}
