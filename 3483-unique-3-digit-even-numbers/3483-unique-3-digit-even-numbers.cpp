class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> unique_num;
        int n = digits.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j == i) continue;
                for(int k=0;k<n;k++){
                    if(k == i || k == j) continue;

                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                    if(digits[i] != 0 && digits[k] % 2 == 0){
                        unique_num.insert(num);
                    }
                }
            }
        }
        return unique_num.size();
    }
};