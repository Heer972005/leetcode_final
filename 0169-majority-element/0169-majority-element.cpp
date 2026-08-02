class Solution {
public:
    int helper(vector<int>& nums, int start, int end) {
        // Base case
        if (start == end) {
            return nums[start];
        }

        int mid = start + (end - start) / 2;

        int left = helper(nums, start, mid);
        int right = helper(nums, mid + 1, end);

        // If both halves agree
        if (left == right) {
            return left;
        }

        // Count occurrences of both candidates
        int lcount = 0, rcount = 0;

        for (int i = start; i <= end; i++) {
            if (nums[i] == left) {
                lcount++;
            } else if (nums[i] == right) {
                rcount++;
            }
        }

        return (lcount > rcount) ? left : right;
    }

    int majorityElement(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};