#include <iostream>
#include <string>
// #include <malloc.h>
#include <queue> 
#include <stack> 

using namespace std;
static int i=0,MAX=0,sum=0;
string s;

typedef struct Tree
{
	char data;
	struct Tree* lc;
	struct Tree* rc;
}node;

node* pcreat_tree(string s)//前序建树 
{
	node* bt;
	if(i >= s.size() || s[i]=='?')
	{
		bt=NULL;
		i++;
	}
	else
	{
		bt=(node*)malloc(sizeof(node));
		bt->data=s[i++];
		bt->lc=pcreat_tree(s);//增加左子树 
		bt->rc=pcreat_tree(s);
	}
	return bt;
}


/*void preoder(node* root)//前序递归 
{
	if(root!=NULL)
	{
		cout<<root->data;
		preoder(root->lc);
		preoder(root->rc);
	}
}*/

void preoder(node* root)//前序非递归 
{
	if(root!=NULL)
	{
		stack<node*> tem;
		tem.push(root);//根结点入栈 
		while(!tem.empty())
		{
			root=tem.top();//取出栈顶结点 
			tem.pop();//更新栈顶结点 
			cout<<root->data;
			//栈先入后出，所以先将右孩子入栈 
			if(root->rc!=NULL)//右孩子不为空入栈 
				tem.push(root->rc);
			if(root->lc!=NULL)//左孩子不为空入栈
				tem.push(root->lc);
		}
	}
}
/*void inoder(node* root)//中序 
{
	if(root!=NULL)
	{
		inoder(root->lc);
		cout<<root->data;
		inoder(root->rc);
	}
}*/

void inoder(node* root)//中序遍历非递归 
{
	if(root!=NULL)
	{
		stack<node*> tem;
		while(root||!tem.empty())//初始root不为空，栈为空 
		{
			if(root)
			{
				tem.push(root);
				root=root->lc;
			}
			else
			{
				root=tem.top();
				cout<<root->data;
				tem.pop();
				root=root->rc;         
			}
		}
	}
}

/*void hoder(node* root)//后序 
{
		if(root!=NULL)
	{
		hoder(root->lc);
		hoder(root->rc);
		cout<<root->data;
	}
}*/

void hoder(node* root)//后序遍历非递归 
{
	if(root!=NULL)
	{
		stack<node*> tem,h;
		tem.push(root);//根结点入栈 
		while(!tem.empty())
		{
			root=tem.top();//取出栈顶结点 
			tem.pop();//更新栈顶结点 
			h.push(root);
			//栈先入后出，所以先将右孩子入栈 
			if(root->lc!=NULL)//右孩子不为空入栈 
				tem.push(root->lc);
			if(root->rc!=NULL)//左孩子不为空入栈
				tem.push(root->rc);
		}
		while(!h.empty())//输出栈 
		{
			node*p;
			p=h.top();
			h.pop();
			cout<<p->data;
		}
	}
}

void leoder(node* root)//层次遍历 
{
	node* p;
	queue<node*> q;
	q.push(root);//根节点入队 
	while(!q.empty())
	{
		p=q.front();//取队列的头 
		q.pop();//更新队列头 
		cout<<p->data;
		if(p->lc!=NULL)//左子树不为空则入队 
			q.push(p->lc);
		if(p->rc!=NULL)
			q.push(p->rc);//右子树不为空则入队 
	}
} 

void treehight(node* root,int num)//求树高 
{
	if(root!=NULL)
	{
		treehight(root->lc,num+1);
		treehight(root->rc,num+1);
	}
	if(MAX<num)//若当前层数大于记录数则更新记录数 
		MAX=num;
}

void leafnum(node* root)//计算叶子节点数 
{
	if(root!=NULL)
	{
		leafnum(root->lc);
		leafnum(root->rc);
	}
	if(root!=NULL&&(root->lc==NULL&&root->rc==NULL))
		sum++;
}

void TestBinaryTree()
{
	node* b;
	int i=0;
	// cin>>s;
    s = "34?56?78?90";
	b=pcreat_tree(s);//前序递归建树 
	cout << "'''preorder'''" << endl;
    preoder(b);//前序遍历 
	cout<<endl;
	
	cout << "'''inorder'''" << endl;
	inoder(b);//中序遍历 
	cout<<endl;
	
	cout << "'''horder'''" << endl;
	hoder(b);//后序遍历 
	cout<<endl;
	 
	cout << "'''leorder'''" << endl;
	leoder(b);//层次遍历 
	cout<<endl;
	
	treehight(b,0);//求树高 
	cout<<MAX<<endl;
	
	leafnum(b);//求树的叶子数 
	cout<<sum<<endl;
 	return;
}
