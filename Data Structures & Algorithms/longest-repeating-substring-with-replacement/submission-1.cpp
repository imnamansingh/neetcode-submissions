class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        for(int i = 0;i<26;i++){
            char target = 'A' + i;
            int left = 0, right = 0, count = 0;
            while(right<s.length()){
                if(s[right] == target){
                    right++;
                }else{
                    if(count<k){
                        right++;
                        count++;
                    }else{
                        while(s[left] == target && left < right){
                            left++;
                        }
                        left++;
                        count--;

                    }
                }
                ans = max(ans, right-left);
            }
        }
        return ans;
    }
};
