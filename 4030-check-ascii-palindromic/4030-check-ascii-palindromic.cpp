class Solution {
public:
    bool isPalindromic(string s) {
        string bin;
        for(char ch:s){
            bin += bitset<8>(ch).to_string();
        }
        int i=0,j=bin.length()-1;
        while(i<j){
            if(bin[i] != bin[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};