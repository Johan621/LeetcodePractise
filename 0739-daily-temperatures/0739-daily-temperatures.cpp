class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        long long n = temperatures.size();
        vector<int> ans(n);
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && temperatures[stk.top()]<=temperatures[i])
                stk.pop();
            if(stk.empty())
                ans[i] = 0;
            else
                ans[i] = stk.top()-i;
            stk.push(i);
        }
        return ans;
    }
};