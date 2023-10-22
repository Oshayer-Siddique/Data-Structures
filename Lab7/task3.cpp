#include <iostream>
#include <vector>

class TreeNode {
public:
    int data;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val, TreeNode* p = nullptr) : data(val), parent(p), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    TreeNode* insertNode(int data, int parentData, int childType) {
        if (!root) {
            root = new TreeNode(data);
            return root;
        }

        TreeNode* parent = findNode(root, parentData);
        if (parent) {
            TreeNode* newNode = new TreeNode(data, parent);
            if (childType == 1)
                parent->left = newNode;
            else
                parent->right = newNode;
            return newNode;
        }

        return nullptr;
    }

    TreeNode* findNode(TreeNode* current, int data) {
        if (!current)
            return nullptr;
        if (current->data == data)
            return current;
        TreeNode* leftResult = findNode(current->left, data);
        if (leftResult)
            return leftResult;
        return findNode(current->right, data);
    }

    void removeNode(int data) {
        TreeNode* node = findNode(root, data);
        if (node) {
            if (node->parent) {
                if (node->parent->left == node)
                    node->parent->left = nullptr;
                else
                    node->parent->right = nullptr;
            }
            deleteSubtree(node);
        } else {
            std::cout << "Not Found" << std::endl;
        }
    }

    void deleteSubtree(TreeNode* node) {
        if (node) {
            deleteSubtree(node->left);
            deleteSubtree(node->right);
            delete node;
        }
    }

    void searchNode(int data) {
        TreeNode* node = findNode(root, data);
        if (node) {
            std::cout << "Node: " << node->data << ", Parent: ";
            if (node->parent)
                std::cout << node->parent->data;
            else
                std::cout << "None";
            std::cout << std::endl;
        } else {
            std::cout << "Not Found" << std::endl;
        }
    }

    int calculateHeight(TreeNode* node) {
        if (!node)
            return -1;  // Height of a leaf node is 0.
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return 1 + std::max(leftHeight, rightHeight);
    }

    int getHeight() {
        return calculateHeight(root);
    }

    void preorderTraversal(TreeNode* node) {
        if (node) {
            std::cout << "Node: " << node->data << ", Parent: ";
            if (node->parent)
                std::cout << node->parent->data;
            else
                std::cout << "None";
            std::cout << std::endl;
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void printTree() {
        preorderTraversal(root);
    }
};

int main() {
    int N;
    std::cin >> N;

    BinaryTree tree;
    std::vector<int> data(N), parent(N), childType(N);

    for (int i = 0; i < N; i++) {
        std::cin >> data[i] >> parent[i] >> childType[i];
        tree.insertNode(data[i], parent[i], childType[i]);
    }

    std::cout << "Tree Preorder Traversal:" << std::endl;
    tree.printTree();

    int removeNodeData;
    std::cin >> removeNodeData;
    tree.removeNode(removeNodeData);

    int searchNodeData;
    std::cin >> searchNodeData;
    tree.searchNode(searchNodeData);

    int treeHeight = tree.getHeight();
    std::cout << "Tree Height: " << treeHeight << std::endl;

    return 0;
}
