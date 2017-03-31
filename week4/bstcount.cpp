#include <iostream>
#include <stdio.h>

using namespace std;

typedef int valueType;

struct TreeNode
{
  valueType val;
  TreeNode* left;
  TreeNode* right;
  int weight;

  TreeNode(valueType val, TreeNode* left=0, TreeNode* right=0,int weight=1)
    : val(val), left(left), right(right), weight(weight) {}
};

void insert(TreeNode*& r, valueType x)
{
    if(!r)
    {
        r = new TreeNode(x);
    }
    else if(x < r->val)
    {
        insert(r->left,x);
    }
    else if(x > r->val)
    {
        r->weight = r->weight+1;
        insert(r->right,x);
    }
}

int count_node(TreeNode* r,int x,int count = 0)
{
    while(r != 0)
    {
        if(r->val <= x)
        {
            r = r->right;
        }
        else 
        {
            count += r->weight;
            r = r->left;
        }
    }
    return count;
}

int main()
{
    TreeNode* root = 0;
    int n,k,x;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&k,&x);
        if(k == 1)
        {
            insert(root,x);
        }
        else if(k == 2)
        {
            printf("%d\n",count_node(root,x));
        }
    }
    return 0;
}