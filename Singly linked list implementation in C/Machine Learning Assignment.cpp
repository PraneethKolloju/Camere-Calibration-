//Praneeth Kolloju ML assignment
#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
}*head=NULL,*t=NULL;

//length of the LinkedList
int lenll(struct node *head){
	int c=0;
	while(head!=NULL){
		c+=1;
		head=head->next;
	}
	return c;
}

//Adding a new node
int insert(int key){
	
	if(head==NULL){
		head=(struct node *)malloc(sizeof(struct node));
		head->data=key;
		head->next=NULL;
		t=head;
	}
	else{
		struct node *p;
		p=(struct node *)malloc(sizeof(struct node));
		p->data=key;
		p->next=NULL;
		t->next=p;
		t=p;
	}
}

//Display the linked list
int disp(struct node *head){
	struct node *temp=head;
	printf("\n Elements of linked lists are : ");
	if(temp==NULL)
		return 0;
	while(temp!=NULL){
		if(temp->next!=NULL){
			printf("%d-->",temp->data);
			temp=temp->next;
		}
		else{
			printf("%d",temp->data);
			temp=temp->next;
		}
	}
	printf("\n");
}

//Deleting a particular node (referenced by the location),
int delatpar(int pos){
	int data;
	if(pos==0){
		data=head->data;
		head=head->next;
		printf("\n %d is deleted\n",data);
	}
	else{
		struct node *tail=NULL;
		struct node *main=head;
		for(int i=0;i<pos;i++){
			tail=main;
			main=main->next;
		}
		data=main->data;
		tail->next=main->next;
		printf("\n %d is deleted\n",data);
	}
}

//Delete all the nodes from the list which contain a particular data say a number 5
struct node* deletekey(int x)
{
    if (!head)
        return head;
    while (head && head->data == x)
        head = head->next;
    struct node *curr = head, *prev = NULL;
    while (curr) {
        if (curr->data == x)
            prev->next = curr->next;
        else
            prev = curr;
        curr = curr->next;
    }
    printf("\n deleted all the %d in the Linked List\n",x);
    return head;
    
}


//Display the inverted linked list
int invertll(){
	if(head==NULL)
		return 0;
	struct node *temp=head;
	struct node *newhead=NULL;
	while(temp!=NULL){
		struct node *newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=temp->data;
		newnode->next=newhead;
		newhead=newnode;
		temp=temp->next;
	}
	head=newhead;
}

//Delete the complete linked list
int entiredelete(struct node *head){
	struct node *temp;
	while(head!=NULL){
		temp=head;
		head=head->next;
		free(temp);
	}
	printf("\n Deleted entire linked list\n");
}

//Display the total memory space occupied by the linked list
int sizeofll(struct node *head){
	int size=0;
	struct node *temp=head;
	while(temp!=NULL){
		size+=sizeof(struct node);
		temp=temp->next;
	}
	
	printf("\n %d Bytes is the size of the Linked List\n",size);
}

//Delete all the nodes from the list which contain a particular data say a number 5 and the next subsequent node

struct node* deletesub(int x)
{
    if (!head)
        return head;
    while (head && head->data == x)
        head = head->next->next;
//        head=  head->next;
    struct node *curr = head, *prev = NULL;
    while (curr) {
        if (curr->data == x)
            prev->next = curr->next->next;
        else
            prev = curr;
        curr = curr->next;
    }
    return head;
}


int main(){
	insert(6);
	insert(5);
	insert(5);
	disp(head);
	invertll();
	printf("\n LinkedList after inverted\n");
	disp(head);
	sizeofll(head);
	deletekey(5);
	disp(head);
	entiredelete(head);
	}

