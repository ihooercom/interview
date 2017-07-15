#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void permute(vector<int>& vec, int n, int start){
	if(start==n){
		for	(auto v:vec) cout<<v<<" ";
		cout<<endl;
	}else{
		for(int i=0;i<=start;i++){
			swap(vec[i], vec[start]);		
			permute(vec, n, start+1);
			swap(vec[i], vec[start]);
		}
	}
}


int main()
{
	
	int n=5;
	vector<int>  vec(n);
	for(int i=0;i<n;i++) vec[i]=i+1;
	permute(vec, n, 1);

	return 0;
}
