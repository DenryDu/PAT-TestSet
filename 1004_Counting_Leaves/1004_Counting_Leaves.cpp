#include <bits/stdc++.h>
using namespace std;
int levelCount[110];//used to store the result of each level
int levelFlag=0;//用来传递层级值，不过是传值，不是传引用，否则会导致逻辑错误 
int Max = 0;

typedef struct Tree{
	int nodeNum;
	int nonLeaf;
	int visited[110]={0};
	vector<int> childNode[110];
}Tree;
void InitTree(Tree &t){
	//assign the non-leaf nodes
	for(int i=0;i<t.nonLeaf;i++){
		int index, childNum;
		cin>>index>>childNum;
		for(int j=0;j<childNum;j++){
			int child;
			cin>>child;
			t.childNode[index].push_back(child);
		}
	}
}
void DFS(Tree &tree, int index, int* levelCount, int levelFlag){
	int flag = levelFlag+1;
	if(flag>Max)
		Max = flag;
	tree.visited[index] = 1;
	if(!tree.childNode[index].size())
		levelCount[flag]++;
	for(std::vector<int>::iterator it = tree.childNode[index].begin();it != tree.childNode[index].end();it++)
		DFS(tree, *it, levelCount, flag);
} 

void DFSTree(Tree &tree, int* levelCount, int &levelFlag){
	for(int i= 1;i<=tree.nodeNum;i++)
		if(!tree.visited[i])
			DFS(tree, i, levelCount, levelFlag);
}
int main(){
	Tree tree;
	cin>>tree.nodeNum>>tree.nonLeaf;
	InitTree(tree);
	DFSTree(tree, levelCount, levelFlag);
	for(int i=0;i<Max;i++){
		if((i+1)<Max)
			cout<<levelCount[i+1]<<" ";
		else
			cout<<levelCount[i+1];
	}
	return 0;
} 


