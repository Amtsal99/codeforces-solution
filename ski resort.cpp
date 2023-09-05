#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
	int  t;
	cin>>t;
	for(int i=0;i<t;i++){
		int panjang=0;
		int n,k,q;
		int suhu;
		cin>>n>>k>>q;
		ll total_kombinasi=0;
		for(int j=0;j<n;j++){
			cin>>suhu;
			if(suhu<=q){
				panjang++;
			}
			else{
				panjang=0;
			}
			total_kombinasi+=max(0,panjang-k+1);
		}
		cout<<total_kombinasi<<endl;
	}
	return 0;
	
}