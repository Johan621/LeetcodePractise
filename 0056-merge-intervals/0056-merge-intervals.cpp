class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> mergeintervals;
        vector<int> tempinterval = intervals[0];
        for(auto it:intervals){
            if(it[0] <= tempinterval[1]){
                tempinterval[1] = max(it[1],tempinterval[1]);
            }else{
                mergeintervals.push_back(tempinterval);
                tempinterval = it;
            }
        }
        mergeintervals.push_back(tempinterval);
        return mergeintervals;
    }
};