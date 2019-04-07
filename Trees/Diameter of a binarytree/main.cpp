#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

class tree
{
    ll data;
    tree *left , *right;
    tree* newNode(ll data);
    ll height(tree* root);
public:
    tree* inst(tree* root , ll data);
    ll diameter(tree* root);
};

tree* tree::newNode(ll data)
{
    tree *temp = new tree;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;

}

tree* tree::inst(tree* root , ll data)
{
    if(root==NULL)
        return newNode(data);
    if(data<root->data)
    {
        root->left = inst(root->left , data);
    }
    else if(data>root->data)
    {
        root->right = inst(root->right ,data);
    }

    return root;
}

ll tree::height(tree* root)
{
    if(root==NULL)
        return 0;
    return 1+max(height(root->left) , height(root->right)) ;
}
ll tree::diameter(tree* root)
{
    if(root==NULL)
        return 0;
    return max(height(root->left)+height(root->right)+1 , max(diameter(root->left) , diameter(root->right))) ;
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
    cout<<t.diameter(root)<<endl;
    return 0;
}
