void link_recover(NodePtr leftmost, NodePtr rightmost){ //double linked list有一個往右斷掉的連結 
	NodePtr r_temp, l_temp;
	r_temp = leftmost;
	while(r_temp->rlink != NULL){ //尋找誰的rlink是斷掉的 
		r_temp = r_temp-> rlink;
		if(r_temp == leftmost){
			printf("往右的連結沒問題\n");
			break;	
		}
	}
	if(r_temp->rlink == NULL){ //把斷掉的連結接上 
		brokenNode = r_temp;
		printf("往右的連結有斷掉");
		l_temp = brokenNode->llink;
		while(l_temp->llink != brokenNode){ //從反方向找要接上的node 
			l_temp = l_temp-> llink;
		}
		brokenNode->rlink = l_temp;
		printf("往右斷掉的連結修好了");
	}
}
