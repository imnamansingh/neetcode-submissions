class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int max = 0, min = INT_MAX, ans = INT_MAX;
        for(auto num : nums){
            max += num;
            if(num<min) min = num;
        }
        ans = max;
        while(min<max){
            int mid = min + (max-min)/2;
            int count = 1;
            int tempSum = 0;
            int maxSum = INT_MIN;
            for(auto num: nums){
                if((tempSum + num)>mid){
                    count++;
                    tempSum = num;
                }else{
                    tempSum += num;
                    
                }
                if(tempSum>maxSum) maxSum = tempSum;
            }
            if(count>k){
                
                min = mid + 1;
            }else if(count<k){
                max = mid;
            }else{
                if(ans>maxSum) ans = maxSum;
                max = mid;
            }
        }
        return ans;


    }
};