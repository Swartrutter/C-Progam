void PostOrder(BiTreeNode* root, void visit(DataType item)) {
	//�������������root�����ʲ���ΪVisit����
	if (root != NULL) {
		PostOrder(root->leftChild, visit);//�Ⱥ������������������
		PostOrder(root->rightChild, visit);//�ٺ������������������
		vist(root->data);//�����ʸ����
	}
}