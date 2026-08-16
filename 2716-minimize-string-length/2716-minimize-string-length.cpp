class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> st;
        for(int i=0;i<s.length();i++){
            st.insert(s[i]);
        }
        return st.size();
    }
};