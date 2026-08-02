class Solution {
public:
    int titleToNumber(string columnTitle) {
        int num = 0;
        for(int i=0;i<columnTitle.length();i++){
            num = num*26 + (columnTitle[i]-'A' + 1);
        }
        return num;
    }
};