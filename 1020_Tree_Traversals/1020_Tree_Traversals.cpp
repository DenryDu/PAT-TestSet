#include <bits/stdc++.h>
using namespace std;
#define Max 0x3f3f3f3f
queue<int> que1,que2;
int num, InOrder[32], PostOrder[32];
int find_InOrder(int d){
    for(int i=0;i<num;i++){
        if(InOrder[i]==d)
            return i;
    }
    return -1;
}
int find_PostOrder(int d){
    for(int i=0;i<num;i++){
        if(PostOrder[i]==d)
            return i;
    }
    return -1;
}
int findMin(int i, int j){
    int flag=Max;
    for(int k=i;k<=j;k++){  if(flag>find_PostOrder(InOrder[k])){ flag=find_PostOrder(InOrder[k]); }  }
    return flag;
}
int findMax(int i, int j){
    int flag=-1;
    for(int k=i;k<=j;k++){  if(flag<find_PostOrder(InOrder[k])){ flag=find_PostOrder(InOrder[k]); }  }
    return flag;
}
typedef struct node{
    int root;
    node* l_child;
    node* r_child;
}node;
node* find_child(int pLow, int pHigh, int inLow, int inHigh){
    int root = PostOrder[pHigh];
    int flag=find_InOrder(root);
    if(inLow<inHigh){
        node* tree = new node; 
        tree->root = root;
        if(flag<inLow){
            tree->l_child=NULL;
        }else{
            tree->l_child = find_child( findMin(inLow,flag-1), findMax(inLow,flag-1), inLow, flag-1);
        }
        if(flag>=inHigh){
            tree->r_child=NULL;
        }else{
            tree->r_child = find_child( findMin(flag+1,inHigh), findMax(flag+1,inHigh), flag+1, inHigh);
        }
        return tree;
    }else if(inLow==inHigh){
        node* temp = new node; 
        temp->root=InOrder[inLow];
        temp->l_child=NULL;
        temp->r_child=NULL;
        return temp;
    }
    else return NULL;
}
void BFS(node *root)
{
    queue<node*>q;
    q.push(root);
    int i=0;
    while(q.size()!=0)
    {
        node* visit=q.front();
        q.pop();
        cout<<visit->root;
        ++i;
        if(i<num)
            cout<<" ";
        if(visit->l_child!=NULL)
            q.push(visit->l_child);
        if(visit->r_child!=NULL)
            q.push(visit->r_child);
    }
}
int main(){
    cin>>num;
    for(int i=0;i<num;i++)
        cin>>PostOrder[i];
    for(int i=0;i<num;i++)
        cin>>InOrder[i];
    node* tree = find_child(0,num-1, 0,num-1);
    BFS(tree);
    return 0;
}
