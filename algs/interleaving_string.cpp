#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <string>
using namespace std;

bool f(string& s, string& s1, string& s2, int i, int j, int k, vector<vector<vector<int>>>& bak){
    if(i<-1 || j<-1 ||k <-1) return 0;
    if(i==-1 && j==-1 && k == -1) return 1;
    if(bak[i+1][j+1][k+1]>=0){
        return (bak[i+1][j+1][k+1]>=1);
    }
    bool i_j_ok=false, i_k_ok=false;
    if(s[i]==s1[j]) i_j_ok = f(s, s1, s2, i-1, j-1,k, bak);
    if(s[i]==s2[k]) i_k_ok = f(s, s1, s2, i-1, j,k-1, bak);

    bool is_ok = max(i_j_ok, i_k_ok);
    bak[i+1][j+1][k+1]=(int)is_ok;
    return is_ok;
}


int main()
{
    string s1="aa";
    string s2 ="cc";

    // string s3 = "aadbbcbcac";
     string s3 = "ccca";
    int I=s3.length();
    int J=s1.length();
    int K=s2.length();
    vector<vector<vector<int>>> bak(I+1, vector<vector<int>>(J+1, vector<int>(K+1, -1)));
    bool is_ok = f(s3, s1, s2, I-1, J-1, K-1, bak);
    cout<< is_ok <<endl;

}