/*
Lc: 542 ---> 01 Matrix
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
private:
    bool isValid(int i, int j, int n, int m){
        if(i >= n || j >= m || i < 0 || j < 0){
            return false;
        }
        return true;
    }
public:        
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        /*
        
        How does one know that we need BFS here and not DFS, which is a very true dilemma is many problems, well the first thought that crosses my mind seeing this problem is if somehow I could iterate through all 0's in matrix and start a recursive action at these cells updating distances of neighboring cells by 1, keep doing so and stop only if the cell under consideration is already closer to another 0.

For this to be successful we need all those actions to execute only 1 round at a time ( visit 4 neighbors ) and then wait for all others to execute their 1 rounds so recursion doesn’t work ( DFS failed only 1 option left BFS). See how this is so similar to the tree case when we needed the kids of the current node only after we have visited nodes at same level, it’s a BFS , bingo! The reason we need this here is if we don’t wait for other actions to execute a round how would we know if the current cell is already closer to another 0 in which case we need to stop BFS operation for that cell.
        
        */
        
        
        queue<int> q;
        int n = mat.size();
        int m = mat[0].size();
        
        // this will work as visited array -> mark as unvisited
        vector<vector<int>> dis(n, vector<int> (m, -1));    
        
        // Push all 0 to queues... to start bfs from there
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    dis[i][j] = 0;  // visited -> with distance = 0
                    q.push(i * m + j);  // one based array -> cell number
                }
            }
        }
        
        int level = 0;
                                // up , down, left right  
        vector<vector<int>> dir = {{1,0}, {0,1}, {0,-1}, {-1,0}};
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int curCell = q.front();
                q.pop();
                
                int cell_row = curCell / m;
                int cell_col = curCell % m;
                
                // I can go to four different directions
                
                for(int ind = 0; ind < 4; ind++) {
                    
                    int new_r = cell_row + dir[ind][0];
                    int new_c = cell_col + dir[ind][1];
                    
                    if(isValid(new_r, new_c, n, m)  && dis[new_r][new_c] == -1) {
                        q.push(new_r * m + new_c);  // cell for next level
                        
                        dis[new_r][new_c] = level + 1;      // because for next level                        
                    }                    
                }
            }
            
            level++;
        }
        return dis;
    }
};


int main(){
    
    int t; cin >> t;
    while(t--){
        
    }
    return 0;
}