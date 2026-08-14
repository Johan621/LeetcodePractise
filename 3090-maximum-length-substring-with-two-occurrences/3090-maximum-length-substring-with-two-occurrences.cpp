class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int maxi = 0;
        int i=0;
        int j=0;
        unordered_map<char,int> freq;
        while(j<n){
            freq[s[j]]++;
            while(freq[s[j]]>2){
                freq[s[i]]--;
                i++;
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};