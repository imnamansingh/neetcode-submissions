class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            int toMatch = nums[i];
            int matchCount = 0;
            for(int j = 0;j<nums.size();j++){
                if(nums[j]==toMatch){
                    matchCount++;
                    if(matchCount == 2){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};