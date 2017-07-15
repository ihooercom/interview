#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <string>
using namespace std;

void insertSort(vector<int>& vec){
    for(int i=1;i<vec.size();i++){
        int j=0;
        for(j=0;j<i && vec[j]<=vec[i];j++);
        if(j<i){
            int tmp=vec[i];
            for(int k=i;k>j;k--) vec[k]=vec[k-1];
            vec[j]=tmp;
        }
    }
}

int main()
{
    vector<int> vec={1,3,5,3,67,6,2};
    insertSort(vec);
    for(auto n:vec){
        cout<<n<<" ";
    }
    cout<<endl;

}