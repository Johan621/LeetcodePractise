class Solution {
private:
    static bool comp(vector<int>& p1,vector<int>& p2){
        return p1[1] < p2[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        int cnt = 1;
        int lastendtime = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=lastendtime){
                cnt++;
                lastendtime = intervals[i][1];
            }
        }
        return n-cnt;
    }
};