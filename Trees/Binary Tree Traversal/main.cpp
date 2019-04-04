#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007

using namespace std;

struct tree{
    ll data;
    struct tree* left , *right;
};

struct tree* newnode(ll data)
{
    struct tree* node = new tree();
    node->data=data;
    node->left = NULL;
    node->right = NULL;
    return node;
};

void preorder(struct tree* node)
{
    if(node==NULL)
        return;
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct tree* node)
{
    if(node==NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}

void inorder(struct tree* node)
{
    if(node==NULL)
        return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}



int main()
{
    ios::sync_with_stdio(0);
    struct tree* root = newnode(10);
    root->left = newnode(11);
    root->right = newnode(12);
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    return 0;
}
