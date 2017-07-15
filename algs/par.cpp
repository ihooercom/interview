#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>
 using namespace std;
 
 vector<vector<string>> split_result;
 void dfs(vector<vector<string>>& parStart, vector<string>& vecStr, int sp, int ep){
     if (sp==ep){
         split_result.push_back(vecStr);
     }else{
         for(auto parStr:parStart[sp]){
             vecStr.push_back(parStr);
             dfs(parStart, vecStr, sp+parStr.length(), ep);
             vecStr.pop_back();
         }
     }
 }
 
int main()
{
   string s="fjdfddf2jadskdj";
   vector<vector<string>> parStart(s.length());
   for(size_t i =0;i< s.length();++i){
       for(size_t j=i;j>=0 && 2*i-j < s.length() && s[j]==s[2*i-j];--j){
           parStart[j].push_back(s.substr(j, 2*i-j-j+1));
       }
       for(size_t j=i;j>=0 && 2*i-j+1 < s.length() && s[j]==s[2*i-j+1];--j){
           parStart[j].push_back(s.substr(j, 2*i-j-j+1+1));
       }
   }
   vector<string> vecStr;
   dfs(parStart, vecStr, 0, s.length());
   for(auto split_each:split_result){
       for(auto par:split_each){
           cout<<par<<" ";
       }
       cout<<endl;
   }
   
}