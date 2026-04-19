class Solution {
public:
    int reverse(int x) {
        
        long long ans  = 0;
        while(x){
            int tomul = x%10;
            ans *=10;
            ans += (tomul);
            if(ans<INT_MIN || ans>INT_MAX){
                return 0;
            }
            
            x/=10;
        }
        int anss = ans;
        return ans;
        
    }
};
