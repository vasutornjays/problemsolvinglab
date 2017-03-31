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

TreeNode* minval(TreeNode* r)
{
    TreeNode* min = r;
    while(min->left != 0)
    {
        min = min->left;
    }
    return min;
}

TreeNode* delete_node(TreeNode* r, valueType x)
{
    if(r == 0)
    {
        return 0;
    }
    if(r->left == 0 && r->right == 0)
    {
        TreeNode* tmp = 0;
        return tmp;
    }

    if(r->val > x)
    {
        r->left = delete_node(r->left,x);
    }
    else if(r->val < x)
    {
        r->right = delete_node(r->right,x);
    }
    else
    {
        if(r->left == 0)
        {
            TreeNode* tmp = r->right;
            delete r;
            return tmp;
        }
        else if(r->right == 0)
        {
            TreeNode* tmp = r->left;
            delete r;
            return tmp;
        }
        else
        {
            TreeNode* tmp = minval(r->right);
            r->val = tmp->val;
            r->right = delete_node(r->right,tmp->val);
        }
    }
    return r;
}

void postorder(TreeNode* r,int x = 0)
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

int main()
{
    TreeNode* root = 0;
    int n,k,x;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> k >> x;
        if(k == 1)
        {
            insert(root,x);
        }
        else if(k == 2)
        {
            printf("%d\n",find(root,x));
        }
        else if(k == 3)
        {
            root = delete_node(root,x);
        }
    }
    return 0;
}