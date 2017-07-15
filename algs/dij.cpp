#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

const int INF=1000000;

void f(vector<vector<int>>& A, vector<int>& d){
	int N=A.size();
	for(int i=0;i<N;i++) d[i]=A[0][i];
	unordered_set<int> V;
	for(int i=1;i<N;i++) V.insert(i);
	int chosen_v= 0;
	for(int i=0;i<N-1;i++){
		int min_dist=INF;
		int min_idx=0;
		for(auto v:V){
			if((d[chosen_v]!=INF) && (A[chosen_v][v]!=INF))
				d[v]=min(d[v], d[chosen_v]+A[chosen_v][v]);	
			if(d[v]<min_dist){
				min_dist=d[v];	
				min_idx=v;
			} 
		}
		chosen_v=min_idx;
		V.erase(min_idx);
	}
}

int main(){

	int N=6;
	vector<vector<int>> A={{0, 7, 9, INF, INF, 14}, {7, 0,10, 15, INF, INF}, {9, 10, 0, 11, INF, 2}, {INF, 15, 11, 0, 6, INF}, {INF, INF, INF, 6, 0, 9}, {14, INF, 2, INF, 9, 0}};
	for(auto vec:A){
		for(auto v:vec){
			cout<<v<<" ";	
		}
		cout<<endl;	
	}
	cout<<endl;
	vector<int> d(N);
	f(A, d);
	for(int i=0;i<N;i++){
		cout<<i<<" "<<d[i]<<endl;
	}
	return 0;
}
