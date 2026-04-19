class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> v = nums;
      sort(v.begin(), v.end());
      int i = 0, j = nums.size()-1;
      while(i<j){
        if((v[i]+v[j])==target){
            break;
        }else if((v[i]+v[j])>target){
            j--;
        }else{
            i++;
        }
      }
      vector<int> ans;
      bool flag = true;
      for(int k  = 0;k<nums.size();k++){
        if(flag && ((nums[k]==v[i])||(nums[k]==v[j]))){
            ans.push_back(k);
            flag = false;
            continue;
        }
        if(ans.size()!=0 &&nums[k]==(target-nums[ans[0]])){
            ans.push_back(k);
            break;
        }
         
         }

         return ans;
    }
};
