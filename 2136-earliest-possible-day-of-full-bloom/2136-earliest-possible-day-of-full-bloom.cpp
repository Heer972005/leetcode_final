class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<pair<int,int>>times(n);
        for(int i=0;i<n;i++){
            //for descending we store in negative
            times[i].first=-growTime[i];
            times[i].second=plantTime[i];
        }
        sort(times.begin(),times.end());
        int tot=0;
        int curr=0;
        for(int i=0;i<n;i++){
            tot=max(tot,curr+times[i].second-times[i].first);
            curr+=times[i].second;
        }
        return tot;
    }
};