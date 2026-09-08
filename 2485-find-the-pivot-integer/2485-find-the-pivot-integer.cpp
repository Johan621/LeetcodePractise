class Solution {
public:
    int pivotInteger(int n) {
        int total = (n*(n+1))/2;
        int sum1 = 0;
        for(int i=1;i<=n;i++){
            sum1 += i;
            int sum2 = total-sum1+i;
            if(sum1 == sum2) return i;
        }
        return -1;
    }
};