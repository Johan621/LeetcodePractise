class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n/2;
        int diff = 0;
        int lq = 0,rq = 0;
        for(int i=0;i<half;i++){
            if(num[i] == '?')
                lq++;
            else
                diff += num[i]-'0';
        }
        for(int i=half;i<n;i++){
            if(num[i] == '?')
                rq++;
            else
                diff -= num[i]-'0';
        }
        if((lq+rq)%2) return true;
        return diff != ((rq-lq)/2)*9;
    }
};