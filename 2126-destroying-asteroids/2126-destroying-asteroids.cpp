class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        //mass--original mass of planet
        //asteroids--asteroid[i]--weight of ith asteroid
        sort(asteroids.begin(),asteroids.end());
        long long currMass=mass;
        //reverse(asteroids.begin(),asteroids.end());
        int k=0;
        for(int i=0;i<asteroids.size();i++){
            if(currMass>=asteroids[i]){
                currMass+=asteroids[i];
                k++;
            }
        }
        if(k==asteroids.size()){
            return true;
        }
        return false;
    }
};