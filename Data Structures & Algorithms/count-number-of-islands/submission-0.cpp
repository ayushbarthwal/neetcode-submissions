class Solution {
public:
    vector<pair<int,int>> a = {
            {-1,0},{1,0},{0,-1},{0,1}
    };
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        for(auto p: a){
            int r = i+p.first;
            int c = j+p.second;
            dfs(r,c,grid);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    island++;
                }
            }
        }
        return island;
    }
};
