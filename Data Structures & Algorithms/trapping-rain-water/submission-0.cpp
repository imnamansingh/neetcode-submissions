class Solution {
public:
    int solveLeft(vector<int>& height, int end){
        if(end<=0) return 0;
        int big = end-1;
        int ans = 0;
        for(int i = end-2;i>=0;i--){
            if(height[i]>=height[big]){
                big = i;
            }
        }
        for(int i = big+1;i<end;i++){
            ans += height[big]-height[i];
        }
        ans += solveLeft(height, big);
        return ans;

    }
    int solveRight(vector<int>& height, int start){
        if(start>=(height.size()-1)) return 0;
        int big = start+1;
        int ans = 0;
        for(int i = start+2;i<height.size();i++){
            if(height[i]>=height[big]){
                big = i;
            }
        }
        for(int i = start+1;i<big;i++){
            ans += height[big]-height[i];
        }
        ans += solveRight(height, big);
        return ans;
    }
    int trap(vector<int>& height) {
        int big1,big2;
        if(height[0]>height[1]){
            big1 = 0;
            big2 = 1;
        }else{
            big1 = 1;
            big2 = 0;
        }
        for(int i = 2;i<height.size();i++){
            if(height[i]>=height[big1]){
                big2 = big1;
                big1 = i;
            }else if(height[i]>height[big2]){
                big2 = i;
            }
        }
        int start = min(big1,big2);
        int end = max(big1,big2);
        int factor = min(height[big1],height[big2]);
        int ans = 0;
        ans += solveLeft(height, start);
        ans += solveRight(height, end);
        for( int i = start+1;i<end;i++){
            ans += factor-height[i];
        }
        return ans;

    }
};
