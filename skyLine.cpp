#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

struct Edge{
	int x;
	int height;
	bool left;

	Edge(int _x, int _height, bool _left):x(_x),height(_height),left(_left){}
	bool operator<(const Edge & p)
	{
		return this->x < p.x;
	}

};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<Edge> points;
		for(const vector<int> &building : buildings)
		{
			points.push_back(Edge(building[0], building[2], true));
			points.push_back(Edge(building[1], building[2], false));
		}

		sort(points.begin(), points.end());

		//map<height, count>
		map<int, int> dict;
		int h = 0;;
		vector<pair<int, int>> rst;
		for(int i = 0; i < points.size(); i++)
		{
			while(i < (points.size() - 1) && points[i].x == points[i+1].x)
			{
				if(points[i].left)
				{
					dict[points[i].height]++;
				}else
				{
					dict[points[i].height]--;
					if(0 == dict[points[i].height])
						dict.erase(points[i].height);
				}
				i++;
			}

			if(points[i].left)
			{
				dict[points[i].height]++;
			}else
			{
				dict[points[i].height]--;
				if(0 == dict[points[i].height])
					dict.erase(points[i].height);
			}

			int newH = dict.size() ? dict.rbegin()->first : 0;
			if(h != newH)
			{
				h = newH;
				rst.push_back(make_pair(points[i].x, h));
			}
		}

		return rst;
    }
};

int main()
{
	return 0;
}