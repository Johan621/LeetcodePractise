class Solution {
private:
    bool validbouquet(vector<int>& bloomDay,int days,int m,int k){
        int n = bloomDay.size();
        int bouquet = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=days){
                cnt++;
                if(cnt == k){
                    bouquet++;
                    cnt = 0;
                }
            }else{
                cnt = 0;
            }
        }
        return bouquet >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1LL*m*k>n) return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(validbouquet(bloomDay,mid,m,k) == true){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};