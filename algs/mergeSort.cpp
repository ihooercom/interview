#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <string>
using namespace std;

void merge(vector<int>& vec, int start, int mid, int end, vector<int>& bak){
    for(int i=start;i<=end;i++) bak[i]=vec[i];
	int i=start;
	int j=mid+1;
	int t=start;
	while(i<=mid && j<=end){
		if(bak[i]<=bak[j]){
			vec[t++]=bak[i++];
		}else{
			vec[t++]=bak[j++];
		}
	}
	while(i<=mid){
		vec[t++]=bak[i++];
	}
	while(j<=end){
		vec[t++]=bak[j++];
	}
}

void mergeSort(vector<int>& vec, int start, int end, vector<int>& bak){
	if(start>=end) return;
	int mid=(start+end)/2;
	mergeSort(vec, start, mid, bak);
	mergeSort(vec, mid+1, end, bak);
	merge(vec, start, mid, end, bak);
}

int main()
{
    vector<int> vec={2,1,2,3,4,1,23,5,1};
    vector<int> bak(vec.size(), 0);
    mergeSort(vec, 0, vec.size()-1, bak);
    for(auto n:vec){
        cout<<n<<" ";
    }
    cout<<endl;

}