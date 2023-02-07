#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define pb push_back
#define ll long long int
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool isTrue(int a[],int n,int m,int pages){
int numberofStud=0;
int i=0,curSum=0;
while(i<n){
	curSum+=a[i];
	if(curSum>pages){
		curSum=0;
		numberofStud++;
		i--;
	}
	if(numberofStud>=m){
		return false;
	}
	i++;
}
return true;
}

int main(){
fastio;
int t;
cin>>t;
while(t--){
int n,m;
cin>>n>>m;	
int a[n];
int sum=0,maxx=INT_MIN;
rep(i,n){
	cin>>a[i];
	sum+=a[i];
	if(a[i]>maxx)
		maxx=a[i];
}
int s=maxx;
int e=sum;
int ans=-1;
while(s<=e){
	int mid=(s+e)/2;
	if(isTrue(a,n,m,mid)){
		ans=mid;
		e=mid-1;
	}
	else{
		s=mid+1;
	}
}
cout<<ans<<endl;

}

return 0;
}
// JrphaOcrky