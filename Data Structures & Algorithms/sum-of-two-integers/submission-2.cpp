class Solution {
public:
    int getSum(int a, int b){
        unsigned int carry = 0;
        do{
            
            carry = (a&b)<<1;
            a = a^b;
            b = carry;
        }while(carry);

        return a;
    }
};
