class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int currentSum = 0;
        int length = 0;
        int left = 0,right = 0;
        int ans = INT_MAX;

        while(right<nums.size()){
            if(currentSum<target){
                currentSum += nums[right++];
                length++;
            }
            
            if(currentSum>=target){
                ans = min(ans,length);
                while(currentSum>=target && left<right){
                    ans = min(ans,length);
                    currentSum -= nums[left++];
                    length--;

                }
            }
            
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};