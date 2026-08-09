class Solution {
private:
    void backtrack(int idx,vector<int>& candidates,int target,vector<int>& path,vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(path);
            return;
        }
        if(target<0){
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(candidates[i]>target){
                break;
            }
            if(i>idx && candidates[i] == candidates[i-1]){
                continue;
            }

            path.push_back(candidates[i]);
            backtrack(i+1,candidates,target-candidates[i],path,ans);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        vector<vector<int>> ans;
        backtrack(0,candidates,target,path,ans);
        return ans;
    }
};