class Solution {
public:
    int countInRange(vector<int>& nums, int num, int lo, int hi) {
        int count = 0;
        for (int i = lo; i <= hi; i++) {
            if (nums[i] == num)
                count++;
        }
        return count;
    }

    int majorityElementRec(vector<int>& nums, int lo, int hi) {
        // Base case
        if (lo == hi)
            return nums[lo];

        // Recursive calls
        int mid = lo + (hi - lo) / 2;

        int left = majorityElementRec(nums, lo, mid);
        int right = majorityElementRec(nums, mid + 1, hi);

        // If both halves agree
        if (left == right)
            return left;

        // Count occurrences of both candidates in current range
        int leftCount = countInRange(nums, left, lo, hi);
        int rightCount = countInRange(nums, right, lo, hi);

        return (leftCount > rightCount) ? left : right;
    }

    int majorityElement(vector<int>& nums) {
        return majorityElementRec(nums, 0, nums.size() - 1);
    }
};