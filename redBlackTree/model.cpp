#include<bits/stdc++.h>

using namespace std;

enum COLOR {RED, BLACK};

struct Node{
  int data;
  Node* parent;
  Node* left;
  Node* right;
  COLOR color;
  bool isLeaf = false;
};

Node* createNullLeafNode(Node* parent){
  // leaf nodes are considered as black nodes
  Node* node = new(Node);
  node->isLeaf = true;
  node->parent = parent;
  node->color = BLACK;

  return node; // which is a leaf
}

Node* createBlackNode(Node* parent, int data){

  Node* node = new(Node);
  node->data = data;
  node->color = BLACK;
  node->parent = parent;
  node->left = createNullLeafNode(node);
  node->right = createNullLeafNode(node);

  return node;
}

Node* createRedNode(Node* parent, int data){

  Node* node = new(Node);
  node->color = RED;
  node->parent = parent;
  node->data = data;
  node->left = createNullLeafNode(node);
  node->right = createNullLeafNode(node);

  return node;
}

Node* insert(Node* parent, Node* root, int data){

  if(root == NULL || root->isLeaf){

    if(parent != NULL){
        //not an empty tree
        return createRedNode(parent, data);

    }else{
      //empty tree
        return createBlackNode(parent, data);
    }

  }
  bool isLeft;
  if(data > root->data){
    Node* right = insert(root, root->right, data);
    if(right == root->parent){
      return right;
    }
    root->right = right;
    isLeft = false;
  }else if(data < root->data){
    Node* left = insert(root, root->left, data);
    if(left == root->parent){
      return left;
    }

    root->left = left;
    isLeft = true;
  }

  return root;
}

int main(int argc, char const *argv[]) {

  Node* root = NULL;
  root = insert(NULL, root, 12);
  root = insert(NULL, root, 45);
  root = insert(NULL, root, 10);
  cout << root->left->data << endl;

  return 0;
}
