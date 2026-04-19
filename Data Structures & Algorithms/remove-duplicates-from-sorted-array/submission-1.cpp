class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it = unique(nums.begin(),nums.end());
        return (it-nums.begin());

    }
};