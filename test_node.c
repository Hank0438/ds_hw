/* link list (�s����C) */  
#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
  
/* �w�q���c���A */  
typedef struct link_node{  
   int data;  
   struct link_node *link;  
} LINK_NODE;  
  
  
  
/* ���ͷs�`�I */  
LINK_NODE *new_node(int data){  
   LINK_NODE *node;  
   node=(LINK_NODE *) malloc(sizeof(LINK_NODE));/*<stdlib.h>*/  
     
   // �O���餣��  
   if(node == NULL){ return NULL;}  
     
   node->data=data;    
   node->link=NULL;       
   return node;  
}  
  
  
/* �[�J�s����Ʃ�̫� */  
LINK_NODE *push_node(LINK_NODE *list, int data){  
   /*���ͷs�`�I*/  
   LINK_NODE *node=new_node(data);    
  
   // �[�J�Ĥ@�ӷs�`�I  
   if(list==NULL){      
       list=node;  
   }else{  
       LINK_NODE *p=list;    
       // ���o�̫�@�Ӹ`�I  
       while(p->link!=NULL){p=p->link;}  
       p->link=node;  
   }     
   return list;  
}  
  
  
/* �ƧǴ��J�s�`�I */  
LINK_NODE *sort_insert(LINK_NODE *list,int data){  
   // �[�J�Ĥ@�����  
     
   // ���ͷs�`�I  
   LINK_NODE *node=new_node(data);      
   if(list==NULL){ list=node; return list; }    
  
   // �M��j����(data)����}  
   LINK_NODE *r=list,*q=list;      
   while(r!=NULL && r->data<data){ q=r; r=r->link; }  
  
   if(r==list){ // ���`�I  
       node->link=list; list=node;   
   }else{ // �[�J�s�`�I�󤤶�  
       node->link=q->link;   
       q->link=node;   
   }      
   return list;   
}  
  
  
/* �p���C���� */  
int get_length(LINK_NODE *list){  
   LINK_NODE *p=list;  
   int count=0;    
   while(p!=NULL){      
       count++;    
       p=p->link;    
   }  
     
   return count;  
}  
  
  
/* �j�M���(data)���`�I��l */  
LINK_NODE *search_node(LINK_NODE *list, int data){  
   LINK_NODE *p=list;    
   while(p!=NULL && p->data!=data){ p=p->link; }  
   return p ;  
}  
  
  
/* �L�X�Ҧ���C���Ҧ���� */  
int display(LINK_NODE *list){  
   LINK_NODE *p=list;  
   while(p!=NULL){   
       printf("%d\n",p->data);/*<stdio.h>*/  
       p=p->link;    
   }  
   return 1;  
}  
  
  
  
  
/*�D�{��*/  
void main(){  
   LINK_NODE *list=NULL;  
     
   list=sort_insert(list,4);  
   list=sort_insert(list,2);  
   list=sort_insert(list,7);  
   list=sort_insert(list,9);  
   list=sort_insert(list,14);  
   display(list);  
     
   printf("--------------------------\n");  
     
   list=push_node(list,4);  
   list=push_node(list,2);  
   list=push_node(list,7);  
   list=push_node(list,9);  
   list=push_node(list,14);  
   display(list);  
     
//   _getch();
}  
