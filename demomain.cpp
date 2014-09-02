#include "perputation.h"

int main()
{
	perputation per;
	std::vector<int> sequence;
	for (int i = 0; i < 3; i++)
		sequence.push_back(i);
	std::vector<std::vector<int>> perputSet = per.perput(sequence);

	return 0;
}