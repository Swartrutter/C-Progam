void PreOrder(BiTreeNode* root, void visit(DataType item)) {
	//ǰ�����������root�����ʲ���ΪVisit����
	if (root != NULL) {
		vist(root->data);
		PreOrder(root->leftChild, visit);
		PreOrder(root->rightChild, visit);
	}
}
//˵�����Բ�ͬ��Ӧ�����⣬��������������ʱ���еĲ����ǲ�ͬ�ģ�
//Ϊ����Ƴ�ͨ�õ�ǰ���������������PreOrder���������ǰѷ��ʲ������Ϊǰ�����������������һ���������Visit();