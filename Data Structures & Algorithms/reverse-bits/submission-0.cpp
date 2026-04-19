class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int count = 1;
        while(count<=32){
            res<<=1;
            res = (res | (n&1));
            n>>=1;
            count++;
        }
        return res;
    }
};
