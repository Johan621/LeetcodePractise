class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for(int i=0;i<s.length();i++){
            if(!stk.empty() && s[i] == stk.top()){
                stk.pop();
            }else{
                stk.push(s[i]);
            }
        }
        string res = "";
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};