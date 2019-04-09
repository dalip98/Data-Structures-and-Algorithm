#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

class tree
{
    ll data;
    tree *left ,*right;
    ll sumx(tree* root, ll& cnt , ll sum);
    tree* newNode(ll data);
public:
    tree* inst(tree* root , ll data);
    ll countsubtrees(tree* root ,ll sum);
};
tree* tree::newNode(ll data)
{
    tree* temp = new tree;
    temp->data=data;
    temp->left = temp->right = NULL;
    return temp;
}
tree* tree::inst(tree* root , ll data)
{
    if(root==NULL)
        return newNode(data);
    if(root->data>data)
    {
        root->left = inst(root->left , data);
    }
    else if(root->data<=data)
    {
        root->right = inst(root->right ,data);
    }
    return root;
}

ll tree::sumx(tree* root ,ll& cnt , ll sum)
{
    if(root==NULL)
        return 0;
    ll ls = sumx(root->left , cnt ,sum);
    ll rs = sumx(root->right , cnt ,sum);
    if(ls+rs+root->data==sum)
        cnt++;
    return root->data + ls+rs;
}
ll tree::countsubtrees(tree* root , ll sum)
{
    ll cnt = 0;
    if(root==NULL)
        return 0;
    ll ls  = sumx(root->left,cnt, sum );
    ll rs = sumx(root->right,cnt , sum);

    if(ls+rs+root->data==sum)
        cnt++;
    return cnt;
}
int main()
{
    ios::sync_with_stdio(0);
    tree* root = NULL;
    tree t ;
    root = t.inst(root, 50);
    root= t.inst(root, 30);
    root =t.inst(root, 20);
    root =t.inst(root, 40);
    root =t.inst(root, 70);
    root =t.inst(root, 90);
    cout<<t.countsubtrees(root , 20)<<endl;
    return 0;
}
