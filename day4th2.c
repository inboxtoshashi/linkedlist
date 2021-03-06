// Create linked list dynamic
// after that add at end of the linked list
// add at bigning of the linked list
// add at mid of the linked list
// add node at anywhere in the linked list
// add node at anywhere in the linked list according to position
// search position in the linked list according to element
// add node in the linked list after an element
// Display the linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

// add node in the linked list after an element
struct node *affterelement(int pos, int val, struct node *head){
	struct node *newnode, *curr;
	curr = head;
	while(curr->next != NULL){
		if(curr->data == pos){
			newnode = malloc(sizeof(struct node));
			newnode->data = val;
			newnode->next = curr->next;

			curr->next = newnode;
		return head;
		}
		curr = curr->next;
	}
};

// search position in the linked list according to element
struct node *searchpos(int val, struct node *head){
	struct node *newnode, *curr;
	int count = 0;
	curr = head;
	while(curr->next != NULL){
		count++;
		if(val == curr->data){
			printf("%d is available at position %d\n", val, count );
		return head;
		}
		curr = curr->next;
	}
};
// add node at anywhere in the linked list according to position
struct node *addpos(int pos, int val, struct node *head){
	struct node *newnode, *curr;
	curr = head;
	int i=1;
	while(curr->next != NULL)
	{	
		curr = curr->next;
		i++;
		printf("i %d\n", i);
		if(i == pos){
			newnode = malloc(sizeof(struct node));
			newnode->data = val;
			newnode->next = curr->next;
			curr->next = newnode;
		return head;
		}
	}
};

// add at bigning of the linked list
struct node *addbig(int val, struct node *head){
	struct node *newnode;
	newnode = malloc(sizeof(struct node));
	newnode->data = val;
	newnode->next = head;
	head = newnode;
return head;
};

// add at mid of the linked list
struct node *addmid(int val, struct node *head){
	struct node *newnode, *curr;
	int count=0, mid, i;
	curr = head;
	while(curr!=NULL){
		curr = curr->next;
		count++;
	}
	mid = count/2;
	newnode = malloc(sizeof(struct node));
	newnode->data = val;
	newnode->next = NULL;
	curr = head;
	for(i=1; i != mid; i++)
		curr = curr->next;
	newnode->next = curr->next;
	curr->next = newnode;
return head;
};

// after that add at end of the linked list
struct node *addnode(int val, struct node *head){
	if(head == NULL){
		struct node * newnode;
		newnode = malloc(sizeof(struct node));
		newnode->data = val;
		newnode->next = NULL;
		head = newnode;
	return head;
	}
	struct node *newnode, *curr;
	curr = head;
	while(curr->next != NULL)
		curr = curr->next;
	newnode = malloc(sizeof(struct node));
	newnode->data = val;
	newnode->next = NULL;
	curr->next = newnode;
return head;

};

// Display the linked list
void display(struct node *head){
	struct node *curr;
	curr =head;
	printf("\n");
	while(curr != NULL){
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}

// Main function
int main(){
	struct node *head=NULL;
	int size, i=1, val, option, pos, addafter;
	printf("Enter the size of the linked list:\n");
	scanf("%d", &size);
	printf("Enter the elements \n");
	for(i=1; i<=size; i++){
		scanf("%d", &val);
		head = addnode(val, head);
	}
	printf("Your linked list is : \n");
	display(head);
	printf("\n");
	while(i != 0){
		printf("\nPress 1 to Print linked list.\n");
		printf("Press 2 to Add node at the Mid of the linked list.\n");
		printf("Press 3 to Add node at the Bigning of the linked list.\n");
		printf("Press 4 to add node at any position\n");
		printf("Press 5 to search the position of the element\n");
		printf("Press 6 to add node in the linked list after an element\n");
		printf("Press 7 to Add node at the End of the linked list.\n");
		printf("Press 8 to Exit.\n");

		scanf("%d", &option);

		switch(option){
			case 1:
				display(head);
				break;
			case 2:
				printf("Enter the element to insert: ");
				scanf("%d", &val);
				head = addmid(val, head);
				break;
			case 3:
				printf("Enter the element to insert: ");
				scanf("%d", &val);
				head = addbig(val, head);
				break;
			case 4:
				printf("Enter the position to insert after an element: ");
				scanf("%d", &pos);
				printf("Enter the element to insert on that position: ");
				scanf("%d", &val);
				addpos(pos, val, head);
				break;
			case 5:
				printf("Enter the element to search the position of the element: ");
				scanf("%d", &pos);
				searchpos(pos, head);
				break;
			case 6:
				printf("Enter the element after which you want to insert the new element: ");
				scanf("%d", &addafter);
				printf("Enter the new element to insert after that: ");
				scanf("%d", &val);
				head = affterelement(addafter, val, head);
				break;
			case 7:
				printf("Enter the element to insert: ");
				scanf("%d", &val);
				head = addnode(val, head);
				break;
			case 8:
				i=0;
				break;
			default:
				printf("\nSelect the correct option\n\n");
		}
	}

}