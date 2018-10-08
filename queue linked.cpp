#include<stdio.h>
#include<stdlib.h>
struct node{
	int marks;
	node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int value);
void dequeue(void);
void Display(void);

main(){
	int marks,choice;
	node *front=NULL;
	node *rear=NULL;
	do{
	printf("\nEnter your choice:\n 1-Insert Data\t 2-Display Data \n 3-Delete Data\t 4-Exit \n");
	scanf("%d",&choice);
	printf("\n");
		switch(choice){
			case 1:{
				printf("\nEnter Marks = ");
	            scanf("%d",&marks);
	            enqueue(marks);
				break;
			}
			case 2:{
				Display();
				break;
			}
			case 3:{
				dequeue();
				Display();
				break;
			}
			default:
				printf("Wrong Input");
		}
	}
	while(choice!=4);
}
void enqueue(int value){
	node *newNode;
	node *Temp;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->marks = value;
	newNode->next = NULL;
	if(front == NULL)
	{
		front=rear = newNode;
		return;
	}
	else{
		Temp = rear;
		while(Temp->next != NULL)
		{
			Temp = Temp->next;
		}
		Temp->next = newNode;
		rear=newNode;
	}
}
void Display(void){
	struct node *Temp;
	Temp = front;
	if(Temp == NULL)
	printf("\nEmpty list");
	else{
	printf("*********QUEUE**********\n\n");
	while(Temp != NULL){
	printf("Marks = %d\n",Temp->marks);
	Temp = Temp->next;
}
printf("\n");
}
}
void dequeue(void){
	struct node *temp=front;
	if(front==NULL){
	printf("Queue is empty");
}
	else if(front==rear){
		free(front);
	front=rear=NULL;
}
	else{
			front=front->next;
			free(temp);
	}
	
}
	

