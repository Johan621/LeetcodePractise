class Solution {
private:
    void backtrack(int idx,vector<int>& candidates,int target,vector<int>& v,vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        if(target < 0){
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(candidates[i]>target){
                break;
            }

            v.push_back(candidates[i]);
            backtrack(i,candidates,target-candidates[i],v,ans);
            v.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        backtrack(0,candidates,target,path,ans);
        return ans;
    }
};