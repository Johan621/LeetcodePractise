class Solution {
public:
    void backtrack(int idx,vector<int>& path,vector<vector<int>>& ans,int k,int n){
        if(path.size() == k){
            ans.push_back(path);
            return;
        }
        for(int i=idx;i<=n;i++){
            
            path.push_back(i);
            backtrack(i+1,path,ans,k,n);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> ans;
        backtrack(1,path,ans,k,n);
        return ans;
    }
};