class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i = 0;i<nums.size()-2;i++){
            for(int j = i+1;j<nums.size()-1;j++){
                int net = nums[i]+nums[j];
                for(int k = j+1;k<nums.size();k++){
                    if((net+nums[k])==0){
                        ans.push_back({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }
        for(int i = 0;i<ans.size();i++){
            sort(ans[i].begin(),ans[i].end());
        }
        sort(ans.begin(),ans.end());
        vector<vector<int>> ansR;
        if(ans.size()){
            ansR.push_back(ans[0]);
        }
        
        for(int i = 1;i<ans.size();i++){
            if((ans[i][0]==ans[i-1][0])&&(ans[i][1]==ans[i-1][1])&&(ans[i][2]==ans[i-1][2])){
                continue;
            }
            ansR.push_back(ans[i]);
        }
        return ansR;
    }
};
