class Solution {
public:
    int maxArea(vector<int>& height) {
        int mxArea=0;
        //int area;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            int l=j-i;
            int b=min(height[i],height[j]);
            mxArea=max(mxArea,l*b);
            if(height[i]<height[j])
                i++;
            else if(height[i]>height[j])
                j--;
            else{
                i++;
                j--;
            }
        }
        return mxArea;
    }
};