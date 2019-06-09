//PRINCE
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
ll p[100];
bool did(int n,ll m,ll K)
{
	ll ans=0;
	for(int i=1;i<(1<<n);i++)
    {
    	int c=0;
    	ll sum=1;
    	for(int j=0;j<n;j++)
    	{
    		if(i&(1<<j))
    		{
    			c++;
    			sum*=p[j];
   			}
    	}
    	if(c%2)
    	{
    		ans+=(K/sum);
    	}
    	else
    		ans-=(K/sum);
    }
    if(ans>=m) 
    	return true;
    else 
    	return false;  
}
int32_t main()
{

    //kiimati 4 line for sublime text
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);//FAST
    int T;cin>>T;
    while(T--)
    {
    	string s;cin>>s;
    	ll K;cin>>K;
    	int c=0;
    	for(int i=0;i<s.size();i++)
    	{
    		if(s[i]-'0')
    		{
				p[c++]=i+1;
    		}
    	}
    	//cout<<"*\n";
    	ll lo=1,hi=1000000000000000000;
    	while(lo<hi)
    	{
    		ll mid =lo+(hi-lo)/2;
    		if(did(c,K,mid))
    			hi=mid;
    		else
    			lo=mid+1;
    	}
    	cout<<lo<<"\n";
    }
    return 0;
}