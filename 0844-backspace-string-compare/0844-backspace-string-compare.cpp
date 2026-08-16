class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk1,stk2;
        for(int i=0;i<s.length();i++){
            if(s[i] == '#'){
                if(!stk1.empty()){
                    stk1.pop();
                }
            }else{
                stk1.push(s[i]);
            }
        }
        for(int i=0;i<t.length();i++){
            if(t[i] == '#'){
                if(!stk2.empty()){
                    stk2.pop();
                }
            }else{
                stk2.push(t[i]);
            }
        }
        while(stk1.size() && stk2.size()){
            if(stk1.top() != stk2.top()){
                return false;
            }
            stk1.pop();
            stk2.pop();
            
        }
        if(!stk1.empty() || !stk2.empty()) return false;
        return true;
    }
};