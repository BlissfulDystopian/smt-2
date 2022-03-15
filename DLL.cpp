#include <iostream>
  
struct Node {
	int val;
	Node *next, *prev;
};
int indexCount(Node **head) {
	Node *curr = (*head);
	int count = 0;
	while(curr != nullptr) {
		count++;
		curr = curr->next;	
	}
	return count;
}
void init(Node **head, Node **tail) {
	int count = 0;
	Node *del, *curr = (*head);
	while(count <= indexCount(head)) {
		std::cout << count << std::endl;
		del = curr;
		curr = curr->next;
		delete del;
		count++;
	}
	(*head) = (*tail) = nullptr;
}
Node *createNode(int val) {
	Node *newNode = new Node;
	newNode->val = val;
	newNode->next = newNode->prev = nullptr;
	return newNode;
}
void pushHead(Node **head, Node **tail, int val) {
	if((*head) == nullptr) {
		Node *newNode = createNode(val);
		(*head) = (*tail) = newNode;
	}else {
		Node *newNode = createNode(val);
		newNode->next = (*head);
		(*head)->prev = newNode;
		(*head) = newNode;
	}
}
void pushTail(Node **head, Node **tail, int val) {
	if((*head) == nullptr) {
		Node *newNode = createNode(val);
		(*head) = (*tail) = newNode;
	}else {
		Node *newNode = createNode(val);
		newNode->prev = (*tail);
		(*tail)->next = newNode;
		(*tail) = newNode;
	}
}
/*
	- if you passed 0, this program will insult you for your chronic ignorance
	- if you passed 1 or ignore 4th parameter, it'll allocate a memory on head
	- if you passed number way way above indexes you have, it'll allocate that on tail
	- if you pass as it should be, YOU BET :)))))))
*/
void push(Node **head, Node **tail, int val, int index = 1) {
	if((*head) == nullptr) {
		Node *newNode = createNode(val);
		(*head) = (*tail) = newNode;	
	} else if(index > 0 && index <= indexCount(head)) {
		int count = 1;
		Node *curr = (*head);
		while(count < index - 1) {
			curr = curr->next;
			count++;
		}
		if(curr == (*head)) {
			pushHead(head, tail, val);
		}
		else {
			Node *newNode = createNode(val), *temp = curr->next;
			newNode->prev = curr;
			newNode->next = curr->next; 
			curr->next = newNode;
			temp->prev = newNode;
		}
	} else if(index >= indexCount(head)) {
		pushTail(head, tail, val);
		std::cout << "There's no index " << index << ", So we Allocate yours on tail or index = "
		<< indexCount(head) << std::endl;
	}else {
		std::cout << "There's no index 0 you dummy dumb!'\n";
	}
}
void popHead(Node **head, Node **tail) {
	if((*head) == nullptr) {
		std::cout << "there's nothing to delete, PUNKS!" << std::endl;
	}else if((*head) == (*tail)) {
		Node *del = (*head);
		(*head) = (*tail) = nullptr;
		delete del;
		std::cout << "Cleared" << std::endl;
	}else {
		Node *del = (*head);
		(*head) = (*head)->next;
		(*head)->prev = nullptr;
		delete del; 
	}
}
void popTail(Node **head, Node **tail) {
	if((*tail) == nullptr) {
		std::cout << "there's nothing to delete, PUNKS!" << std::endl;
	}else if((*tail) == (*head)) {
		Node *del = (*tail);
		(*tail) = (*head) = nullptr;
		delete del;
		std::cout << "Cleared" << std::endl;
	}else {
		Node *del = (*tail);
		(*tail) = (*tail)->prev;
		(*tail)->next = nullptr;
		delete del; 
	}
}
void pop(Node **head, Node **tail, int index = 1) {
	if((*head) == nullptr) {
		std::cout << "there's nothing to delete, PUNKS!" << std::endl;
	}else if((*head) == (*tail)) {
		Node *del = (*head);
		(*head) = (*tail) = nullptr;
		delete del;
	}
	else if(index > 0 && index <= indexCount(head)) {
		int count = 1;
		Node *curr = (*head);
		while(count < index - 1) {
			curr = curr->next;
			count++;
		}
		if(curr == (*head)) {
			popHead(head, tail);
		}
		else {
			Node *del = curr, *temp = curr->prev;
			curr = curr->next;
			temp->next = curr;
			curr->prev = temp;
			delete del;
		}
	} else if(index >= indexCount(head)) {
		popTail(head, tail);
		std::cout << "There's no index " << index << ", So we Delete at tail index = "
		<< indexCount(head) << std::endl;
	}else {
		std::cout << "There's no index 0 you dummy dumb!'\n";
	}
}
void print(Node **head) {
	Node *curr = (*head);
	std::cout << "===================\n=======head======\n" << std::endl;
	while(curr != nullptr) {
		std::cout << curr->val << std::endl;
		curr = curr->next;	
	}
}
void printx(Node **tail) {
	Node *curr = (*tail);
	std::cout << "===================\n=======tail======\n" << std::endl;
	while(curr != nullptr) {
		std::cout << curr->val << std::endl;
		curr = curr->prev;	
	}
}
int main() {
	Node *head = nullptr, *tail = nullptr;
	
	push(&head, &tail, 12);
	push(&head, &tail, 11);
	push(&head, &tail, 10);
	print(&head);
	
	push(&head, &tail, 60);
	print(&head);
	
	pop(&head, &tail, 100);
	print(&head);
	
	push(&head, &tail, 12);
	print(&head);
	
	popHead(&head, &tail);
	print(&head);
	
	printx(&tail);
	std::cout << indexCount(&head) << std::endl;
	
	init(&head, &tail);
	print(&head);
	return 0;
}
