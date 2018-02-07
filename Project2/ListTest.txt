#include <stdio.h>
#include "List.h"
#include <stdlib.h>

//NodeObj type---------------------
typedef struct NodeObj {
	int data;
	struct NodeObj* next;
	struct NodeObj* prev;
} NodeObj;

typedef NodeObj* Node;
//Node Constructor/Destructor--------
Node newNode(int data) {
	Node nNode = malloc(sizeof(NodeObj));
	nNode->data = data;
	nNode->next = NULL;
	nNode->prev = NULL;
	return nNode;
};
void FreeNode(Node* pN) {
	if (pN!= NULL && *pN != NULL) {
		free(*pN);
		*pN = NULL;
	}
};
//ListObj type-------
typedef struct ListObj {
	Node front;
	Node back;
	int length;
	int cursor;	
}ListObj;
// Constructors-Destructors ---------------------------------------------------
List newList() {
	List newList;
	newList = malloc(sizeof(ListObj));
	newList->front = NULL;
	newList->back = NULL;
	newList->cursor = -1;
	newList->length = 0;
	return newList;
};

void freeList(List* pL) {
	if (pL == NULL || *pL == NULL) {
		return;
		while (length(*pL) != 0)
		{
			deleteFront(*pL);
		}
		free(*pL);
		*pL = NULL;
	}
};
// Access functions -----------------------------------------------------------
int length(List L){
	if (L == NULL) {
		printf("The List is NULL\n");
		exit(1);
	}
	else 
		return L->length;
	
};


	int index(List L) {
		if (L == NULL){
			printf("The List is NULL");
			exit(1);
		}
		else if(L-> cursor == -1){
			return -1;
		}
		else {
			return L->cursor;
		}
	};
	
	
	int front(List L) {
		if (L == NULL) {
			printf("The List is NULL");
			exit(1);
		}
		else if (L->length == 0) {
			return -1;
		}
		else {
			return L->front->data;
		}
	};
	
	int back(List L) {
		if (L == NULL) {
			printf("The List is NULL");
			exit(1);
		}
		else if (L->length == 0) {
			exit(1);
		}
		else {
			return L->back->data;
		}
	};
	int get(List L){
		if(L == NULL){
			printf("The List is NULL");
			exit(1);
		}
		else if(L->cursor == -1){
		printf("The cursor is undefined");
		exit(1);
		}
		else if (index(L) >= 0) { 
			Node temp = L->front;
			for (int i = 0; i < (L->cursor)-1; i++) {
				temp = temp->next;
			}
			if (temp == NULL) {
				return -1;
			}
			else {
				return temp->data;
			}
		}
		else{
		return -1;}
	};
	

		int equals(List A, List B) {
			if(A == NULL){
				printf("First List is NULL");
			exit(1);
			}
			else if(B == NULL){
				printf("Second List is NULL");
			exit(1);
			}
			else {
			moveFront(A);
			moveFront(B);
			int test = 0;
			if (A->back == A->front && B->back == B->front) {
				test = 1;
				
			}
			else if (A->length != B->length) {
				test = 0;
			}
			else if (A->length == B->length) {
				for (int i = 0; i < A->length-1; i++) {
					if (get(A) == get(B)) {
						test = 1;
						moveNext(A);
						moveNext(B);
					}
					else {
						test = 0;
					}
				}
			}
		return test;
			}
		};

// Manipulation procedures ----------------------------------------------------
		void clear(List L){
			if (L == NULL) {
			printf("The List is NULL");
			exit(1);
			}
			else{
			L->back = NULL;
			L->front = NULL;
			L->cursor = -1;
			L->length = 0;
			freeList(&L);
			}
		};
		void moveFront(List L) {
			if (L == NULL) {
			printf("The List is NULL");
			exit(1);
			}
			else if(L->front == L->back){
			L->cursor = 0;
			}
			else if (L->front != L->back) {
				L->cursor = 0;
			}
		}
	void moveBack(List L) {
		if (L == NULL) {
			printf("The List is NULL");
			exit(1);
			}
		else if(L->length == 1){
			L->cursor = 0;
			}
		else if(L->cursor == L->length-1){
			
		}
		else if (L->front != L->back) {
			L->cursor = L->length - 1;
		}
		
		};
		
	void movePrev(List L) {
		if (L == NULL) {
			printf("The List is NULL");
			exit(1);
			}
			else{
		L->cursor--;
			}
	}
	void moveNext(List L) {
		if (L == NULL) {
			printf("The List is NULL");
			exit(1);
			}
		if(L->cursor == -1){
			printf("Cursor doesn't exist");
			exit(1);
		}
		else if (L->length == 1){
		L->cursor = -1;
		}
		else if(L-> front != L-> back){
		if (L-> cursor == L-> length-1){
		L->cursor = -1;
		}
		else{
			L->cursor++;
			}
		}
	}
		

	void prepend(List L, int data) {
		if (L == NULL) {
			printf("The List is NULL");
			exit(1);
			}
			else{
		Node nNode = newNode(data);
		if (L-> front == NULL && L-> back == NULL) {
			L->front = nNode;
			L->back = nNode;
		}
		else {
			if (L->front == NULL) {
				nNode->next = (L->front);
				L->front->prev = nNode;
				L->front = nNode;
				L->cursor++;
			}
			else {
				nNode->next = L->front;
				L->front->prev = (nNode);
				L->front = nNode;
				L->cursor++;
			}
			
		}
		L->length++;
	}
	}

	void append(List L, int data) {
	if (L == NULL) {
		printf("List is NULL");
		exit (1);
	} else if (L->length == 0) {
		Node N = newNode(data);
		L->front = L->back = N;
		L->cursor = 0;
	} else {
		Node N = newNode(data);
		N->prev = L->back;
		L->back->next = N;
		L->back = N;
	}
	L->length++;
}

void insertBefore(List L, int data) { // Insert new element before cursor
	if (L == NULL) {
			printf("The List is NULL");
			exit(1);
			}
	else if(L->cursor == -1){
		printf("The cursor is NULL");
		exit(1);
	}else if(index(L) < 0){
	printf("The index is NULL");
	exit(1);
	}
	else if(L->length < 0){
	printf("The list is empty");
	exit(1);
	}
	else if(L->length == 0){
	Node nNode = newNode(data);
	L->front = nNode;
	L->back = nNode;
	L->cursor++;
	}
	else{
	Node nNode = newNode(data);    // Pre: length()>0, index()>=0
	Node temp = L->front;
	for (int i = 0; i < index(L); i++) {
		if (i == index(L)) {
		}
		temp = temp->next;
	}

	Node tempf = temp->prev;
	if (temp->prev == NULL) {
		nNode->next = L->front;
		L->front->prev = nNode;
		L->front = nNode;

	}
	else {
		nNode->prev = tempf;
		nNode->next = temp;
		temp->prev = nNode;

	}
	L->cursor++;
	L->length++;
	
			}
}
void insertAfter(List L, int data) {  // Inserts new element after cursor.
	if (L == NULL) {
		printf("The List is NULL");
		exit(1);
			}
	else if(L->length <= 0){
		printf("The length is 0");
		exit(1);
	}
	else{
	Node nNode = newNode(data);        // Pre: length()>0, index()>=0
	int temp2 = L->cursor;
	if(L->length == 1){
	nNode->prev = L->front;
	L->front->next =nNode; 
	}
	else if (L->cursor == 0) {
		nNode->next = L->front->next;
		nNode->prev = L->front;
		L->front->next = nNode;

	}
	
	else {
		Node temp = L->front;
		for (int i = 0; i < index(L); i++) {

			temp = temp->next;
		}
		if (temp->next == NULL) {
			nNode->prev = L->back;
			L->back->next = nNode;
			L->back = nNode;

		}
		else {
			Node tempb = temp->next;
			nNode->next = (tempb);
			nNode-> prev = (temp);
			temp -> prev =(nNode);

		}
	}
	L->cursor = temp2;
	L->length++;
}
}
void deleteFront(List L) { // Deletes the front element. Pre: length()>0
	if (L == NULL) {
		printf("The List is NULL");
		exit(1);
			}
	else if (length > 0) {
		Node temp = L->front->next;
		Node temp2 = L->front;
		FreeNode(&temp2);
		L->front = temp;
		L->front-> prev = NULL;
		L->cursor--;
		L->length--;
	}
}
void deleteBack(List L) {  // Deletes the back element. Pre: length()>0
	if (L == NULL) {
		printf("The List is NULL");
		exit(1);
			}
	else if (length > 0) {
		if (L->back == L->front) {
			L->back = NULL;
			L->front = NULL;
			L->length--;
		}
		else if(L->cursor == -1){
			
		}
		else if (L->cursor == L->length - 1) {
			L->back = L->back->prev;
			Node temp = L->back->next;
			FreeNode(&temp);
			L->length--;
			L->cursor = -1;
		}
		else {
			Node temp = L->back->prev;
			Node temp2 = L->back;
			FreeNode(&temp2);
			L->back = temp;
			L->length--;
		}
	}
}
void delete(List L) {           // Deletes cursor element, making cursor undefined
	if (L == NULL) {
		printf("The List is NULL");
		exit(1);
			}
			else if(L->cursor == -1 || L->length == 0){
			}
	if (L->length>0 && L->cursor >= 0) {   // Pre: length()>0, index()>=0
		if (L->cursor == 0) {
			deleteFront(L);
		}
		else if (L->cursor == L->length - 1) {
			deleteBack(L);

		}
		else {
			Node temp = L ->front;
			for (int i = 0; i< L->cursor; i++) {
				temp = temp->next;
			}
			Node tempb = temp->next;
			Node tempf = temp->prev;
			FreeNode(&temp);
			tempb->prev = tempf;
			tempf-> next = tempb;
			L->cursor--;
		}

	}
}
// Other operations -----------------------------------------------------------
void printList(FILE* out, List L) {
	if (L == NULL) {
		printf("The List is NULL");
		exit(1);
			}
			else{
	fprintf(out, "%d", get(L));
	int temp = L->cursor;

	 if (L->front == NULL && L-> back == NULL) {
		printf(" ");
	}
	else {

		moveFront(L);
		for (int i = 0; i < L->length - 1; i++) {
			fprintf(out, "%d", get(L));
			fprintf(out, "\n");
			L->cursor++;
		}
		L->cursor = temp;

	}
			}
};

List copyList(List L){ // Returns a new List representing the same integer sequence as this
	if (L == NULL) {
			printf("The List is NULL");
			exit(1);
			}
			else{
	List copied = newList();
	if (L-> front == NULL && L-> back == NULL) { 
	}
	else {
		copied = L;
	}
	return copied;

}
}
int isEmpty(List L){
	if(L == NULL){
		printf("The List is NULL");
		exit(1);
	}
	else if (L->front == NULL && L->back == NULL) {
		return 1;
	}
	else {
		return 0;
	}
	}
