#include <iostream>
#include <stdio.h>

using namespace std;

typedef int valueType;

struct TreeNode
{
  valueType val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(valueType val, TreeNode* left=0, TreeNode* right=0)
    : val(val), left(left), right(right) {}
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
        insert(r->right,x);
    }
}

void postorder(TreeNode* r,int x)
{
    if(r == 0)
    {
        return;
    }
    postorder(r->right,x+1);
    for(int i = 0;i < x;i++)
    {
        printf("...");
    }
    printf("* %d\n",r->val);
    postorder(r->left,x+1);
}

int find(TreeNode* r, valueType x)
{
    if(r == 0)
    {
        return 0;
    }
    else if(x == r->val)
    {
        return 1;
    }
    else if(x < r->val)
    {
        find(r->left,x);
    }
    else if(x > r->val)
    {
        find(r->right,x);
    }
}

int main()
{
    TreeNode* root = 0;
    int n,k,x;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        insert(root,x);
    }
    postorder(root,0);
    return 0;
}