/*
There are N children standing in a line.Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements :

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give ?
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
	int candy(vector<int> &ratings) {
		if (ratings.size() == 0)
			return 0;
		if (ratings.size() == 1)
			return 1;

		vector<int> candyNum(ratings.size(), 1);

		//��һ��
		if (ratings[0] > ratings[1]){
			candyNum[0] += 1;
		}
		//�м���Щ
		for (int i = 1; i < ratings.size() - 1; ++i){
			//��ǰ��ıȽ�
			if (ratings[i] >= ratings[i - 1]){
				candyNum[i] = ratings[i] > ratings[i - 1] ? candyNum[i - 1] + 1 : 1;
			}
			//�����ıȽ�
			if (ratings[i] > ratings[i + 1]){
				int start = i, end = i;
				for (; (end < ratings.size() - 1) && (ratings[end] > ratings[end + 1]); ++end);
				i = end;
				--end;
				for (; end >= start; --end)
					candyNum[end] = max(candyNum[end + 1] + 1, candyNum[end]);
				adjustCandyNum(start, ratings, candyNum);
			}
		}
		
		//���һ��
		int l = ratings.size() - 1;
		if (ratings[l] >= ratings[l - 1]){
			candyNum[l] = ratings[l] > ratings[l - 1] ? candyNum[l - 1] + 1 : 1;
		}
		return accumulate(candyNum.begin(), candyNum.end(), 0);
	}
private:
	void adjustCandyNum(int, const vector<int>&, vector<int>&);
};

void Solution::adjustCandyNum(int i, const vector<int> &ratings, vector<int> &candyNum){
	while (i > 0 && ratings[i] < ratings[i - 1]){
		if (candyNum[i] < candyNum[i - 1])
			break;
		candyNum[i - 1] = candyNum[i] + 1;
		--i;
		continue;
	}
}

int main(){
	vector<int> ratings;
	/*for (int i = 1; i < 3; ++i)
		ratings.push_back(i);*/
	ratings.push_back(2);
	ratings.push_back(2);
	ratings.push_back(1);
	/*ratings.push_back(2);
	*/
	Solution sol;
	cout << sol.candy(ratings);
	return 0;
}