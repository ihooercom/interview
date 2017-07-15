#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <string>
using namespace std;

int KMP(const string &T, const string &P, vector<int>& next){
    int i=0, j=0;
    while((i<(int)T.length()) && (j<(int)P.length())){
        if(j==-1 || T[i]==P[j]){
            i++;j++;
        }else{
            j=next[j];
        }
    }
    if(j<P.length()) return -1;
    else return i-P.length();
}
void getNext(const string &P, vector<int>& next){
    next[0]=-1;
    int k=-1;
    int j=0;
    while(j<P.length()){
        if(k==-1 || P[k]==P[j]) {
            k++;j++;
            next[j]=k;
        }else{
            k=next[k];
        }
    }
}
int main()
{
    string T="fjdssfdsfkfjd";
    string P="dsfk";
  vector<int> next(P.size(), 0);
  getNext(P, next);
  int idx= KMP(T, P, next);
  cout<<idx<<endl;

}