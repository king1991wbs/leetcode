#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution{
public:
	vector<int> twoSum(vector<int> &numbers, int target){
		vector<int> result;
		vector<int> _numbers(numbers.begin(), numbers.end());

		sort(numbers.begin(), numbers.end());

		int value1, value2;
		for(int i = 0; i < numbers.size(); ++i){
			auto j = find(numbers.begin() + i + 1, numbers.end(), target - numbers[i]);
			if(j != numbers.end()){
				value1 = numbers[i];
				value2 = *j;
				break;
			}
		}

		vector<int>::iterator index1, index2;
		if(value1 != value2){
			index1 = find(_numbers.begin(), _numbers.end(), value1);
			index2 = find(_numbers.begin(), _numbers.end(), value2);
		}
		else{
			index1 = find(_numbers.begin(), _numbers.end(), value1);
			index2 = find(index1 + 1, _numbers.end(), value2);
		}

		if (index1 < index2){
			result.push_back(distance(_numbers.begin(), index1) + 1);
			result.push_back(distance(_numbers.begin(), index2) + 1);
		}
		else{
			result.push_back(distance(_numbers.begin(), index2) + 1);
			result.push_back(distance(_numbers.begin(), index1) + 1);
		}
		return result;
	}
};

int main(){
	vector<int> numbers;
	numbers.push_back(0);
	numbers.push_back(4);
	numbers.push_back(3);
	numbers.push_back(0);

	Solution sol;
	sol.twoSum(numbers, 0);
	return 0;
}
