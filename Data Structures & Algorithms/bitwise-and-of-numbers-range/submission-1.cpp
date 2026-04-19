class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        long long factor = 1;
        while(left!=0 && right!=0){
            if((left&1)==(right&1)){
                if(left&1){
                    ans+= factor;
                }
            }else{
                ans = 0;
            }
            factor*=2;
            left >>=1;
            right >>=1;
        }
        if(left==0&&right!=0){
            ans = 0;
        }
        return ans;
    }
};