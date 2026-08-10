class Solution {
private:
    void backtrack(int idx,vector<int>& path,vector<vector<int>>& ans,vector<int>& candidates,int target,int k){
        if(target == 0 && path.size() == k){
            ans.push_back(path);
            return;
        }
        if(target<0 || path.size()>k) return;
        for(int i=idx;i<candidates.size();i++){
            if(candidates[i]>target){
                break;
            }
            path.push_back(candidates[i]);
            backtrack(i+1,path,ans,candidates,target-candidates[i],k);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i=1;i<=9;i++){
            nums.push_back(i);
        }
        vector<int> path;
        vector<vector<int>> ans;
        backtrack(0,path,ans,nums,n,k);
        return ans;
    }
};