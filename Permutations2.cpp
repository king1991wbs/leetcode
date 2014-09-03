#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());

		vector<vector<int>> perputSet;
		vector<int> tem;

		if (num.size() == 0) return perputSet;

		_aux_perput(num, tem, perputSet);

		return perputSet;
		}
private:
	void _aux_perput(vector<int> num, vector<int> tem, vector<vector<int>> &perputSet);
};

void Solution::_aux_perput(vector<int> num, vector<int> tem, vector<vector<int>> &perputSet)
{
	if (num.size() == 1)
	{
		tem.push_back(num[0]);
		perputSet.push_back(tem);
		return;
	}

	for (auto iter = num.begin(); iter != num.end(); iter++)
	{
		if(num.begin() != iter && *num.begin() == *iter) continue;//相等是相同情况

		swap(*num.begin(), *iter);
		tem.push_back(*num.begin());
		//num.erase(num.begin());
		_aux_perput(vector<int>(++num.begin(), num.end()), tem, perputSet);
		tem.pop_back();
	}
}


int  main()
{
	vector<int> num;
	for(int i = 1; i < 4; i ++)
		num.push_back(i);
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);

	Solution sol;
	sol.permuteUnique(num);
	return 0;
}