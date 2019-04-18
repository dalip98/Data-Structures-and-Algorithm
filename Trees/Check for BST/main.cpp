#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

class node
{
    public:
    node* left , *right ;
    ll data;

    node(ll data)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};

ll isBSTUtil(node *node , ll min ,ll max);

ll isBST(node *node)
{
    return(isBSTUtil(node , INT_MIN ,INT_MAX));
}

ll isBSTUtil(node *node , ll min ,ll max)
{
    if(node == NULL)
        return 1;
    if(node->data<min||node->data>max)
        return 0;
    return isBSTUtil(node->left , min , node->data - 1) && isBSTUtil(node->right , node->data-1 , max);
}

int main()
{
	ios::sync_with_stdio(0);
	node *root = new node(4);
    root->left = new node(2);
    root->right = new node(0);
    root->left->left = new node(1);
    root->left->right = new node(3);

    if(isBST(root))
        cout<<"Is BST";
    else
        cout<<"Not a BST";
	return 0;
}
