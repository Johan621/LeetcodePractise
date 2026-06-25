class Solution {
public:
    int hammingDistance(int x, int y) {
        int xr = x^y;
        int cnt = 0;
        while(xr){
            xr = xr&(xr-1);
            cnt++;
        }
        return cnt;
    }
};