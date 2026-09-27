class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == ')') {
                string temp;

                // Pop until '('
                while (st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }

                // Remove '('
                st.pop();

                // temp is already reversed
                for (char ch : temp) {
                    st.push(ch);
                }
            } 
            else {
                st.push(c);
            }
        }

        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

