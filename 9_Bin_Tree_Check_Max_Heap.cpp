/* 
Description
Each node of a binary tree has id which is an integer representing the identifier of the node. 
Perform a sequence of operations of 3 types belows for constructing the tree T (T is initialized by an empty tree)
make-root u: create the root having id = u (u is an integer, 1 <= u <= 100000)
add-left  u  v (u,v are integers, 1 <= u,v <= 100000): create a node having id = u and insert this node as a left-child of the node having id = v in T (do not perform the operation if the node having id = v does not exist or the node having id = u exists or the node having id = v has already a left-child)
add-right u  v (u,v are integers, 1 <= u,v <= 100000): create a node having id = u and insert this node as a right-child of the node having id = v in T (do not perform the operation if the node having id = v does not exist or the node having id = u exists or the node having id = v has already a right-child)
A sub-tree (by convention, T is a sub-tree of itself) is call a max-heap if the id of each node is greater than the ids of its chlidren.
Perform a sequence of equeries of 2 types belows:
is-max-heap  u (u is an integer, 1 <= u <= 100000): return 1 if the sub-tree (of T) rooted at u is a max-heap, and return 0, otherwise (if the node having id = u does not exist, then return 1)
count-nodes-having-2-children  u (u is an integer, 1 <= u <= 100000): return the number of nodes having both left-child and right-child in the sub-tree (of T) rooted at u.

Input
Consists of two block of information:
The first block is a sequence of lines, each line is an operation of 3 type above (note: the operation make-root appears exactly once and at the beginning of the block). The first block is terminated by a line containing the character *
The second block is a sequence of lines, each line is a query. The second block is terminated by a line containing ***

Output
Write on each line, the result of the corresponding query of the second block described above

Example
Input
make-root 9
add-left 5 9
add-right 7 9
add-left 1 5
add-right 4 5
add-left 2 7
add-right 3 7
*
is-max-heap 5
count-nodes-having-2-children 9
***

Output
1
3 
*/

#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

struct Node {
    int id;
    Node* left;
    Node* right;
};

Node* createNode(int id) {
    Node* newNode = new Node;
    newNode->id = id;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

unordered_map<int, Node*> nodes;

void makeRoot(int u) {
    Node* root = createNode(u);
    nodes[u] = root;
}

void addLeft(int u, int v) {
    if (nodes.find(u) != nodes.end() || nodes.find(v) == nodes.end() || nodes[v]->left != nullptr) {
        return;
    }
    Node* newNode = createNode(u);
    nodes[u] = newNode;
    nodes[v]->left = newNode;
}

void addRight(int u, int v) {
    if (nodes.find(u) != nodes.end() || nodes.find(v) == nodes.end() || nodes[v]->right != nullptr) {
        return;
    }
    Node* newNode = createNode(u);
    nodes[u] = newNode;
    nodes[v]->right = newNode;
}

bool isMaxHeap(Node* node) {
    if (node == nullptr) {
        return true;
    }
    if (node->left != nullptr && node->left->id > node->id) {
        return false;
    }
    if (node->right != nullptr && node->right->id > node->id) {
        return false;
    }
    return isMaxHeap(node->left) && isMaxHeap(node->right);
}

int countNodesWithTwoChildren(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    int count = 0;
    if (node->left != nullptr && node->right != nullptr) {
        count++;
    }
    count += countNodesWithTwoChildren(node->left) + countNodesWithTwoChildren(node->right);
    return count;
}

int main() {
    string line;
    while (getline(cin, line) && line != "*") {
        string operation;
        int u, v;
        stringstream ss(line);
        ss >> operation;
        if (operation == "make-root") {
            ss >> u;
            makeRoot(u);
        } else if (operation == "add-left") {
            ss >> u >> v;
            addLeft(u, v);
        } else if (operation == "add-right") {
            ss >> u >> v;
            addRight(u, v);
        }
    }

    while (getline(cin, line) && line != "***") {
        string query;
        int u;
        stringstream ss(line);
        ss >> query >> u;
        if (query == "is-max-heap") {
            cout << isMaxHeap(nodes[u]) << endl;
        } else if (query == "count-nodes-having-2-children") {
            cout << countNodesWithTwoChildren(nodes[u]) << endl;
        }
    }

    return 0;
}
