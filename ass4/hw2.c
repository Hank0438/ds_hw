void link_recover(NodePtr leftmost, NodePtr rightmost){ //double linked list���@�ө��k�_�����s�� 
	NodePtr r_temp, l_temp;
	r_temp = leftmost;
	while(r_temp->rlink != NULL){ //�M��֪�rlink�O�_���� 
		r_temp = r_temp-> rlink;
		if(r_temp == leftmost){
			printf("���k���s���S���D\n");
			break;	
		}
	}
	if(r_temp->rlink == NULL){ //���_�����s�����W 
		brokenNode = r_temp;
		printf("���k���s�����_��");
		l_temp = brokenNode->llink;
		while(l_temp->llink != brokenNode){ //�q�Ϥ�V��n���W��node 
			l_temp = l_temp-> llink;
		}
		brokenNode->rlink = l_temp;
		printf("���k�_�����s���צn�F");
	}
}
