#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

void dfs(vector<int>& nums, int num_idx_last_chosen, int sum_remain, vector<int>& comb_vec, vector<vector<int>>& result){
        if (sum_remain==0){
            result.push_back(comb_vec);
        }else if (sum_remain <0){
            return;
        }else{
            for(int i=num_idx_last_chosen;i<nums.size();++i){
                comb_vec.push_back(nums[i]);
                dfs(nums, i, sum_remain-nums[i], comb_vec, result);
                comb_vec.pop_back();
            }
        }
}

int main()
{
    vector<int> nums={2,3,4,5};
    vector<int> comb_vec;
    vector<vector<int>> result;
    int T = 10;
    dfs(nums, 0, T, comb_vec, result);
    cout<<result.size()<<endl;
    for(auto each:result){
        for(auto num:each){
            cout<<num<<" ";
        }
        cout<<endl;
    }
  
   return 0;
}