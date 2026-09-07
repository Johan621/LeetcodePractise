class Solution {
private:
    bool nozero(int n){
        while(n>0){
            int digit = n % 10;
            if(digit == 0) return false;
            n/=10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<=n;i++){
            if(nozero(i) && nozero(n-i)){
                return {i,n-i};
            }
        }
        return {};
    }
};