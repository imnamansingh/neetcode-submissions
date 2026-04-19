class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        sort(people.begin(),people.end());
        int start = 0;
        int end = people.size()-1;
        while(end>start){
            int sum = people[end]+people[start];
            if(sum<=limit){
                start++;
            }
            count++;
            end--;
        }
        if(start==end) count++;
        return count;
        
    }
};