class Solution {
private:
    void backtracking(int idx,vector<int>& arr,vector<int>& v,vector<vector<int>>& ans){
        if(idx == arr.size()){
            ans.push_back(v);
            return;
        }
        //pick
        v.push_back(arr[idx]);
        backtracking(idx+1,arr,v,ans);

        //not pick
        v.pop_back();
        backtracking(idx+1,arr,v,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        backtracking(0,nums,v,ans);
        return ans;
    }
};