class Solution {
public:
    double myPow(double x, int n) {
        long long temp = n;
        double ans = 1;
        if(temp<0){
            temp = abs(temp);
            x = 1/x;
        }
        
        while(temp){
            if(temp%2==1){
                ans*= x;
            }
            
            x*=x;
            temp/=2;
        }
        return ans;
    }
};
