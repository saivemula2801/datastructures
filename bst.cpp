#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*left,*right;
}*root=NULL;
struct node* create(int x)
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
struct node* insert(struct node*root,int data)
{
	if(root==NULL)
	{
		return create(data);
	}
	else if(data>root->data)
	{
		root->right=insert(root->right,data);
	}
	else
	{
		root->left=insert(root->left,data);
	}

}
struct node* min(struct node*root)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(root->left!=NULL)
	{
		return min(root->left);
	}
	else
	{
		return root;
	}
}

struct node* del(struct node*root,int x)
{
	
	if(root==NULL)
	{
		return root;
	}
	else if(x>root->data)
	{
		root->right=del(root->right,x);
	}
	else if(x<root->data)
	{
		root->left=del(root->left,x);
	}
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			return NULL;
		}
		else if(root->left==NULL || root->right==NULL)
		{
			struct node*p;
			if(root->left==NULL)
			{
				p=root->right;
			}
			else
			{
				p=root->left;
			}
			free(root);
			return p;
		}
        else
		{
			struct node*p=min(root->right);
			root->data=p->data;
			root->right=del(root->right,p->data);
		}
		return root;
	}
}
struct node* inorder(struct node*root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d->",root->data);
		inorder(root->right);
	}

}
struct node* preorder(struct node*root)
{
	if(root!=NULL)
	{
		printf("%d->",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
struct node* postorder(struct node*root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d->",root->data);
	}
}
main()
{
	root=insert(root,5);
	root=insert(root,10);
	root=insert(root,13);
	root=insert(root,6);
	root=insert(root,2);
	root=insert(root,3);
	printf("\n inorder traversal \t");
	inorder(root);
	printf("\n preorder traversal \t");
	preorder(root);
	printf("\n postorder traversal \t");
	postorder(root);
	printf("\n delete 10 \t");
	root=del(root,10);
	
	printf("\n inorder traversal \t");
	inorder(root);
	printf("\n preorder traversal \t");
	preorder(root);
	printf("\n postorder traversal \t");
	postorder(root);
}
