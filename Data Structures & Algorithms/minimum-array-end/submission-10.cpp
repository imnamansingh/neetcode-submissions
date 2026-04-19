class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = 0;
        int countx = 0;
        int countn = 0;
        int base = n-1;
        long long shift = 1;
        for(;countx<32;countx++){
            if(!((x>>countx)&1)){
                if(((base>>countn)&1)){
                    ans = ans | (shift<<countx);
                    
                }
                countn++;
            }else{
                ans = ans | (shift<<countx);
            }
        }
        while(base>>countn){
            if(((base>>countn)&1)){
                    ans = ans | (shift<<countx);
                    
                    
                }
                countn++;
                countx++;
        }
        return ans;
            
       

        
    }
};