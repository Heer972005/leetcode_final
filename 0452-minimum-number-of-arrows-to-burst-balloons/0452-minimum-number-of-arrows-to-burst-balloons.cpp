class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)return 0;
        sort(points.begin(),points.end());
        int arrows=1;
        int lstE=points[0][1];
        for (int i = 1; i < points.size(); i++) {
            int currStart = points[i][0];
            int currEnd = points[i][1];

            if (currStart <= lstE) {
                lstE = min(lstE, currEnd);
            } else {
                arrows++;
                lstE = currEnd;
            }
        }
        return arrows;
    }
};