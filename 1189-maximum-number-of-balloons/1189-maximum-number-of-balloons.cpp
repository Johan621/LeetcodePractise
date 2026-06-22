class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> freq;
        for(char ch:text){
            freq[ch]++;
        }
        return min({freq['b'],freq['a'],freq['n'],freq['l']/2,freq['o']/2});
    }
};