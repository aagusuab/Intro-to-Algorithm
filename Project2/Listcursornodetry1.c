#include <stdio.h>
#include "List.h"
#include <stdlib.h>

//NodeObj type---------------------
typedef struct NodeObj {
	int data;
	struct NodeObj* next;
	struct NodeObj* prev;
	struct NodeObj* cursor;
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
void freeNode(Node* pN) {
	if (pN== NULL && *pN == NULL) {
		free(*pN);
		*pN = NULL;
	}
};
//ListObj type-------
typedef struct ListObj {
	Node front;
	Node back;
	int length;
	int cindex;
	Node cursor;
}ListObj;
// Constructors-Destructors ---------------------------------------------------
List newList() {
	List newList;
	newList = malloc(sizeof(ListObj));
	newList->front = NULL;
	newList->back = NULL;
	newList->cursor = NULL;
	newList->length = 0;
	newList->cindex = -1;
	return newList;
};

void freeList(List* pL) {
	if (pL == NULL || *pL == NULL) {
		while (length(*pL) != 0)
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
		return L->cindex;
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
		else if(L-> cursor == NULL){
		printf("The cursor is NULL");
		exit(1);
		}
		else {
			return L->cursor->data;
		}
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
				for (int i = 0; i < A->length; i++) {
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
				moveFront(L);
			for(int i = 0; i < L->length - 1; i++){
				L->cursor = L->cursor->next;
				L->cursor->prev = NULL;
				freeNode(&L->cursor->prev);
				}
				freeNode(&L->cursor);
			L->back = NULL;
			L->front = NULL;
			L->cursor = NULL;
			L->length = 0;
			}
		};
		void moveFront(List L) {
			if (L == NULL) {
			printf("The List is NULL");
			exit(1);
			}
			else if (L->front != L->back) {
				L->cursor = L->front;
			}
		}
	void moveBack(List L) {
		if (L == NULL) {
			printf("The List is NULL");
			exit(1);
			}
		else if (L->front != L->back) {
			L->cursor = L->back;
		}
		};
		
	void movePrev(List L) {
		if (L == NULL) {
			printf("The List is NULL");
			exit(1);
			}
			else if(L->cursor == L->front){
				Node nNode = newNode(-1);
			L->cursor->prev = nNode;
			nNode->next = L->cursor;
			}
			else{
		L->cursor = L->cursor->prev;
			}
	}
	void moveNext(List L) {
		if (L == NULL) {
			printf("The List is NULL");
			exit(1);
			}
		else if(L->cursor == L->back){
			Node nNode = newNode(-1);
			L->cursor->next = nNode;
			nNode->prev = L->cursor;
			}
		else{
			L->cursor = L->cursor->next;
			}
	}
		

	void prepend(List L, int data) {
		if (L == NULL) {
			printf("The List is NULL");
			exit(1);
			}
			else{
		if (L-> front == NULL && L-> back == NULL) {
			Node nNode = newNode(data);
			L->front = nNode;
			L->back = nNode;
			L->cursor = nNode;
		}
		else {
			if (L->front == NULL) {
				Node nNode = newNode(data);
				nNode->next = (L->front);
				L->front->prev = nNode;
				L->front = nNode;
				L->cursor = L->front->next;
			}
			else {
				Node nNode = newNode(data);
				nNode->next = L->front;
				L->front->prev = (nNode);
				L->front = nNode;
				if(L->cursor == NULL){
				L->cursor = L->front->next;
				}
			}
			
		}

		L->length++;
	}
	}

	void append(List L, int data) {
	if (L == NULL) {
			printf("The List is NULL");
			exit(1);
			}
			else{
		if (L-> front == NULL && L-> back == NULL) {
			Node nNode = newNode(data);
			L->front = nNode;
			L->back = nNode;
			L->cursor = nNode;
		}
		else {
			if (L->back == NULL) {
				Node nNode = newNode(data);
				nNode->prev = (L->back);
				L->back->next = nNode;
				L->back = nNode;
			}
			else {
				Node nNode = newNode(data);
				nNode->prev = L->back;
				L->back->next = (nNode);
				L->back = nNode;
				if(L->cursor == NULL){
				L->cursor = L->back;
				}
			}
			
		}

		L->length++;
	}
	}

void insertBefore(List L, int data) { // Insert new element before cursor
	if (L == NULL) {
			printf("The List is NULL");
			exit(1);
			}
	else if(L->length < 0){
	printf("The list is empty");
	exit(1);
	}
	else{
	Node nNode = newNode(data); 
	if(L->cursor->prev == NULL){
	nNode->next = L->cursor;
	L->cursor->prev = nNode;
	}
	else{
	L->cursor->prev->next = nNode;
	nNode->prev = L->cursor->prev;
	nNode->next = L->cursor;
	L->cursor->prev = nNode;
	}
	}

	L->length++;
			}

void insertAfter(List L, int data) {  // Inserts new element after cursor.
	if (L == NULL) {
			printf("The List is NULL");
			exit(1);
			}
	else if(L->length < 0){
	printf("The list is empty");
	exit(1);
	}
	else{
	Node nNode = newNode(data); 
	if(L->cursor->next == NULL){
	nNode->prev = L->cursor;
	L->cursor->next = nNode;
	}
	else{
	L->cursor->next->prev = nNode;
	nNode->next = L->cursor->prev;
	nNode->prev = L->cursor;
	L->cursor->next = nNode;
	}
	}

	L->length++;
			}

void deleteFront(List L) { // Deletes the front element. Pre: length()>0
	if (L == NULL) {
		printf("The List is NULL");
		exit(1);
			}
	else if(L->front == NULL){
		L->front = L->front->next;
			}
	else  if (L->length == 1) {
		Node temp = L->front;
		L->front = NULL;
		freeNode(&temp);
	}
	else if (L->length > 0) {
		Node temp = L->front;
		Node a = L->front->next;
		a->prev = NULL;
		L->front = a;
		if (L->cindex != -1) L->cindex--;
		if (L->cursor == temp)
			L->cursor = NULL;
		freeNode(&temp);
	} L->length--;
}
void deleteBack(List L) {  // Deletes the back element. Pre: length()>0
	if (L == NULL) {
		printf("The List is NULL");
		exit(1);
			}
	else if(L->back == NULL){
		L->back = L->back->prev;
			}
	else  if (L->length == 1) {
		Node temp = L->back;
		L->back = NULL;
		freeNode(&temp);
	}
			
	else if (L->length > 0) {
		Node temp = L->back;
		Node temp2 = L->back->prev;
		temp2->next = NULL;
		L->back = temp2;
		if (L->cursor == temp) 
			L->cursor = NULL;
		freeNode(&temp);
	} L->length--;
	}


void delete(List L) {           // Deletes cursor element, making cursor undefined
	if (L == NULL) {
		printf("The List is NULL");
		exit(1);
			}
	else if(L->cindex < 0){
	printf("Undefined cursor");
	exit(1);
	}
	else if (L->length>0) {
		if (L->cursor == L->front) {
			deleteFront(L);
		}
		else if (L->cursor == L->back) {
			deleteBack(L);

		}
		else {
			Node temp1 = L->cursor->prev;
			Node temp2 = L->cursor->next;
			freeNode(&L->cursor);
			temp1->next = temp2;
			temp2->prev = temp1;
		}

	}L->length--;
}
// Other operations -----------------------------------------------------------
void printList(FILE* out, List L) {
	if (L == NULL) {
		printf("The List is NULL");
		exit(1);
			}
			else{
	Node temp = L->cursor;

	 if (L->front == NULL && L-> back == NULL) {
		printf(" ");
	}
	else {

		moveFront(L);
		for (int i = 0; i < L->length - 1; i++) {
			fprintf(out, "%d", get(L));
			fprintf(out, "\n");
			moveNext(L);
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
