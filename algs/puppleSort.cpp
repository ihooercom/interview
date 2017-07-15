#include<iostream>
#include<vector>
using namespace std;

void puppleSort(vector<int>& vec){
	for(int i=1;i<vec.size();i++){
		bool exchange= false;	
		for(int j=vec.size()-1;j>=i;j--){
			if(vec[j-1]>vec[j]){
				int t=vec[j-1];vec[j-1]=vec[j];vec[j]=t;	
				exchange = true;
			}	
		}
		if(exchange == false) return;
	}
}

void chosenSort(vector<int>& vec){
	for(int i=0;i<vec.size()-1;i++){
		int k=i;
		for(int j=i+1;j<vec.size();j++){
			if(vec[j]<vec[k]) k=j;
		}	
		if(k!=i){
			int t=vec[i];vec[i]=vec[k];vec[k]=t;	
		}
	}
}

int main(){

	vector<int> vec={1,3,4,1,6,23,5};
	//puppleSort(vec);
	chosenSort(vec);
	for(auto v:vec){
		cout<<v<<" ";	
	}
	cout<<endl;


	return 0;
}

