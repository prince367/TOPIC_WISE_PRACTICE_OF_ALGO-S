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
int partition(int arr[],int low,int high)
{
	int pivot = arr[high];
	int i=low-1;
	for(int j=low;j<high;j++)
	{
		if(arr[j] < pivot)
		{
			i++;
			swap(arr[j],arr[i]);
		}
	}
		swap(arr[i+1],arr[high]);
	return i+1;
}


int random_partition(int arr[] ,int low ,int high)
{
	srand(time(NULL));
	int random = low + rand()%(high-low);
	swap(arr[random],arr[high]);
	int pivot = partition(arr,low,high);
	return pivot;
}


void quick_sort(int arr[] ,int low ,int high)
{
	if(low < high)
	{
		int pivot = random_partition(arr ,low , high);
		quick_sort(arr ,low ,pivot-1);
		quick_sort(arr ,pivot+1 ,high); 
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
    int A[N];
    rep(i,0,N)
    {
    	cin>>A[i];
    }
    quick_sort(A,0,N-1);
    rep(i,0,N)
    {
    	cout<<A[i]<<" ";
    }
    return 0;
}