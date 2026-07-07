class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long rem = 0;
        while(n>0){
            int digit = n%10;
            sum += digit;
            if(digit != 0){
                rem = rem*10 + digit;
            }
            n /= 10;
        }
        long long rem2 = 0;
        while(rem>0){
            int digit = rem%10;
            rem2 = rem2*10+digit;
            rem /= 10;
        }
        return rem2*sum;
    }
};