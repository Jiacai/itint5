using namespace std;
//给定一棵完全二叉树（查看定义）的根结点，统计该树的结点总数。
//
//树结点类型名为TreeNode，您没必要知道该类型的定义，请使用下面的方法得到某个结点的左，右儿子结点，以及判断某结点是否为NULL。

//提示：使用O(n)的递归算法统计二叉树的结点数是一种显而易见的方法，此题中请利用完全二叉树的性质，想出效率更高的算法。

//使用getLeftChildNode(TreeNode)获得左儿子结点
//使用getRightChildNode(TreeNode)获得右儿子结点
//使用isNullNode(TreeNode)判断结点是否为空
int get_left_height(TreeNode root) {
    if (isNullNode(root)) {
        return 0;
    } else {
        return get_left_height(getLeftChildNode(root)) + 1;
    }
}

int count_complete_binary_tree_nodes(TreeNode root) {
    if (isNullNode(root))
        return 0;
    TreeNode leftNode = getLeftChildNode(root);
    TreeNode rightNode = getRightChildNode(root);
    int lheight = get_left_height(leftNode);
    int rheight = get_left_height(rightNode);
    if (lheight == rheight) {
        return (1 << lheight) + count_complete_binary_tree_nodes(rightNode);
    } else {
        return (1 << rheight) + count_complete_binary_tree_nodes(leftNode);
    }
}