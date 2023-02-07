#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define pb push_back
#define ll long long int
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool findroot(ll n,ll k,ll val){
	if(pow(val,k)<=n)
		return true;
	else
		return false;
}

float kthroot(ll n,ll k,ll p){
	ll s=0,e=n,ans=-1;
	while(s<=e){
		ll mid=(s+e)/2;
		if(findroot(n,k,mid)){
			ans=mid;
			s=mid+1;
		}
		else{
			e=mid-1;
		}
	}
	float inc=0.1;
	for(int times=1;times<=p;times++){
		while(pow(ans,k)<=n){
			ans+=inc;
		}
		ans-=inc;
		inc/=10;
	}
	return ans;
}

int main(){
fastio;
int t;
cin>>t;
while(t--){
	ll n,k,p;
	cin>>n>>k>>p;
	float ans=kthroot(n,k,p);
	cout<<ans<<endl;
}

return 0;
}
// JrphaOcrky