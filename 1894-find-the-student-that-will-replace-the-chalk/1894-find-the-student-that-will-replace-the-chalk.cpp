class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // int i=0;
        int n=chalk.size();
        // int idx=-1;
        // while(k!=0){
        //     if(i<n){
        //         k=k-chalk[i];
        //         if(k==0){ 
        //             if(i==n-1){
        //                 idx=0;
        //             }
        //             else{
        //                 idx=i++;
        //             }
        //             }
        //         i++;
        //     }
        //     else{
        //         i=0;
        //     }
        // }
        // return idx;
        long long ttl=0;
        for(int i=0;i<n;i++){
            ttl+=chalk[i];
        }
        long long rem=k%ttl;
        for(int i=0;i<n;i++){
            if(rem<chalk[i])
                return i;
            rem=rem-chalk[i];
        }
        return 0;
    }
};