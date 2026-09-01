class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>arr;
        for(int i:nums){
            arr.push_back(to_string(i));
        }
        //lambda function
        sort(arr.begin(),arr.end(),[](const string &a,const string &b){
            return (b+a)<(a+b);
        });

        if(arr[0]=="0")
            return "0";
        
        string largest;
        for(string i:arr){
            largest+=i;
        }
        return largest;
    }
};