#include "perputation.h"


std::vector<std::vector<int>>  perputation::perput(std::vector<int> sequence)
{
	std::vector<std::vector<int>> perputSet;
	std::vector<int> tem;

	if (sequence.size() == 0) return perputSet;

	_aux_perput(sequence, tem, perputSet);

	return perputSet;
}

void perputation::_aux_perput(std::vector<int> sequence, std::vector<int> tem, std::vector<std::vector<int>> &perputSet)
{
	if (sequence.size() == 1)
	{
		tem.push_back(sequence[0]);
		perputSet.push_back(tem);
		return;
	}

	for (auto iter = sequence.begin(); iter != sequence.end(); iter++)
	{
		
		std::swap(*sequence.begin(), *iter);
		tem.push_back(*sequence.begin());
		//sequence.erase(sequence.begin());
		_aux_perput(std::vector<int>(++sequence.begin(), sequence.end()), tem, perputSet);
		tem.pop_back();
	}
}


