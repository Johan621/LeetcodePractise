class Solution {
private:
    void backtrack(vector<int>& nums,vector<int>& path,vector<vector<int>>& ans,vector<bool>& used){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i] == true) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums,path,ans,used);

            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> path;
        vector<bool> used(n,false);
        vector<vector<int>> ans;
        backtrack(nums,path,ans,used);
        return ans;
    }
};