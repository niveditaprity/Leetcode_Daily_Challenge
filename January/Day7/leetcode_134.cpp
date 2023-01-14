class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
     int lowest_index = 0;
     int totalGas = 0,totalCost = 0;
     int n = gas.size();
     int currGas = 0;
     for(int i = 0; i<n; i++)
     {
        totalGas += gas[i];
        totalCost += cost[i];
        currGas = currGas + gas[i] - cost[i];
        if(currGas < 0)
        {
            lowest_index = i+1;
            currGas = 0;
        }
     }
     if(totalGas >= totalCost)
     {
         return lowest_index;
     }
     return -1;
    }
};
