class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0,right = n-1,top = 0,bottom = n-1;
        int num = 1;
        vector<vector<int>> mat(n,vector<int>(n));
        while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++){
            mat[top][i] = num;
            num++;
        }
        top++;
        for(int i=top;i<=bottom;i++){
            mat[i][right] = num;
            num++;
        }
        right--;

        if(top<=bottom){
            for(int i=right;i>=left;i--){
                mat[bottom][i] = num;
                num++;
            }
            bottom--;
        }

        if(left<=right){
            for(int i=bottom;i>=top;i--){
                mat[i][left] = num;
                num++;
            }
            left++;
            }
        }

        return mat;
    }
};