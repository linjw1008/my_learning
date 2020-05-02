#include "common.h"

class BinarySearchTree
{
public:
    TreeNode* root = NULL;

//二叉搜索树的查找操作
    TreeNode* findNode(int val)
    {
        TreeNode* node = root;
        while (node != NULL)
        {
            if (val == node->val) return node;
            else if (val < node->val) node = node->left;
            else node = node->right;
        }

        return NULL;
    }

//二叉搜索树的插入操作
    void insertNode(int val)
    {
        if (root == NULL)
            root = new TreeNode(val);
        else
        {
            TreeNode* node = root;
            while (node != NULL)
            {
                if (val < node->val)
                {
                    if (node->left == NULL)
                    {
                        node->left = new TreeNode(val);
                        return;
                    }
                    node = node->left;
                }
                else
                {
                    if (node->right == NULL)
                    {
                        node->right = new TreeNode(val);
                        return;
                    }
                    node = node->right;
                }
            }
        }
    }

//二叉搜索树的删除操作
    void deleteNodeV1(int val)
    {
        TreeNode* node = root;
        TreeNode* parent = NULL;

        //找到要删除的节点及其父节点
        while (node != NULL && node->val != val)
        {
            parent = node;
            if (val < node->val) node = node->left;
            else node = node->right;
        }

        if (node == NULL) return; //没有找到

        //还没有考虑parent为NULL的情况

        //左右都右子节点
        if (node->left != NULL && node->right != NULL)
        {
            //找到右子树中最小的一个节点
            TreeNode* minNode = node->right;
            TreeNode* minParent = node;
            while (minNode->left != NULL)
            {
                minParent = minNode;
                minNode = minNode->left;
            }
            node->val = minNode->val;
            minParent->left = NULL;
        }
        else if (node->left != NULL) //只有左节点
        {
            if (parent->left == node) parent->left = node->left;
            else parent->right = node->left;
        }
        else if (node->right != NULL) //只有右节点
        {
            if (parent->left == node) parent->left = node->right;
            else parent->right = node->right;
        }
        else //左右两个子节点都没有
        {
            if (parent->left == node) parent->left = NULL;
            else parent->right = NULL;
        }
    }

//二叉搜索树的删除操作
    void deleteNodeV2(int val)
    {
        TreeNode* node = root;
        TreeNode* parent = NULL;

        //找到要删除的节点及其父节点
        while (node != NULL && node->val != val)
        {
            parent = node;
            if (val < node->val) node = node->left;
            else node = node->right;
        }

        if (node == NULL) return; //没有找到

        //要删除的节点有两个子节点
        if (node->left != NULL && node->right != NULL)
        {
            TreeNode* minNode = node->right;
            TreeNode* minParent = node;

            //找到右子树最小的节点
            while (minNode->left != NULL)
            {
                minParent = minNode;
                minNode = minParent->left;
            }
            //把该节点替换到要删除的节点中
            node->val = minNode->val;
            //问题转换为删除右子树的最小节点
            node = minNode;
            parent = minParent;
        }

        //删除要删除的节点
        //分3种情况，要删除的节点没有子节点、只有左节点、只有右节点
        //先找出要删除的节点的孩子节点
        TreeNode* child;
        if (node->left != NULL) child = node->left;
        else if (node->right != NULL) child = node->right;
        else child = NULL;

        //把要删除的节点的父节点的左子树或者右子树指向child
        if (parent == NULL)
            root = child;
        else if (parent->left == node)
            parent->left = child;
        else
            parent->right = child;
    }

//遍历二叉树
    void printCore(TreeNode* node)
    {
        if (node == NULL) return;
        printCore(node->left);
        cout << node->val << " ";
        printCore(node->right);
    }
    void printSearchTree()
    {
        printCore(root);
        cout << endl;
    }
};

int main()
{
    BinarySearchTree tree;
    tree.insertNode(1);
    tree.insertNode(3);
    tree.insertNode(5);
    tree.insertNode(7);
    tree.insertNode(9);
    tree.insertNode(2);
    tree.insertNode(4);
    tree.insertNode(6);
    tree.insertNode(8);
    tree.insertNode(10);

    tree.printSearchTree();

    tree.deleteNodeV2(8);
    tree.printSearchTree();

    tree.deleteNodeV2(8);
    tree.printSearchTree();

    tree.deleteNodeV2(2);
    tree.printSearchTree();

    tree.deleteNodeV2(4);
    tree.printSearchTree();

    cout << tree.root->val << endl;

    tree.deleteNodeV2(1);
    tree.printSearchTree();

    TreeNode* ans = tree.findNode(9);
    cout << ans->val << endl;

    return 0;
}