class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total = 0;
        int n = arr.size();
        for(int num:arr){
            total += num;
        }
        if(total%3 != 0) return false;
        int target = total/3;
        int pre = 0;
        int partitionscnt = 0;
        for(int i=0;i<n;i++){
            pre += arr[i];
            if(pre == target){
                partitionscnt++;
                pre = 0;
                if(partitionscnt == 2 && i<arr.size()-1){
                    return true;
                }
            }
        }
        return false;
    }
};