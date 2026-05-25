class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) { 
        int start = 1,end = INT_MIN;
        for(int i = 0;i<piles.size();i++){
            if(piles[i]<start) start = piles[i];
            if(piles[i]>end) end = piles[i];
        }

        while(start<end){
            int maxLimit = start + (end-start)/2;
            int count = 0;
            for(auto pile : piles){
                int count2 = pile/maxLimit;
                if(pile%maxLimit) count2++;
                count+=count2;

            }

            if(count>h){
                if(end == start+1){
                    start = end;
                    continue;
                }
                start = maxLimit;
            }else{
                end = maxLimit;
            }
        }
        return start;
        
    }
};
