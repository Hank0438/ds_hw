#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
};

void main(){
	
	struct Node *first = NULL ;
	first = malloc( sizeof(struct Node) );
	first->next = 0;    //null pointer
	first->data = -1;
}

Node *createNode(void)
{
    Node *tmpNode;
    tmpNode = (Node *) malloc(sizeof(Node));
    if(tmpNode == NULL){
        printf("�O���餣��");
        exit(1);
    }
    return (tmpNode);
}

void insert(Node *first, Node x){
    Node tmp;
    MALLOC(tmp, sizeof(*tmp));
    tmp->data = 50;
    if(*first){
        tmp->link = x->link;
        x->link = tmp;
    }else{
        tmp->link = NULL;
        *first = tmp;
    }
}

Node *insertNode( Node *first, Node *theNode, int data)}{
    Node *newNode;
    newNode = createNode();
    newNode = data;
    newNode->link = NULL;
    if( theNode == NULL ){            //�e�ݴ��J
        newNode->link = first;
        first = new;Node;
    }else{
        if(theNode->link == NULL)    //���ݴ��J
            theNode->link = newNode;
        else{                           //�������J
            newNode->link = theNode->link;
            theNode->link = newNode;
        }
    }
    return (first);
}
