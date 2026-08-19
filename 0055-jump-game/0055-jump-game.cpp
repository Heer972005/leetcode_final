class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]==0&&n==1)
             return true;
        int maxR=0;
        int currR=0;
        int jump=0;
        for(int i=0;i<n;i++){
            maxR=max(maxR,nums[i]+i);
            if(maxR>=n-1)
                return true;
            if(currR==i){
                if(maxR==i)
                    return false;
                else{
                    jump++;
                    currR=maxR;
                }
            }
        }
        return false;
    }
};