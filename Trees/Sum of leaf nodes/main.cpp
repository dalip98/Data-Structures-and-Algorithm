#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

class tree
{
    ll data ;
    tree *left ,*right ;
    tree* newNode(ll data);
public:
    tree* inst(tree* root , ll data);
    ll sum(tree* root);
};

tree* tree::newNode(ll data)
{
    tree *temp = new tree;
    temp->data = data;
    temp->left =NULL;
    temp->right = NULL;
    return temp;
}

tree* tree::inst(tree* root , ll data)
{
    if(root==NULL)
        return newNode(data);
    if(data<root->data)
        root->left = inst(root->left , data);
    else if(data>root->data)
        root->right = inst(root->right ,data);
    return root;
}

ll tree::sum(tree* root)
{
    if(root->left ==NULL&&root->right ==NULL)
        return root->data;
    else if(root->left==NULL)
        return sum(root->right);
    else if(root->right==NULL)
        return sum(root->left);
    else
        return sum(root->left)+sum(root->right);
}
int main()
{
    ios::sync_with_stdio(0);
    tree t;
    tree *root= NULL;
    root = t.inst(root, 50);
    root= t.inst(root, 30);
    root =t.inst(root, 20);
    root =t.inst(root, 40);
    root =t.inst(root, 70);
    root =t.inst(root, 90);
    cout<<t.sum(root)<<endl;
    return 0;
}
