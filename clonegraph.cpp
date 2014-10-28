/*Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
*
*
*OJ's undirected graph serialization:
*Nodes are labeled uniquely.
*
*We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
*As an example, consider the serialized graph {0,1,2#1,2#2,2}.
*
*The graph has a total of three nodes, and therefore contains three parts as separated by #.
*
*First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
*Second node is labeled as 1. Connect node 1 to node 2.
*Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
*Visually, the graph looks like the following:
*
*       1
*      / \
*     /   \
*    0 --- 2
*         / \
*         \_/
*/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct UndirectedGraphNode{
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x){};
};

class Solution{
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node){
		if(!node) return NULL;

		UndirectedGraphNode *cloneNode =new UndirectedGraphNode(node->label);
		visited[node] = cloneNode;
		//visited.insert(node);
		cloneNeighbors(node, cloneNode);

		return cloneNode;
	}
private:
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
	//unordered_set<UndirectedGraphNode*> visited;
private:
	void cloneNeighbors(UndirectedGraphNode*&, UndirectedGraphNode*&);
};

void Solution::cloneNeighbors(UndirectedGraphNode* &node, UndirectedGraphNode* &cloneNode){
	for(auto iter = node->neighbors.begin(); iter != node->neighbors.end(); iter++){
		if(visited.find(*iter) != visited.end()){
			cloneNode->neighbors.push_back(visited[*iter]);
			continue;
		}
		UndirectedGraphNode *tem = new UndirectedGraphNode((*iter)->label);
		//visited.insert(*iter);
		visited[*iter] = tem;
		cloneNeighbors(*iter, tem);
		cloneNode->neighbors.push_back(tem);
	}
}

int main(){
	return 0;
}
