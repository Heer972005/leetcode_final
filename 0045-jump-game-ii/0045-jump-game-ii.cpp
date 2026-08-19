class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]==0&&n==1){
            return 0;
        }
        int maxR=0;
        int currR=0;
        int jump=0;

        for(int i=0;i<n;i++){
            maxR=max(maxR,nums[i]+i);
            if(maxR>=n-1&&n!=1)
                return jump+1;
            if(currR==i){
                if(i==maxR)
                    return 0;
                else{
                    jump++;
                    currR=maxR;
                }
            }
        }
        return 0;
    }
};