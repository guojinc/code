#include<stdio.h>
#include<stdlib.h>
 
typedef struct BTNode{
	char data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;
 
char pre[100], mid[100];
int len;
 
void init(){
	int i;
	for(i = 0; i < 100; i++){
		pre[i] = '#';
		mid[i] = '#';
	}
    i = 0;
    char ss[100];
    scanf("%s", ss);
	for (char s = ss[i]; s != '\0'; s = ss[++i]){
		pre[i] = s;

	}
    i = 0;
    char sss[100];
    scanf("%s", sss);
	for (char s = sss[i]; s != '\0'; s = sss[++i]){
		mid[i] = s;

	}
	i = 0;
    while(pre[i]!='#'){
    	i++;
    }
    len = i;
}
 
BTNode *CreateNode(int pre_start, int pre_end, int mid_start, int mid_end){
	int i, LLen,RLen;
	BTNode *root = (BTNode*)malloc(sizeof(BTNode));
	root->data = pre[pre_start];
	root->lchild = NULL;
	root->rchild = NULL;
	i = mid_start;
	while(root->data != mid[i])
	    i++;
	LLen = i - mid_start;
	RLen = mid_end - i;
	if(LLen){
		root->lchild = CreateNode(pre_start+1, pre_start+LLen, mid_start, i-1);
	}
	if(RLen){
		root->rchild = CreateNode(pre_start+LLen+1, pre_end, i+1,mid_end);
	}
	return root;
}
 
void PrintfTree(BTNode *root){
	if(root->lchild)
	     PrintfTree(root->lchild);
	if(root->rchild)
	     PrintfTree(root->rchild);
	printf("%c",root->data);
}
 
int main(){
	BTNode *root = (BTNode*)malloc(sizeof(BTNode));
	init();
	root = CreateNode(0 , len-1, 0, len-1);
	PrintfTree(root);
	return 0;
}