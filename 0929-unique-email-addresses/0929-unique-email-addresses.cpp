class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(string email:emails){
            int posidx = email.find('@');
            string local = email.substr(0,posidx);
            string domain = email.substr(posidx);
            string normalloc = "";
            for(char ch:local){
                if(ch == '+') break;
                if(ch != '.') normalloc += ch;
            }
            st.insert(normalloc + domain);
        }
        return st.size();
    }
};