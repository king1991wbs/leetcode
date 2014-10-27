/*There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
*
*You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
*
*Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
*
*Note:
*The solution is guaranteed to be unique.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost){
		int N = gas.size();
		if(N == 0)
			return -1;

		int start = 0, end = 0;
		while(start < N){
			while(gas[start] < cost[start]){
				++start;
				if(start >= N)
					return -1;
			}
			
			int gashave = gas[start];
			int gascost = cost[start];
			for(end = start + 1; end % N != start; ++end){
				gashave += gas[end % N];
				gascost += cost[end % N];
				if(gashave < gascost){
					start = end + 1;
					break;
				}
			}
			if(end % N == start)
				return start;
		}
		return -1;
	}
};

int main(){
	vector<int> gas;
	vector<int> cost;
	Solution sol;
	cout << sol.canCompleteCircuit(gas, cost);
	return 0;
}
