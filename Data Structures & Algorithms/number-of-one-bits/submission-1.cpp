#include <cstdint>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        uint32_t bitm = 1;
        int count = 1;
        while(count<=32){
            if((n&bitm)==bitm){
                ans++;
            }
            count++;
            if(count<=32)bitm*=2;
        }
        return ans;
        
        
        
        
    }
};
