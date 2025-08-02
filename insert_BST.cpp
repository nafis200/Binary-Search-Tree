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
// 18 7 21 -1 12 20 26 9 15 -1 -1 -1 -1 -1 -1 -1 -1

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

void insert(Node* &root,int val){
    if(root == NULL){
       root = new Node(val);
    }
    if(root->val > val){
        if(root->left == NULL){
            root->left = new Node(val);
        }
        else{
            insert(root->left,val);
        }
    }
    else{
      if(root->right == NULL){
            root->right = new Node(val);
        }
        else{
            insert(root->right,val);
        }
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
// 18 7 21 -1 12 20 26 9 15 -1 -1 -1 -1 -1 -1 -1 -1
int main(){
  Node* root = input_tree();
  int val; cin >> val;
  insert(root,val);
  level_order(root);
  return 0;
}