class Solution {
private:
    bool selfdivide(int num){
        string s = to_string(num);
        for(int i=0;i<s.length();i++){
            if((s[i]-'0') == 0 || num%(s[i]-'0') != 0) return false;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> arr;
        for(int i=left;i<=right;i++){
            if(selfdivide(i)){
                arr.push_back(i);
            }
        }
        return arr;
    }
};