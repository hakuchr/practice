//INPUT: ABDH##I##EJ##K##CFL##M##GN##O##

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
struct node
{
	char data;
	node *lchild, *rchild;
};

node *insert()
{
	char ch;
	scanf("%c", &ch);
	node *current;
	if (ch == '#')
		current = NULL;
	else
	{
		current = new node;
		current->data = ch;
		current->lchild = insert();
		current->rchild = insert();
	}
	return current;
}

void pre(node *root)
{
	if (root){
		printf("%c ", root->data);
		pre(root->lchild);
		pre(root->rchild);
	}
}

void in(node *root)
{
	if (root){
		in(root->lchild);
		printf("%c ", root->data);
		in(root->rchild);
	}
}

void post(node *root)
{
	if (root){
		post(root->lchild);
		post(root->rchild);
		printf("%c ", root->data);
	}
}

void bfs(node *root)
{
	queue<node*>v;
	v.push(root);
	while (!v.empty()){
		root = v.front();
		v.pop();
		printf("%c ", root->data);
		if (root->lchild != NULL)
			v.push(root->lchild);
		if (root->rchild != NULL)
			v.push(root->rchild);
	}
}

int FindTreeDeep(node *root) 
{
	int deep = 0;
	if (root){
		int lchild_deep = FindTreeDeep(root->lchild);
		int rchild_deep = FindTreeDeep(root->rchild);
		deep = lchild_deep >= rchild_deep ? lchild_deep+1 : rchild_deep+1;
	}
	return deep;
}

int main()
{
	node *root = insert();
	printf("pre: \n");
	pre(root);
	printf("\nin: \n");
	in(root);
	printf("\npost: \n");
	post(root);
	printf("\nbfs: \n");
	bfs(root);
	printf("\n");
	int TreeDeep = FindTreeDeep(root);
	printf("TreeDeep = %d\n", TreeDeep);
	return 0;
}
