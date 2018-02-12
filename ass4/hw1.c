NodePtr findtail(NodePtr p){ //放開始的位置 
	NodePtr q; //表示迴圈現在的位置 
	q=p; //從開始的位置開始 
	while(q->link!=p){ // 如果現在的位置還沒回到開始的位置 
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
		p = head; //p表示迴圈從head開始 
		while(p->link != head){ //找head的前一個node 
			p = p->link;
		}
		if(p->link = head){ //找到後，head的前一個node的link是head的下一個node ，然後刪掉head的記憶體 
			p->link = head->link
			free(head);	
		}	
	}
}

void invert_cir(NodePtr head){//add something here	
	NodePtr p, q, last;
	p = head;
	while(p->link!=head){ //因為會循環，先找head的上一個node 
		p = p->link;
	} 
	last = p; //找到原本的head的上一個node 
	while(head!=last){ //開始把順序顛倒 
		q = p;
		p = head;
		head = head->link;
		p->link = q;
	}
}


