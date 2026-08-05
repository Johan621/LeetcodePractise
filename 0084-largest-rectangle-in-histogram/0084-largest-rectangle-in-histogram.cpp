class Solution {
private:
    vector<int> prevsmaller(int n,vector<int>& heights){
        stack<int> stk;
        vector<int> prevsmall(n);
        for(int i=0;i<n;i++){
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            if(stk.empty()){
                prevsmall[i] = -1;
            }else{
                prevsmall[i] = stk.top();
            }
            stk.push(i);
        }
        return prevsmall;
    }
    vector<int> nextsmaller(int n,vector<int>& heights){
        stack<int> stk;
        vector<int> nextsmall(n);
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            if(stk.empty()){
                nextsmall[i] = n;
            }else{
                nextsmall[i] = stk.top();
            }
            stk.push(i);
        }
        return nextsmall;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev = prevsmaller(n,heights);
        vector<int> next = nextsmaller(n,heights);
        int max_area = 0;
        for(int i=0;i<n;i++){
            int width = next[i] - prev[i] -1;
            max_area = max(max_area,width*heights[i]);
        }
        
        return max_area;
    }
};