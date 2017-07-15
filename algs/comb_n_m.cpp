#include<iostream>
#include<vector>
using namespace std;

void comb(int n, int m, int chosen_num, int start, vector<int>& vec){
	if(chosen_num==m){
		for	(auto v:vec) cout<<v<<" ";
		cout<<endl;
	}else{
		for(int i=start;i<n;i++){
			vec.push_back(i+1);
			comb(n, m, chosen_num+1, i+1, vec);
			vec.pop_back();
		}
	}
}


int main()
{
	
	vector<int>  vec;
	comb(5,2,0, 0, vec);

	return 0;
}
