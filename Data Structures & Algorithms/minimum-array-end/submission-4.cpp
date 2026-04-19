class Solution {
public:
    long long minEnd(int n, int x) {
        string xx,nn;
        int lim = n-1;
        while(x!=0){
            xx.push_back((x&1) + '0');
            x >>= 1;
        }
        while(lim!=0){
            nn.push_back((lim&1) + '0');
            lim >>= 1;
        }
        for(int i = 0;i<xx.length();i++){

            if(i<nn.length()){
                if(xx[i]=='1'){
                    nn.insert(i,1, '1');
                }
                
            }else{
                nn.push_back(xx[i]);
            }
        }
        long long ans = 0;
        unsigned __int128 factor = 1;
        for(int i = 0;i<nn.length();i++){
            if(nn[i]=='1'){
                ans += factor;
            }
            factor<<=1;
        }
        return ans;

        
    }
};