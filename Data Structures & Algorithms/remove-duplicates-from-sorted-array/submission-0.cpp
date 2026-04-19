class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0;
        int end = 0;
        int count = 0;
        while(end<nums.size()-1){
            if(nums[end]==nums[end+1]){
                end++;
            }else{
                count++;
                swap(nums[start++],nums[end++]);
            }
        }
        swap(nums[start],nums[end]);
        
        return count+1;
    }
};