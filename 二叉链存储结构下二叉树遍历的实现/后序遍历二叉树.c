void PostOrder(BiTreeNode* root, void visit(DataType item)) {
	//后序遍历二叉树root，访问操作为Visit函数
	if (root != NULL) {
		PostOrder(root->leftChild, visit);//先后序遍历根结点的左子树
		PostOrder(root->rightChild, visit);//再后序遍历根结点的右子树
		vist(root->data);//最后访问根结点
	}
}