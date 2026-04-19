class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i = 0;i<nums.size()-3;i++){
            if(i&&(nums[i]==nums[i-1])) continue;
            for(int j = i+1;j<nums.size()-2;j++){
                if((j>(i+1))&&(nums[j]==nums[j-1])) continue;
                int start = j+1;
                int end = nums.size()-1;
                while(start<end){
                    long long sum = 1ll*nums[i]+1ll*nums[j]+1ll*nums[start]+1ll*nums[end];
                    
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[start],nums[end]});
                        while(nums[start]==nums[start+1])start++;
                        while(nums[end]==nums[end-1])end--;
                        start++;
                        end--;
                    }else if(sum>target){
                        end--;
                    }else{
                        start++;
                    }
                }
            }
        }
        
        return ans;
    }
};