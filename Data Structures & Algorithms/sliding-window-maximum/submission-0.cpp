class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque <int> d;
        d.push_back(0);
        int i = 1;
        for(;i<k;i++){
            while(d.size() && nums[d.back()]<=nums[i]){
                d.pop_back();
            }
            d.push_back(i);

        }
        ans.push_back(nums[d.front()]);
        int right = i;
        while(right<nums.size()){
            if(d.front()<=(right-k)){
                d.pop_front();
            }
            while(d.size() && nums[d.back()]<=nums[right]){
                d.pop_back();
            }
            d.push_back(right++);
            ans.push_back(nums[d.front()]);

        }
        return ans;
    }
};
