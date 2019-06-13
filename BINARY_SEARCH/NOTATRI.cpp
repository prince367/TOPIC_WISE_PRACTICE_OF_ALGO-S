//PRINCE
//Question link
// https://www.spoj.com/problems/NOTATRI/
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
int A[100000];
int B_search(int l,int r,int N,int sum)
{
	int lo=0,hi=N-1;
	while(lo<hi)
	{
		int mid=lo+(hi-lo)/2;
		if(A[mid]>sum)
		{
			hi=mid;
		}
		else
		{
			lo=mid+1;
		}
	}
	if(A[lo]<=sum)
	{
		lo++;
	}
	///cout<<sum<<" "<<lo<<"\n";
	if(lo>=l and lo>=r)
	{
		return N-lo;
	}
	if(lo>=l or lo>=r)
	{
		return N-lo-1;
	}
	else
	{
		return N-lo-2;
	}
}
int32_t main()
{

    //kiimati 4 line for sublime text
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);//FAST
    int N;cin>>N;
    while(N!=0)
    {
    	rep(i,0,N)
    	{
    		cin>>A[i];
    	}
    	sort(A,A+N);
    	int ans=0;
    	for(int i=0;i<N;i++)
    	{
    		for(int j=i+1;j<N;j++)
    		{
    			//cout<<A[i]+A[j]<<"\n";
    			ans+=B_search(i,j,N,A[i]+A[j]);
    		}
    	}
    	cout<<ans<<"\n";
    	cin>>N;
    }
    return 0;
}
