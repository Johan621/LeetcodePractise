class Solution {
private:
    bool miniforce(vector<int>& nums,int dist,int k){
        int lastplaced = nums[0];
        int cnt = 1;
        for(int i=1;i<nums.size();i++){
            if((nums[i]-lastplaced) >= dist){
                lastplaced = nums[i];
                cnt++;
            }
        }
        return cnt>=k;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int low = 1,high = position[n-1] - position[0];
        while(low<=high){
            int mid = low + (high-low)/2;
            if(miniforce(position,mid,m) == true){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low-1;
    }
};