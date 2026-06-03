class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = nums[0];
        int cur = 0;
        for (int& n: nums) {
            if (cur < 0) cur = 0;
            cur += n;
            maximum = max(maximum, cur);
        }
        return maximum;
    }
};
