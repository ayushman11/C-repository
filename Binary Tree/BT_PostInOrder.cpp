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

node* buildBinary (int postorder[], int inorder[], int start, int end) {
    static int idx = sizeof(postorder)/sizeof(postorder[0]) - 1;
    if(start > end) return NULL;

    int curr = postorder[idx];
    idx--;
    node* root = new node(curr);

    if(start == end) return root;

    int pos = search(inorder, start, end, curr);
    root->right = buildBinary(postorder, inorder, pos+1, end);
    root->left = buildBinary(postorder, inorder, start, pos-1);

    return root;
}

int main()
{
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};

    node* root = buildBinary(postorder, inorder, 0, 4);
    inorderPrint(root);
}