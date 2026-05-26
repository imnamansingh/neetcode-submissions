class Solution {
public:
    bool canSplit(const vector<int>& nums, int k, int maxCapacity) {
        int subarrayCount = 1;
        int currentSum = 0;
        
        for (int num : nums) {
            if (currentSum + num > maxCapacity) {
                subarrayCount++;
                currentSum = num;
                
                if (subarrayCount > k) {
                    return false;
                }
            } else {
                currentSum += num;
            }
        }
        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        
        for (int num : nums) {
            low = max(low, num); // Fix: Low bound must be the maximum single element
            high += num;         // High bound is the sum of all elements
        }
        
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canSplit(nums, k, mid)) {
                ans = mid;        // 'mid' is feasible, save it
                high = mid - 1;   // Try to find a smaller maximum sum
            } else {
                low = mid + 1;    // 'mid' is too small, increase capacity
            }
        }
        
        return ans;
    }
};