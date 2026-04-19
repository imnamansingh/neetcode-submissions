class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<multiset<int>> s;
        for(int i = 0;i<nums.size()-2;i++){
            for(int j = i+1;j<nums.size()-1;j++){
                int net = nums[i]+nums[j];
                for(int k = j+1;k<nums.size();k++){
                    if((net+nums[k])==0){
                        multiset<int> m;
                        m.insert(nums[i]);
                        m.insert(nums[j]);
                        m.insert(nums[k]);
                        s.insert(m);
                    }
                }
            }
        }
        
        vector<vector<int>> ans;
        for(auto item:s){
            vector<int> part;
            for(auto innerItem: item){
                part.push_back(innerItem);
            }
            ans.push_back(part);
        }
        
        return ans;
    }
};
