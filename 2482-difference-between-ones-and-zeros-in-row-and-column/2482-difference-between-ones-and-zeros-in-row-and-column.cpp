class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> onerows;
        vector<int> onecols;
        
        for(int i=0;i<m;i++){
            int sum = 0;
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    sum += 1;
                }
            }
            onerows.push_back(sum);
        }
        for(int j=0;j<n;j++){
            int sum = 0;
            for(int i=0;i<m;i++){
                if(grid[i][j] == 1){
                    sum += 1;
                }
            }
            onecols.push_back(sum);
        }
        vector<int> zerorows(m);
        vector<int> zerocols(n);
        for(int i=0;i<m;i++){
            zerorows[i] = m-onerows[i];
        }
        for(int i=0;i<n;i++){
            zerocols[i] = n-onecols[i];
        }
        vector<vector<int>> dist(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dist[i][j] = onerows[i] + onecols[j] - zerorows[i] - zerocols[j];
            }
        }
        return dist;
    }
};