#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *root = NULL;


Node* insert(struct Node* node, int key)
{

    if (node == NULL)
    {
        Node *temp = new Node(key);
        return temp;
    }

    if (key < node->data)
    {
        node->left=insert(node->left, key);
    }
    else if (key > node->data)
    {
        node->right=insert(node->right, key);
    }

    return node;

}


void in_order(Node *node)
{
    if(node->left!=NULL)
        in_order(node->left);
    cout << node->data << " ";
    if(node->right!=NULL)
        in_order(node->right);
}

void ser(Node *node, int key)
{
    if (node == NULL)
    {
        cout<< "not found";
        return;
    }
    if(node-> data == key)
    {
        cout<< "found";
        return;
    }

    else if(key < node->data)
    {
        node = node->left;
        ser(node,key);
    }
    else if(key > node->data)
    {
        node = node->right;
        ser(node,key);
    }

}

int main()
{
    int item,n,key;
    root = insert(root, 20);


    cout<< "Enter number of nodes: ";
    cin>> n;

    cout<< " Enter nodes: ";
    for(int i=0; i<n-1; i++)
    {
        cin>> key;
        insert(root, key);
    }

    cout<<"In order:"<<endl;
    in_order(root);
    cout<<endl;
    cout<< "enter the number to be searched: ";
    cin >> item;
    ser(root,item);
}

