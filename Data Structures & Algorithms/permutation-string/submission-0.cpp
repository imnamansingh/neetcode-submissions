class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()) return false;
        vector<int> v1(26), v2(26);
        int i = 0;
        for(;i<s1.length();i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        if(v1==v2) return true;
        while(i<s2.length()){
            v2[s2[i-s1.length()]-'a']--;
            v2[s2[i]-'a']++;
            if(v1==v2) return true;
            i++;
        }

        return false;
    }
};
