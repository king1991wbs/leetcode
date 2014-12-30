//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//getMin() -- Retrieve the minimum element in the stack.
//
#include <iostream>
#include <deque>
#include <climits>

using namespace std;

class MinStack {
public:
    void push(int x) {
	if(minData.empty() || minData.back() >= x)
		minData.push_back(x);
	data.push_back(x);
    }

    void pop() {
	if(data.back() == minData.back())
		minData.pop_back();
	data.pop_back();
    }

    int top() {
        return data.back();
    }

    int getMin() {
         return minData.back();
    }
private:
    deque<int> data,minData;
};

int main(){
	deque<int> d;
	d.push_back(12);
	cout << d.back() << endl;
	MinStack ms;
	ms.push(1);
	ms.push(1);
	ms.pop();
	cout << ms.top();
	cout << ms.getMin();
	return 0;
}
