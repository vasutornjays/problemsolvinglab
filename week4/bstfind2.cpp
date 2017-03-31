#include <iostream>
#include <stdio.h>

using namespace std;

typedef int valueType;

struct TreeNode
{
  valueType val;
  TreeNode* left;
  TreeNode* right;
  int height;

  TreeNode(valueType val, TreeNode* left=0, TreeNode* right=0,int height=0)
    : val(val), left(left), right(right) ,height(height) {}

    void update_height()
    {
        int lh;
        int rh;
        if(left == 0) lh = -1;
        else lh = left->height;

        if(right == 0) rh = -1;
        else rh = right->height;

        if(lh > rh) height = lh+1;
        else height = rh+1;
    }
};
    
void left_rotation(TreeNode*& r)
{
    TreeNode* a = r;
    TreeNode* b = r->right;
    TreeNode* T = b->left;
    
    a->right = T;
    b->left = a;
    r = b;
    a->update_height();
    b->update_height();
}

void right_rotation(TreeNode*& r)
{
    TreeNode* a = r;
    TreeNode* b = r->left;
    TreeNode* T = b->right;
    
    a->left = T;
    b->right = a;
    r = b;

    a->update_height();
    b->update_height();
}

void balance(TreeNode*& r,valueType x)
{
    r->update_height();
    int lh;
    int rh;
    if(r->left == 0) lh = -1;
    else lh = r->left->height;

    if(r->right == 0) rh = -1;
    else rh = r->right->height;

    if(rh > lh+1)
    {
        if(x < r->right->val)
        {
            right_rotation(r->right);
        }
        left_rotation(r);
    }
    else if(lh > rh+1)
    {
        if(x > r->left->val)
        {
            left_rotation(r->left);
        }
        right_rotation(r);
    }
}

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
    balance(r,x);
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
            printf("%d\n",find(root,x));
        }
    }
    return 0;
}