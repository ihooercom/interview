#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
 using namespace std;
 struct Point{
     int i,j;
     Point(int i_, int j_){
         i=i_;j=j_;
     }
 };
void bfs(vector<vector<char>>& board){
    queue<Point> q;
    vector<vector<int>> mask(board.size(), vector<int>(board[0].size(), 0));
    for(int i=0;i<board.size();i++){
        if(board[i][0]=='o') {
            q.push(Point(i,0));
            mask[i][0]=1;
        }
        if(board[i][board[0].size()-1]=='o'){
            q.push(Point(i, board[0].size()-1));
            mask[i][board[0].size()-1]=1;
        }
    }
    for(int j=0;j<board[0].size();j++){
        if(board[0][j]=='o'){
            q.push(Point(0,j));
            mask[0][j]=1;
        }
        if(board[board.size()-1][j]=='o'){
            q.push(Point(board.size()-1, j));
            mask[board.size()-1][j]=1;
        }
    }
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    while(!q.empty()){
        Point p=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            Point p_new(p.i+x[i], p.j+y[i]);
            if(p.i+x[i]>=0 && p.i+x[i]<mask.size() && p.j+y[i]>=0 && p.j+y[i]< mask[0].size() && mask[p.i+x[i]][p.j+y[i]]==0 && board[p.i+x[i]][p.j+y[i]]=='o'){
                q.push(p_new);
                mask[p.i+x[i]][p.j+y[i]]=1;
            }
        }
    }
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='o' && mask[i][j]==0){
                board[i][j]='x';
            }
        }
    }
}

int main()
{
    vector<vector<char>> board={{'o','x','x','x'},{'x','o','o','x'},{'x','x','o','x'},{'x','o','x','x'}};
    
    bfs(board);
    for(auto row:board){
        for(auto c:row){
            cout<<c<<" ";
        }
        cout<<endl;
    }
    return 0;
}