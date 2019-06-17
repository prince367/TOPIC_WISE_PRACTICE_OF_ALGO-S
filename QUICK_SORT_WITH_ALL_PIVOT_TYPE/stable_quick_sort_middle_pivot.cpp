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
	int p_index = low+(high-low)/2;
	int pivot = arr[p_index];
	int i=low-1;
	for(int j=low;j<=high;j++)
	{
		if(j==p_index)
			continue;
		if(arr[j]<pivot)
		{
			i++;	
			if(i==p_index) 
				i++;
			swap(arr[j],arr[i]);
		}
		else if(arr[j]==pivot and j<p_index) // smallest index come first if equal elements
		{
			i++;
			swap(arr[j],arr[i]);
		}
	}
	if(i<p_index)
	{
		swap(arr[p_index],arr[i+1]);
		return i+1;
	}
	else
	{
		swap(arr[p_index],arr[i]);
		return i;		
	}
}
void quick_sort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pivot = partition(arr,low,high);
		quick_sort(arr,low,pivot-1);
		quick_sort(arr,pivot+1,high);
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