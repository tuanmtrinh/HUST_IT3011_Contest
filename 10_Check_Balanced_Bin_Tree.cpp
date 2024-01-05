/* 
Description
Each node of a binary tree has a field id which is the identifier of the node. Build a binary tree and check if the tree is a balanced tree, compute the height of the given tree (the number of nodes of the tree can be upto 50000)

Input
Line 1 contains MakeRoot u: make the root of the tree having id = u
Each subsequent line contains: AddLeft or AddRightcommands with the format
AddLeft u v: create a node having id = u, add this node as a left-child of the node with id = v (if not exists)
AddRight u v: create a node having id = u, add this node as a right-child of the node with id = v (if not exists)
The last line contains * which marks the end of the input

Output
Write two integers z and h (separated by a SPACE character) in which h is the height (the number of nodes of the longest path from the root to a leaf) and z = 1 if the tree is balanced and z = 0, otherwise

Example

Input
MakeRoot 1
AddLeft 2 1
AddRight 3 1
AddLeft 9 2
AddRight 4 2
AddLeft 6 3
AddRight 5 3
AddLeft 7 4
AddRight 8 4
*

Output
1 4 
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>

struct Node {
    int id;
    Node* left;
    Node* right;
};

int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
}

bool isBalanced(Node* node) {
    if (node == nullptr) {
        return true;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    if (std::abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right)) {
        return true;
    }
    return false;
}

int main() {
    std::unordered_map<int, Node*> nodes;
    Node* root = nullptr;

    std::string command;
    while (std::cin >> command && command != "*") {
        if (command == "MakeRoot") {
            int u;
            std::cin >> u;
            root = new Node{u, nullptr, nullptr};
            nodes[u] = root;
        } else if (command == "AddLeft" || command == "AddRight") {
            int u, v;
            std::cin >> u >> v;
            Node* parent = nodes[v];
            Node* child = new Node{u, nullptr, nullptr};
            if (command == "AddLeft") {
                parent->left = child;
            } else {
                parent->right = child;
            }
            nodes[u] = child;
        }
    }

    int height = getHeight(root);
    bool balanced = isBalanced(root);

    std::cout << (balanced ? "1" : "0") << " " << height << std::endl;

    return 0;
}
