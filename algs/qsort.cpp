#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void qsort(vector<int>& vec, int left, int right){
	if(left>=right) return;
	int tmp = vec[left];
	int i=left, j=right;
	while(i<j){
		while(vec[j]>= tmp && i< j) j--;
		while(vec[i] <= tmp && i< j) i++;
		if (i<j) swap(vec[i], vec[j]);
	}
	vec[left] = vec[i];
	vec[i]= tmp;
	f(vec, left, i-1);
	f(vec, i+1, right);
}

int main()
{
	vector<int> vec={19,2,4,1,5, 12,41,2,3,1,1,1};
	qsort(vec, 0, vec.size()-1);
	for(auto n:vec){
		cout<<n<<" ";	
	}
	cout<<endl;
	return 0;
}

