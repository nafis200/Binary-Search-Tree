// Sorted array ke BST te convert korbo

// 6

//  2 5 8 11 15 18 

// BST te duplicate value insert kora hoy na
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_tree()
{
    int val;
    cin >> val;
    if (val == -1)
        return NULL;

    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *x = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node *myleft = NULL;
        Node *myright = NULL;

        if (l != -1)
        {
            myleft = new Node(l);
        }
        if (r != -1)
        {
            myright = new Node(r);
        }

        x->left = myleft;
        x->right = myright;

        if (x->left)
        {
            q.push(x->left);
        }
        if (x->right)
        {
            q.push(x->right);
        }
    }
    return root;
}

bool search(Node* root, int val){
    if(root == NULL){
        return false;
    }
    if(root->val == val){
        return true;
    }
    if(root->val > val){
       return search(root->left,val);
    }
    else{
       return search(root->right,val);
    }
}
int level_order(Node *root)
{
    queue<Node *> q;
    q.push(root);
    int count = 0;
    while (!q.empty())
    {
        Node *x = q.front();
        q.pop();
        count++;
        if (x->left != NULL)
        {
            q.push(x->left);
        }
        if (x->right != NULL)
        {
            q.push(x->right);
        }
    }
    return count;
}

Node* convert(int a[], int n, int l, int r){
    if(l > r){
        return NULL;
    }

    int mid = (l + r) / 2;
    Node* root = new Node(a[mid]);
    Node* leftroot = convert(a, n, l, mid - 1);
    Node* rightroot = convert(a, n, mid + 1, r);
    root->left = leftroot;
    root->right = rightroot;
    return root;
}

int main(){
  
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    Node* root = convert(a, n, 0, n - 1);
    level_order(root);
    return 0;
}