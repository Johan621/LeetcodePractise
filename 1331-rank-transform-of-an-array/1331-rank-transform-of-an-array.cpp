class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return {};
        vector<int> ans(arr.begin(),arr.end());
        sort(ans.begin(),ans.end());
        unordered_map<int,int> mp;
        int rank = 1;
        mp[ans[0]] = rank;
        for(int i=1;i<ans.size();i++){
            if(ans[i] != ans[i-1]){
                rank++;
            }
            mp[ans[i]] = rank; 
        }
        for(int i=0;i<arr.size();i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};