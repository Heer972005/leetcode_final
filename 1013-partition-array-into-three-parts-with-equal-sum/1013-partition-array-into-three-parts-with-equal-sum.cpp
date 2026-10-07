class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int tSum=0;
        for(int num:arr){
            tSum+=num;
        }
        if(tSum%3!=0)
            return false;
        int trg=tSum/3;
        int currSum=0;
        int c=0;
        for(int num:arr){
            currSum+=num;
            if(currSum==trg){
                currSum=0;
                c++;
            }
        }
        return c>=3;
    }
};