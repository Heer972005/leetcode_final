class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums,0,nums.size()-1);
    }
    int maxSubArray(vector<int>&a,int l,int r){
        if(l>r) return INT_MIN;
        int mid=(l+r)/2,ls=0,rs=0;
        for(int i=mid-1,cursum=0;i>=l;i--)
        {cursum+=a[i];
        ls=max(ls,cursum);}
        for(int i=mid+1,cursum=0;i<=r;i++)
        {cursum+=a[i];
        rs=max(rs,cursum);}
        return max({maxSubArray(a,l,mid-1),maxSubArray(a,mid+1,r),ls+a[mid]+rs});
    }
};