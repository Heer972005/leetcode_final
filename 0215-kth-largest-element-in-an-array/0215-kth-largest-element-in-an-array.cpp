class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        return quickSelect(nums, 0, nums.size() - 1, target);
    }

private:
    int quickSelect(vector<int>& nums, int left, int right, int target) {
        if (left == right)
            return nums[left];

        int pivot = nums[right];

        int lt = left;
        int i = left;
        int gt = right;

        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[lt]);
                lt++;
                i++;
            } 
            else if (nums[i] > pivot) {
                swap(nums[i], nums[gt]);
                gt--;
            } 
            else {
                i++;
            }
        }

        if (target < lt)
            return quickSelect(nums, left, lt - 1, target);

        if (target > gt)
            return quickSelect(nums, gt + 1, right, target);

        return pivot;
    }
};