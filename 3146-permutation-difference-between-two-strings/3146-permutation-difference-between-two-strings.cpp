class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char,int> freq;
        for(int i=0;i<s.size();i++){
            freq[s[i]] = i;
        }
        int sum = 0;
        for(int i=0;i<t.size();i++){
            if(freq.count(t[i])){
                sum += abs(i-freq[t[i]]);
            }
        }
        return sum;
    }
};