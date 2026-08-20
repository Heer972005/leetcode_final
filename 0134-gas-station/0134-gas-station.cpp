class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int tank=0;//totl gas
        int leftGas=0;//curr gas
        int tcost=0;
        int strt=0;
        for(int i=0;i<n;i++){
            tank=tank+gas[i];
            tcost=tcost+cost[i];
            leftGas=leftGas+gas[i]-cost[i];
            if(leftGas<0){
                strt=i+1;
                leftGas=0;
            }
        }
        return (tank<tcost)?-1:strt;
    }
};

// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();

//         for(int start = 0; start < n; start++) {

//             int tank = 0;
//             bool possible = true;

//             for(int step = 0; step < n; step++) {

//                 int current = (start + step) % n;

//                 tank += gas[current];
//                 tank -= cost[current];

//                 if(tank < 0) {
//                     possible = false;
//                     break;
//                 }
//             }

//             if(possible)
//                 return start;
//         }

//         return -1;
//     }
// };