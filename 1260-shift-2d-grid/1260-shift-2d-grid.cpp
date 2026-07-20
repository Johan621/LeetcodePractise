class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> v;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v.push_back(grid[i][j]);
            }
        }
        k %= v.size();
        vector<int> rotated(v.size());
        for(int i=0;i<v.size();i++){
            rotated[(i+k)%v.size()] = v[i];
        }
        vector<vector<int>> ans(m,vector<int>(n));
        int idx = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = rotated[idx++];
            }
        }
        return ans;
    }
};