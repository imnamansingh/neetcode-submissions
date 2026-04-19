class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char,int> m;
        int ans = 0;
        int tempans = 0;
        int last = -1;
        for(int i = 0;i<s.length();i++){
            char sample = s[i];
            if(m.find(sample) == m.end() || m[sample] < last){
                tempans++;
                m[sample] = i;
            }else{
                // if(m.find(sample) != m.end() && m[sample] > last){
                    last = m[sample];
                    m[sample] = i;
                    ans = max (ans, tempans);
                    tempans = i-last;
                // }
            }
        }
        return max(ans,tempans);
    }
};
