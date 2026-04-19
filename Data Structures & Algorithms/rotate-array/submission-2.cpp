class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        vector<int> v;
        for(int i = 0;i<k;i++){
            v.push_back(nums[i]);
        }
        for(int i = nums.size()-1;i>=k;i--){
            nums[(i+k)%nums.size()] = nums[i];
        }
        for(int j=0;j<k;j++){
            nums[(j+k)%nums.size()] = v[j];
        }
    }
};