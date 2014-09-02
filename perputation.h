#pragma once
#include <iostream>
#include <vector>

class perputation
{
public:
	perputation(){}
	~perputation(){}

	std::vector<std::vector<int>> perput(std::vector<int> sequence);
private:
	void _aux_perput(std::vector<int> sequence, std::vector<int> tem, std::vector<std::vector<int>> &perputSet);
};

