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

int32_t main()
{

    //kiimati 4 line for sublime text
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);//FAST
    int N;cin>>N;//number of book cabinet
    int M;cin>>M;//number of worker
    int cabinet[N]; //number of books on each cabinet
    int max_book_no=0;
    int total_books=0;
    for(int i=0;i<N;i++)
    {
    	cin>>cabinet[i];
    	max_book_no = max(max_book_no,cabinet[i]);
    	total_books += cabinet[i];
    }
    int lo = max_book_no; // minimum possible required answer 
    int hi=total_books; //maximum possible required answer
    while(lo<hi)
    {
    	int mid=lo+(hi-lo)/2;
    	int curr_load=0;
    	int num_work=1;
    	for(int i=0;i<N;i++)
    	{
    		if(curr_load+cabinet[i]<=mid)
    		{
    			curr_load+=cabinet[i];
    		}
    		else
    		{
    			curr_load=cabinet[i];
    			num_work++;
    		}
    	}
    	if(num_work<=M)
    	{
    		hi=mid;
    	}
    	else
    	{
    		lo=mid+1;
    	}
    }
    cout<<"Required answer is :- "<<lo<<"\n";
    return 0;
}