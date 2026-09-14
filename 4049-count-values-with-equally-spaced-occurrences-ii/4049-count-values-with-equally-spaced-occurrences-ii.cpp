class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        int ans = 0;
        for(auto& [key,pos]:mp){
            if(pos.size()<3)
                continue;
            int gap = pos[1]-pos[0];
            bool special = true;
            for(int i=2;i<pos.size();i++){
                if(pos[i]-pos[i-1] != gap){
                    special = false;
                    break;
                }
            }
            if(special){
                ans++;
            }
        }
        return ans;
    }
};