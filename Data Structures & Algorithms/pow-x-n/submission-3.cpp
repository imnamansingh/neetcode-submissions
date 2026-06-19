class Solution {
public:
    double myPow(double x, int n) {
        int temp = n;
        double ans = 1;
        if(temp<0){
            temp = abs(temp);
            x = 1/x;
        }
        
        while(temp){
            ans*= x;
            temp--;
        }
        return ans;
    }
};
