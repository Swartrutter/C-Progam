void InOrder(BiTreeNode* root, void visit(DataType item)) {
	//中序遍历二叉树root，访问操作为Visit函数
	if (root != NULL) {
		InOrder(root->leftChild, visit);//先中序遍历根结点的左子树
		vist(root->data);//访问根结点
		InOrder(root->rightChild, visit);//再中序遍历根结点的右子树
	}
}