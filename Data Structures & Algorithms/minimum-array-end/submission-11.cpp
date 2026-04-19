class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = 0;
        int countx = 0;
        int countn = 0;
        int base = n-1;
        
        for(;countx<32;countx++){
            if(!((x>>countx)&1)){
                if(((base>>countn)&1)){
                    ans = ans | (1ll<<countx);
                    
                }
                countn++;
            }else{
                ans = ans | (1ll<<countx);
            }
        }
        while(base>>countn){
            if(((base>>countn)&1)){
                    ans = ans | (1ll<<countx);
                    
                    
                }
                countn++;
                countx++;
        }
        return ans;
            
       

        
    }
};