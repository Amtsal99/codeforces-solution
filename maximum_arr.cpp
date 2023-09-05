#include<iostream>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;
ll solve(vector<ll>v,ll n,ll k,ll sum){
	for(int i=n-k;i<n;i++){
		ll temp_sum=sum-(v[0]+v[1])+v[i];
		v.erase(v.begin(),v.begin()+2);
		sum=max(sum,temp_sum);
	}
	return sum;
	
}
int main(){
	ll t,n,k;
	cin>>t;
	ll arr[t];
	for(ll i=0;i<t;i++){
		cin>>n>>k;
		vector<ll> v;
		ll temp;
		ll sum=0;
		for(ll j=0;j<n;j++){
			cin>>temp;
			v.push_back(temp);
		}
		sort(v.begin(),v.end());
		for(ll m=0;m<n-k;m++){
		   sum+=v[m];
		}
		cout<<sum<<endl;
		arr[i]=solve(v,n,k,sum);
		
		
	}
	for(ll i:arr){
		cout<<i<<endl;
	}

	return 0;
}