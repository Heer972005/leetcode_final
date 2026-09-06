class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        if(target==1)return 0;
        int c=0;
        if(target%2==1){
            c++;
            target=target-1;
        }
        while(maxDoubles>0&&target>1){
            if(target%2==0){
                target=target/2;
                c++;
                maxDoubles--;
            }
            else{
                c++;
                target--;
            }
        }
        if(target>1){
            c=c+(target-1);
        }
        return c;
    }
};