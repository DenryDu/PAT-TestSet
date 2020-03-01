#include <bits/stdc++.h>
using namespace std;
int levelCount[105];//used to store the result of each level
int levelFlag=0;//用来传递层级值，不过是传值，不是传引用，否则会导致逻辑错误 
int Max = 0;

//BFS进队出队太麻烦了，就选择用Dfs只不过通过levelFlag和levelCount来实现

typedef struct node{
	//因为外层用来记录序号的是数组的索引值，如果每次用
	//到这个值都需要从外层传进来的话，未免也太麻烦了 
	int index;
	//接下来两个元素的设置是按照题目的输入格式来的，既然
	//每次输入都是先输入子结点的个数， 然后挨个输入子结点的索引号
	//那就在结构体内创建一个存放个数的整数，
	//然后依据结点个数创建一个int数组存放所有的子结点 
	int childNum;
	int* childNode;
}node;
//初始化结点，包括子结点数量和子结点数组的赋值 
void InitNode(node &n, int childNum){
	n.childNum = childNum;
	n.childNode = (int*)malloc(n.childNum*(sizeof(int)));
	for(int i=0;i<n.childNum;i++){
		cin>>n.childNode[i];
	}
}

typedef struct Tree{
	int nodeNum;
	int nonLeaf;
	int visited[100]={0};
	node* nodeList; 
}Tree;
void InitTree(Tree &t){
	//t.nodeList = (node*)malloc(110*sizeof(node));      //这一行可以与下一行互换，区别在于，下一行那种写法，如果结点序号不是连续的，而是例如01 02 04 05 这种中间缺省的，就会出现寻不到子结点的情况，但PAT的测试用例里没有这种情况
	t.nodeList = (node*)malloc(t.nodeNum*sizeof(node)); 
	//init all nodes
	//for(int i=0;i<110;i++){                            //区别同上 
	for(int i=0;i<t.nodeNum;i++){
		t.nodeList[i].index = i+1;
		t.nodeList[i].childNum = 0;
	} 
	//assign the non-leaf nodes
	for(int i=0;i<t.nonLeaf;i++){
		int index, childNum;
		cin>>index>>childNum;
		InitNode(t.nodeList[index-1], childNum);
	}
}
void DFS(Tree &tree, node &node, int* levelCount, int levelFlag){
	int flag = levelFlag+1;
	if(flag>Max)
		Max = flag;
	tree.visited[node.index-1] = 1;
	if(node.childNum==0)
		levelCount[flag]++;
	for(int i= 0;i<node.childNum;i++)
		DFS(tree, tree.nodeList[node.childNode[i]-1], levelCount, flag);
} 

void DFSTree(Tree &tree, int* levelCount, int &levelFlag){
	for(int i= 0;i<tree.nodeNum;i++)
		if(!tree.visited[i])
			DFS(tree, tree.nodeList[i], levelCount, levelFlag);
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




