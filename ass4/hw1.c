NodePtr findtail(NodePtr p){ //��}�l����m 
	NodePtr q; //��ܰj��{�b����m 
	q=p; //�q�}�l����m�}�l 
	while(q->link!=p){ // �p�G�{�b����m�٨S�^��}�l����m 
		q=q->link;
	}
	return q;
}

void delfirst(NodePtr head){
	NodePtr p;
	if(head==NULL){
		ListIsEmpty();
	}else if(head->link = Null){//for there is only head node situation	
		head->data=Null;
		free(head);	 
	}else{//there are more than two node in the list
		p = head; //p��ܰj��qhead�}�l 
		while(p->link != head){ //��head���e�@��node 
			p = p->link;
		}
		if(p->link = head){ //����Ahead���e�@��node��link�Ohead���U�@��node �A�M��R��head���O���� 
			p->link = head->link
			free(head);	
		}	
	}
}

void invert_cir(NodePtr head){//add something here	
	NodePtr p, q, last;
	p = head;
	while(p->link!=head){ //�]���|�`���A����head���W�@��node 
		p = p->link;
	} 
	last = p; //���쥻��head���W�@��node 
	while(head!=last){ //�}�l�ⶶ���A�� 
		q = p;
		p = head;
		head = head->link;
		p->link = q;
	}
}


