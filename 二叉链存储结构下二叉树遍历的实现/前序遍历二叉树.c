void PreOrder(BiTreeNode* root, void visit(DataType item)) {
	//前序遍历二叉树root，访问操作为Visit函数
	if (root != NULL) {
		vist(root->data);
		PreOrder(root->leftChild, visit);
		PreOrder(root->rightChild, visit);
	}
}
//说明：对不同的应用问题，二叉树遍历操作时进行的操作是不同的，
//为了设计出通用的前序遍历二叉树函数PreOrder函数，我们把访问操作设计为前序遍历二叉树函数的一个函数虚参Visit();