#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);
vector<int> v(1005);
void build_next(string T){
	v[0] = 0;
	int pre_len = 0;
	int	i = 1;
	while(i<T.length()){
		if(T[pre_len] == T[i]){
			pre_len++;
			v.push_back(pre_len);
			i++;
		} else { 
			if(pre_len > 0){
				pre_len = v[pre_len-1];
			}
			if(pre_len == 0){
				v.push_back(0);
				i++;
			}
		}
	}
}
bool KMP(string S, string T){
	build_next(T);
	int i=0,j=0;
	while(i<S.length()){
		if(S[i] == T[j]){
			i++;
			j++;
		} else if(j>0){
			j = v[j-1];
		} else {
			i++;
		}

		if(j == T.length()){
			return 1;
		}
	}
	return 0;
}


int32_t main(){
	int k;
	cin>>k;
	while(k--){
		int q;
		string s;
		cin>>s;
		cin>>q;
		while(q--){
			string t;
			cin>>t;
			if(KMP(s,t) == 1)cout<<"y"<<endl;
			else cout<<"n"<<endl;
		
		}
	}
	return 0;
}

