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

// IGNORE ALL THE ABOVE LINE EXCEPT "//PRINCE"

int Array[100001];
int N;
bool predicate(int a,int val)
{
	if(a>val) return true;
	return false;
}
int up_bound(int l,int h,int val)
{
	int lo=l,hi=h;
	while(lo<hi)
	{
		int mid=lo+(hi-lo)/2;
		if(predicate(Array[mid],val))
			hi=mid;
		else
			lo=mid+1;
	}
	if(!predicate(Array[lo],val)) return N;
	 return Array[lo];
}
int32_t main()
{

    //kiimati 4 line for sublime text
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);//FAST
    cin>>N;
    rep(i,0,N)
    {
    	cin>>Array[i];
    }
    sort(Array,Array+N);
    int val;
    cin>>val;
    cout<<up_bound(0,N-1,val);
    return 0;
}