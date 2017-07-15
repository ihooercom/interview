#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
 using namespace std;
int wordLadder(unordered_set<string>& dict, string start, string end, unordered_map<int, vector<string>>& all_avail){
    unordered_map<string, int> vis;
    vis[start]=1;
    all_avail[0]= vector<string>(1, start);
    queue<string> q;
    q.push(start);
    int end_level=-1;
    while(!q.empty()){
        string s=q.front();
        q.pop();
        if(end_level >=0) return end_level;
        for(int i=0;i<s.length();i++){
            for(char c='a';c<='z';c++){
                string new_str=s;
                new_str[i]=c;
                if(dict.count(new_str) && (vis.find(new_str)==vis.end())){
                    q.push(new_str);
                    vis[new_str] = vis[s]+1;
                    if (all_avail.find(vis[s])!=all_avail.end()){
                        all_avail[vis[s]].push_back(new_str);
                    }else{
                        all_avail[vis[s]]=vector<string>(1,new_str);
                    }
                    if(new_str==end) end_level = vis[new_str];
                }
            }
        }
    }
    return 0;
}

void dfs(int sp, int ep, unordered_map<int, vector<string>>& all_avail, vector<string>& vec)
{
    if(sp==ep){
        for(auto s:vec){
            cout<<s<<" ";
        }
        cout<<endl;
    }else{
        for(auto s:all_avail[sp]){
            vec.push_back(s);
            dfs(sp+1, ep, all_avail, vec);
            vec.pop_back();
        }
    }
}
int main()
{
    unordered_set<string> dict={"abd","ebd","ebf"};
    string start="abc", end="ebb";
    dict.insert(end);
    unordered_map<int, vector<string>> all_avail;
    int num=wordLadder(dict, start, end, all_avail);
    // for(auto pair:all_avail){
    //     cout<<pair.first<<" ";
    //     for(auto s:pair.second){
    //         cout<<s<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<string> vec;
    dfs(0, num, all_avail, vec);
    return 0;
}