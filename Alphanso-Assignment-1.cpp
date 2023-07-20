#include <iostream>
#include <map>
#include <queue>
using namespace std;
// Definition for a binary tree node
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  char color = 'N';
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Function to construct tree from given parent array
TreeNode *createTree(vector<int> &parent) {
  map<int, TreeNode *> m;
  TreeNode *root, *temp;
  int i, n = parent.size();
  for (i = 0; i < n; i++) {
    if (m.find(i) == m.end()) {
      temp = new TreeNode(i);
      m[i] = temp;
    }
    if (parent[i] == -1)
      root = m[i];

    else if (m.find(parent[i]) == m.end()) {
      temp = new TreeNode(parent[i]);
      temp->left = m[i];
      m[parent[i]] = temp;
    } else {
      if (!m[parent[i]]->left)
        m[parent[i]]->left = m[i];
      else
        m[parent[i]]->right = m[i];
    }
  }
  return root;
}
// Function to perform level order traversal of the binary tree
void levelOrderTraversal(TreeNode *root) {
  if (root == NULL)
    return;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    int size = q.size();
    while (size--) {
      TreeNode *currNode = q.front();
      q.pop();
      cout << currNode->val << "-" << currNode->color << " ";
      if (currNode->left != NULL)
        q.push(currNode->left);
      if (currNode->right != NULL)
        q.push(currNode->right);
    }
    cout << endl;
  }
}
// Function to perform Boundary traversal of left part of tree
void leftTraversal(TreeNode *root, vector<TreeNode *> &nodeArray) {
  if ((root == NULL) || (root->left == NULL && root->right == NULL))
    return;
  nodeArray.push_back(root);
  if (root->left)
    leftTraversal(root->left, nodeArray);
  else
    leftTraversal(root->right, nodeArray);
}
// Function to traverse leaf nodes of the binary tree
void leafTraversal(TreeNode *root, vector<TreeNode *> &nodeArray) {
  if (root == NULL)
    return;
  if (root->left == NULL && root->right == NULL)
    nodeArray.push_back(root);
  leafTraversal(root->left, nodeArray);
  leafTraversal(root->right, nodeArray);
}
// Function to perform Boundary traversal of the left part of tree
void rightTraversal(TreeNode *root, vector<TreeNode *> &nodeArray) {
  if ((root == NULL) || (root->left == NULL && root->right == NULL))
    return;
  if (root->right)
    rightTraversal(root->right, nodeArray);
  else
    rightTraversal(root->left, nodeArray);
  nodeArray.push_back(root);
}
// Function to color inner nodes of the binary tree
void inner(TreeNode *root) {
  if (!root)
    return;
  if (root->color == 'N')
    root->color = 'G';
  inner(root->left);
  inner(root->right);
}
int main() {
  // vector<int> parentArray = {-1};//test case 1
  // vector<int> parentArray = {-1,0,1,2};//test case 2
  // vector<int> parentArray = {-1,0,0,1,2,2};//test case 3
  // vector<int> parentArray = {-1,0,0,1,2};//test case 4
  // vector<int> parentArray = {-1,0,0,1,1,2,2,3,4,6,6};//test case 5
  // vector<int> parentArray =
  // {-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14};//test
  // case 6 vector<int> parentArray = {-1, 0, 0, 1, 1, 3, 4,4,5 };//my test case
  // 1 vector<int>parentArray= {-1,0,0,1,1,2,2}; //my test case 2 vector<int>
  // parentArray = {-1,0,0,1,1,2,4,5}; // my test case 3 vector<int> parentArray
  // = {-1, 0, 0, 1, 1, 3, 5 };//my test case 4
  vector<int> parentArray = {-1, 0, 1, 2, 3}; // my test case 5

  // corner case
  if (parentArray.size() == 0) {
    cout << "please provide valid input";
    return 0;
  }
  TreeNode *root = createTree(parentArray);
  cout << "Level Order Traversal of the Binary Tree before coloring:" << endl;
  levelOrderTraversal(root);
  vector<TreeNode *> nodeArray;
  nodeArray.push_back(root);

  leftTraversal(root->left, nodeArray);
  leafTraversal(root->left, nodeArray);
  leafTraversal(root->right, nodeArray);
  rightTraversal(root->right, nodeArray);

  int blue = 1, i;
  for (i = 0; i < nodeArray.size(); i++) {
    TreeNode *node = nodeArray[i];
    node->color = blue == 1 ? 'B' : 'R';
    blue = !blue;
  }
  inner(root);
  cout << "Level Order Traversal of the Binary Tree after coloring:" << endl;
  levelOrderTraversal(root);
  return 0;
}

