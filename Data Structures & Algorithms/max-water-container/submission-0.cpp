class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        for(int i = 0;i<heights.size()-1;i++){
            for(int j = 0;j<heights.size();j++){
                int minn = min(heights[i],heights[j]);
                ans = max(ans, (j-i)*minn);
            }
        }
        return ans;
    }
};
