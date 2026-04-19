class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0;
        int end = heights.size()-1;
        int ans = 0;
        while(end>start){
            ans = max(ans, (end-start)*(min(heights[end],heights[start])));
            if(heights[end]<heights[start])end--;
            else start++;
        }
        return ans;
    }
};
