void InOrder(BiTreeNode* root, void visit(DataType item)) {
	//�������������root�����ʲ���ΪVisit����
	if (root != NULL) {
		InOrder(root->leftChild, visit);//���������������������
		vist(root->data);//���ʸ����
		InOrder(root->rightChild, visit);//���������������������
	}
}