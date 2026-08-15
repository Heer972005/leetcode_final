// class Solution {
// public:
//     int countElements(vector<int>& nums, int k) {
//         int count=0;
//         if(k==0){
//             return nums.size();
//         }
//         for(int i=0;i<nums.size();i++){
//             int n=nums[i];
//             int c=0;
//             for(int j=0;j<nums.size();j++){
//                 if(nums[i]<nums[j]){
//                     c++;
//                     if(c==k){
//                         count++;
//                         break;
//                     }
//                 }
//             }
//         }
//         return count;
//     }
// };
class Solution {
public:

    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;

        int i = low;
        int j = mid + 1;

        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while (j <= high) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            nums[low + k] = temp[k];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        // Divide
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);

        // Combine
        merge(nums, low, mid, high);
    }

    int countElements(vector<int>& nums, int k) {

        if (k == 0)
            return nums.size();

        int n = nums.size();

        // Divide and conquer sorting
        mergeSort(nums, 0, n - 1);

        // k-th largest element
        int threshold = nums[n - k];

        int count = 0;

        for (int x : nums) {
            if (x < threshold)
                count++;
        }

        return count;
    }
};
