class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum = 0;
        long long prod = 1;
        long long orig = n;
        while(orig>0){
            sum += orig%10;
            prod *= (orig%10);
            orig = orig/10;
        }
        if(n%(sum+prod) == 0) return true;
        return false;
    }
};