#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node *left;
    node *right;

    node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void inorderPrint(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int search(int inorder[], int start, int end, int curr) {
    for(int i=start; i<=end; i++) {
        if(inorder[i] == curr) return i;
    }
    return -1;
}

node* buildBinary (int preorder[], int inorder[], int start, int end) {
    static int idx = 0;
    if(start > end) return NULL;

    int curr = preorder[idx];
    idx++;
    node* root = new node(curr);

    if(start == end) return root;

    int pos = search(inorder, start, end, curr);
    root->left = buildBinary(preorder, inorder, start, pos-1);
    root->right = buildBinary(preorder, inorder, pos+1, end);

    return root;
}

int main()
{
    int preorder[] = {1,2,4,3,5}; 
    int inorder[] = {4,2,1,5,3};

    node* root = buildBinary(preorder, inorder, 0, 4);

    inorderPrint(root); 
}