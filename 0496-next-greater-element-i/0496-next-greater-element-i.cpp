class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int,int> mp;
        stack<int> stk;
        for(int i=m-1;i>=0;i--){
            while(!stk.empty() && stk.top()<nums2[i])
                stk.pop();
            if(stk.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = stk.top();
            stk.push(nums2[i]);
        }
        vector<int> ans;
        for(int x:nums1){
            ans.push_back(mp[x]);
        }

        return ans;
    }
};