class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        long long factor = 1;
        int count = 0;
        while(left!=0 && right!=0 && (left!=right)){
            
            left >>=1;
            right >>=1;
            count++;
        }
        if(left==0&&right!=0){
            ans = 0;
        }else{
            ans = left * pow(2, count);
        }
        return ans;
    }
};