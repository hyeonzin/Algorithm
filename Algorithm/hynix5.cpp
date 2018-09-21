#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	TreeNode *left, *right;
}TreeNode;


void inorder(TreeNode *cur)
{
	if(cur->left!=NULL)
		inorder(cur->left);
	printf(" %d", cur->data);
	if(cur->right!=NULL)
		inorder(cur->right);

}

void preorder(TreeNode *cur)
{
	printf(" %d", cur->data);
	if (cur->left != NULL)
		preorder(cur->left);
	if (cur->right != NULL)
		preorder(cur->right);
}

void postorder(TreeNode *cur)
{
	if (cur->left != NULL)
		postorder(cur->left);
	if (cur->right != NULL)
		postorder(cur->right);
	printf(" %d", cur->data);
}


int main()
{

	TreeNode t7 = { 7,NULL,NULL };
	TreeNode t4 = { 4,NULL,NULL };
	TreeNode t5 = { 5,NULL,NULL };
	TreeNode t6 = { 6,NULL,&t7 };
	TreeNode t2 = { 2,&t4,NULL };
	TreeNode t3 = { 3,&t5,&t6 };
	TreeNode t1 = { 1,&t2,&t3 };
	TreeNode * tree = &t1;

	printf("preorder :");
	preorder(tree);
	printf("\ninorder :");
	inorder(tree);
	printf("\npostorder :");
	postorder(tree);

	return 0;
}