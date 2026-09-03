class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        int orig = num;
        if(num<0) num = abs(num);
        string res = "";
        while(num>0){
            res += to_string(num%7);
            num /= 7;
        }
        reverse(res.begin(),res.end());
        return (orig<0)?"-"+res:res;
    }
};