#include<iostream>
#include<string>
using namespace std;
int dp(string cek,char a){
	int indeks = 400000;
	for(int i=0;i<cek.length();i++){
		if(cek[i]==a){
			indeks = i;
			break;
		}
	}
	return indeks;
}	
bool jawab(string cek,string a, string b,bool& ans){
	int lb=-1;
	if(a==""){
		return 1;
	}
	else if(cek==""){
		return 0;	
	}
	else{
		for(int i=(int)a[0];i<=(int)b[0];i++){
			if(dp(cek,(char)i)==400000){
				return 0;
				break;
			}
				else{		
			lb=max(lb,dp(cek,(char)i));
			}
		}
		cek=cek.erase(0,lb+1);          
		a=a.erase(0,1);
		b=b.erase(0,1);
		ans = jawab(cek,a,b,ans);
	}
	return ans;
}
int main(){
	bool ans;
	int test_case,digits;
	string cek,a,b;
	cin>>test_case;
	string arr[test_case];
	for(int i=0;i<test_case;i++){
		cin>>cek;
		cin>>digits;
		cin>>a>>b;
		if(cek.length()<a.length()||cek.length()<b.length()){
			arr[i]="YES";
		}
		else{
			if(jawab(cek,a,b,ans)==0){
				arr[i]="YES";
			}
			else{
				arr[i]="NO";
			}
		}
	}
	for(auto element:arr){
		cout<<element<<endl;
	}
	return 0;
}