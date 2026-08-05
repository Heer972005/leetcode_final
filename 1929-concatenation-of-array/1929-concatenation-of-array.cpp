class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>temp(2*nums.size());
        int k=0;
        for(int i=0;i<nums.size();i++){
            temp[k]=nums[i];
            k++;
        }
        for(int i=0;i<nums.size();i++){
            temp[k]=nums[i];
            k++;
        }
        return temp;
    }
};