#include <bits/stdc++.h>
using namespace std;
int levelCount[105];//used to store the result of each level
int levelFlag=0;//�������ݲ㼶ֵ�������Ǵ�ֵ�����Ǵ����ã�����ᵼ���߼����� 
int Max = 0;

//BFS���ӳ���̫�鷳�ˣ���ѡ����Dfsֻ����ͨ��levelFlag��levelCount��ʵ��

typedef struct node{
	//��Ϊ���������¼��ŵ������������ֵ�����ÿ����
	//�����ֵ����Ҫ����㴫�����Ļ���δ��Ҳ̫�鷳�� 
	int index;
	//����������Ԫ�ص������ǰ�����Ŀ�������ʽ���ģ���Ȼ
	//ÿ�����붼���������ӽ��ĸ����� Ȼ�󰤸������ӽ���������
	//�Ǿ��ڽṹ���ڴ���һ����Ÿ�����������
	//Ȼ�����ݽ���������һ��int���������е��ӽ�� 
	int childNum;
	int* childNode;
}node;
//��ʼ����㣬�����ӽ���������ӽ������ĸ�ֵ 
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
	//t.nodeList = (node*)malloc(110*sizeof(node));      //��һ�п�������һ�л������������ڣ���һ������д������������Ų��������ģ���������01 02 04 05 �����м�ȱʡ�ģ��ͻ����Ѱ�����ӽ����������PAT�Ĳ���������û���������
	t.nodeList = (node*)malloc(t.nodeNum*sizeof(node)); 
	//init all nodes
	//for(int i=0;i<110;i++){                            //����ͬ�� 
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




