class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        long long sum=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=n-2;i>=n/3;i-=2){
            sum+=nums[i];
        }
        return sum;
    } 
};