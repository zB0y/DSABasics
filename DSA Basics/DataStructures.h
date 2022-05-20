#include <iostream>
#include <chrono>
#include <stack>
#include <queue>
#include <vector>
#include<unordered_map>
using namespace std::chrono; //
using namespace std;
#pragma once

//ARRAY (DONE!)
void ArrayLoop(vector<int>* user, bool x)
{
	while (x)
	{
		int y;
		cout << "\nThings you can do with your array:\n1. Insert element at 'back'\n2. Insert element at index\n3. Delete element at 'back'\n4. Delete element at index\n5. Print size of array\n6. Print capacity of array\n7. Print all elements from array\n8. Exit\nPlease select an option: ";
		cin >> y;
		switch (y)
		{
		case 1:
		{
			int v = 0;
			cout << "\nValue: ";
			cin >> v;
			user->push_back(v);
			break;
		}
		case 2:
		{
			int v = 0, index = 0;
			cout << "\nValue: ";
			cin >> v;
			cout << "\nIndex: ";
			cin >> index;
			if(index < 0 || index > user->size()) 
			{
				cout << "\nError: Cannot select an index value greater than the size of the array or less than zero.\nTry again!";
				break;
			}
			user->insert(user->begin() + index, v);
			break;
		}
		case 3:
		{
			user->pop_back();
			break;
		}
		case 4:
		{
			int index = 0;
			cout << "Index: ";
			cin >> index;
			if (index < 0 || index > user->size())
			{
				cout << "\nError: Cannot select an index value greater than the size of the array or less than zero.\nTry again!";
				break;
			}
			user->erase(user->begin() + index);
			break;
		}
		case 5:
		{
			cout << "\nSize of array = " << user->size();
			break;
		}
		case 6:
		{
			cout << "\nCapacity of array = " << user->capacity();
			break;
		}
		case 7:
		{
			for (int i = 0; i < user->size(); i++)
			{
				cout << user->at(i) << " ";
			}
			cout << "" << endl;
			break;
		}
		case 8:
		{
			x = false;
			break;
		}
		default:
		{
			cout << "\nPlease select an appropriate option!";
			break;
		}
		}
	}
}
//END OF ARRAY

//LINKED LIST (DONE!)
class Node //why did you make all of the functions "friend" functions?
{
	int data;
	Node* next;
	Node() {}
	Node(int val)
	{
		data = val;
		next = nullptr;
	}
	Node(int val, Node* pointer)
	{
		data = val;
		next = pointer;
	}
	friend Node* CreateList(int n);
	friend void PrintLinkedList(Node* A);
	friend void PrintRecursive(Node* (&A));
	friend void PrintReverseRecursive(Node* (&A));
	friend void Insert(Node* (&A), int value, int index);
	friend void Delete(Node* (&A), int index);
	friend void ReverseIterative(Node* (&A));
	friend void ReverseRecursive(Node* (&temp), Node* (&A));
	friend void PushStackLL(Node* (&top), int x);
	friend void PopStackLL(Node* (&top));
	friend void PrintStackLL(Node* top);

	friend void QueueLLInitiate();
	friend void QueueLLInsert(Node* parent, int val);
	friend void QueueLLRemove(Node* parent);
	friend void QueueLLPrint(Node* parent);
};

void LLloop(Node* A, bool x)
{
	while (!x)
	{
		int y;
		cout << "\nThings you can do with your linked list:\n1. Print List (Iterative)\n2. Insert Node at Index\n3. Delete Node at Index\n4. Reverse Linked List (Iterative)\n5. Reverse Linked List (Recursion)\n6. Print (Recursion)\n7. Print Reverse (Recursion) *DOESN'T CHANGE LINKED LIST\n8. Exit\n Please select an option: "; //Maybe implement search algorithms later to review them as well
		cin >> y;
		switch (y)
		{
		case 1:
		{
			PrintLinkedList(A);
			break;
		}
		case 2: //index goes from 1 to max value for ease of user
		{
			int ind, val;
			cout << "\nWhat would you like the effective index value of the new node to be? (Starts from 1) ";
			cin >> ind;
			cout << "\nWhat would you like the value to be? ";
			cin >> val;
			Insert(A, val, ind);
			break;
		}
		case 3:
		{
			int ind;
			cout << "\nWhat is the index value of the node you would like to delete? ";
			cin >> ind;
			Delete(A, ind);
			break;
		}
		case 4:
		{
			ReverseIterative(A);
			cout << "\nList reversed...";
			break;
		}
		case 5:
		{
			auto start = high_resolution_clock::now();
			Node* lmao = A;
			ReverseRecursive(lmao, A);
			auto end = high_resolution_clock::now();
			auto duration = duration_cast<nanoseconds>(end - start);
			cout << "\nTime taken to reverse linked list using recursion: " << duration.count() << " nanoseconds" << endl;
			cout << "\nList reversed...";
			break;
		}
		case 6:
		{
			cout << endl;
			auto start = high_resolution_clock::now();
			PrintRecursive(A);
			auto end = high_resolution_clock::now();
			auto duration = duration_cast<nanoseconds>(end - start);
			cout << "\nTime taken to print linked list using recursion: " << duration.count() << " nanoseconds" << endl;
			break;
		}
		case 7:
		{
			auto start = high_resolution_clock::now();
			PrintReverseRecursive(A);
			auto end = high_resolution_clock::now();
			auto duration = duration_cast<nanoseconds>(end - start);
			cout << "\nTime taken to print reverse of linked list using recursion (without changing the actual list): " << duration.count() << " nanoseconds" << endl;
			break;
		}
		case 8:
		{
			x = true;
			break;
		}
		default:
		{
			cout << "Invalid option selected. Exiting program.";
			break;
		}
		}
	}
}

Node* CreateList(int n) //n = no. of nodes
{
	Node* temp = new Node();
	cout << "1 node = ";
	cin >> temp->data;
	cout << endl;
	//temp->next = NULL;
	Node* pointerToFirst = temp;
	for (int i = 1; i < n; i++)
	{
		Node* temp1 = new Node();
		cout << i + 1 << " node = ";
		cin >> temp1->data;
		cout << endl;
		//temp1->next = NULL;
		temp->next = temp1;
		temp = temp1;
	}
	//temp = pointerToFirst;
	return(pointerToFirst);
}

void PrintLinkedList(Node* A)
{
	cout << endl;
	auto start = high_resolution_clock::now();
	Node* tempo = A;
	while (tempo != NULL)
	{
		cout << tempo->data << "-> ";
		tempo = tempo->next;
	}
	cout << "NULL";
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(end - start);
	cout << "\nTime taken to print linked list using iteration: " << duration.count() << " nanoseconds" << endl;
}

void PrintRecursive(Node* (&A))
{
	if (A == NULL) return;
	cout << A->data << "-> ";
	PrintRecursive(A->next);
}

void PrintReverseRecursive(Node* (&A))
{
	if (A == NULL) return;
	PrintReverseRecursive(A->next);
	cout << A->data << "-> ";
}

void Insert(Node* (&A), int value, int index)//call by reference
{
	//check if index is within that of the linked list
	Node* check = A;
	int count = 2;
	while (check != NULL)
	{
		count++;
		check = check->next;
	}
	Node* temp = new Node;
	temp->data = value;
	//temp->next = NULL;
	if (index == 1)
	{
		temp->next = A;
		A = temp;
	}
	else if ((1 < index) && (index < count)) //if there are 10 nodes, you can insert a new node such that it is effectively the 10th node (this will push the last node forward) or such that it is effectively the 11th node (thus c = max of list + 2)
	{
		Node* before = A;
		for (int i = 1; i < index - 1; i++)
		{
			before = before->next;
		}
		temp->next = before->next;
		before->next = temp;
	}
	else
	{
		cout << "Please enter a valid index value.";
	}
}

void Delete(Node* (&A), int index)
{
	//check if index is in list
	Node* check = A;
	int count = 1;
	while (check != NULL)
	{
		count++;
		check = check->next;
	}
	if (A != NULL)
	{
		Node* temp = A;
		if (index == 1)
		{
			/*A = temp->next;
			free(temp);*/
			Node* temp = A->next;
			A->next = NULL;
			A = temp;
		}
		else if ((1 < index) && (index < count))
		{
			for (int i = 1; i < index - 1; i++)
			{
				temp = temp->next;
			}
			Node* del = temp->next; //temp points to index - 1 whereas del points to index
			temp->next = del->next;
			del->next = NULL;
		}
		else
		{
			cout << "\nPlease enter a valid index value.";
		}
	}
	else if ((A != NULL) && (A->next == NULL))
	{
		A = NULL; //are you sure this works? what if you have a single node and the user passes an index greater than 1?
	}
	else
	{
		cout << "\nList is empty...";
	}
}

void ReverseIterative(Node* (&A))
{
	auto start = high_resolution_clock::now();
	Node *before, *on, *after;
	on = A;
	before = NULL;
	while (on != NULL)
	{
		after = on->next;
		on->next = before;
		before = on;
		on = after;
	}
	A = before;
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(end - start);
	cout << "\nTime taken to reverse linked list using iteration: " << duration.count() << " nanoseconds" << endl;
}

void ReverseRecursive(Node* (&temp), Node* (&A))//reverse of the last node is not called in this recursion because the if has a return statement
{
	if(temp->next == NULL)
	{
		A = temp;
		return;
	}
	ReverseRecursive(temp->next, A);
	Node* temp1 = temp->next;
	temp1->next = temp;
	temp->next = NULL;
}
//logic of insert is correct (at beginning should be O(1), at end should be O(n), at nth position should be O(n))
//logic of delete (check O())
//logic of reverse (iterative)
//logic of reverse (recursion)
//END OF LINKED LIST

//2D ARRAY DONE!
void TwoDArrayLoop(vector<vector<int>> user, bool x)
{
	int max;
	cout << "To implement a strict 2D Array, we will first need to set its max capacity. What value would you like its length or width to be?\nValue: ";
	cin >> max;
	for (int i = 0; i < max; i++)
	{
		vector<int>* temp = new vector<int>;
		for (int j = 0; j < max; j++) //I need to make an empty 2D array so that the user can access the blocks... without it, we won't be able to access anything... i think
		{
			temp->push_back(NULL);
		}
		user.push_back(*temp);
	}
	cout << "\nYour 2D array will essentially be a " << max << " x " << max << " matrix.\n";
	while (!x)
	{
		int y;
		cout << "Things you can do with your 2D Array:\n1. Insert element at block\n2.Delete element from block\n3. Print 2D Array\n4. Rotate to Right\n5. Rotate to Left\n6. Depth-First Search for value\n7. Breadth-First Search for value\n8. Exit\nPlease select an option: ";
		cin >> y;
		switch (y)
		{
		case 1:
		{
			int row, col, value;
			cout << "\nPlease enter a value greater than or equal to zero and less than " << max << ".\nRow: ";
			cin >> row; 
			cout << "\nPlease enter a value greater than or equal to zero and less than " << max << ".\nColumn: ";
			cin >> col;
			cout << "\nValue: ";
			cin >> value;
			user[row][col] = value;
			break;
		}
		case 2:
		{
			int row, col;
			cout << "\nPlease enter a value greater than or equal to zero and less than " << max << ".\nRow: ";
			cin >> row;
			cout << "\nPlease enter a value greater than or equal to zero and less than " << max << ".\nColumn: ";
			cin >> col;
			user[row][col] = NULL;
			break;
		}
		case 3:
		{
			for (int i = 0; i < user.size(); i++)
			{
				cout << "\n[";
				for (int j : user[i])
				{
					cout << j << " ";
				}
				cout << "]\n";
			}
			break;
		}
		case 4:
		{
			int n = user.size();
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j <= i; j++) swap(user[i][j], user[j][i]);
			}
			for (int i = 0; i < n; i++) reverse(user[i].begin(), user[i].end());

			break;
		}
		case 5:
		{
			int n = user.size();
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j <= i; j++) swap(user[i][j], user[j][i]);
			}

			break;
		}
		case 6:
		{

			break;
		}
		case 7:
		{

			break;
		}
		case 8:
		{
			x = true;
			break;
		}
		default:
		{
			cout << "\nPlease select an appropriate option.";
			break;
		}
		}
	}
}
//END OF 2D ARRAY

//DOUBLY LINKED LIST (DONE!)
class DNode
{
	int data;
	DNode* next;
	DNode* prev;
	friend void InsertAtHead(DNode* (&A), int value);
	friend void PrintDLL(DNode* (&A));
	friend void ReversePrintDLL(DNode* (&A));
	friend void InsertAtTail(DNode* (&A), int value);
};

void DLLloop(DNode* (&B), bool x)
{
	while (x != false)
	{
		int y;
		cout << "\nThings you can do with your Doubly Linked List:\n1. Insert at head\n2. Print\n3. Reverse Print\n4. Insert at tail\n5. Exit\nPlease select an option: ";
		cin >> y;
		switch (y)
		{
		case 1:
		{
			int v;
			cout << "\nValue = ";
			cin >> v;
			InsertAtHead(B, v);
			break;
		}
		case 2:
		{
			PrintDLL(B);
			break;
		}
		case 3:
		{
			ReversePrintDLL(B);
			break;
		}
		case 4:
		{
			int v;
			cout << "\nValue = ";
			cin >> v;
			InsertAtTail(B, v);
			break;
		}
		case 5:
		{
			x = false;
			break;
		}
		default:
		{
			cout << "\nPlease select a valid option.";
			break;
		}
		}
	}
}

void InsertAtHead(DNode* (&A), int value)
{
	DNode* tempo = new DNode;
	tempo->data = value;
	tempo->next = NULL;//why do i have to do this for DLL and didn't have to do it for LL?
	tempo->prev = NULL;
	if (A == NULL)
	{
		A = tempo;
		return;
	}
	A->prev = tempo;
	tempo->next = A;
	A = tempo;
}

void InsertAtTail(DNode* (&A), int value)
{
	DNode* temp1 = new DNode;
	temp1->data = value;
	temp1->next = NULL;
	temp1->prev = NULL;
	if (A == NULL)
	{
		A = temp1;
		return;
	}
	DNode* count = A;
	while (count->next != NULL)
	{
		count = count->next;
	}
	count->next = temp1;
	temp1->prev = count;
	return;
}

void PrintDLL(DNode* (&A))
{
	cout << endl;
	DNode* tempo = A;
	while (tempo != NULL)
	{
		cout << tempo->data << " <-> ";
		tempo = tempo->next;
	}
	cout << "NULL";
}

void ReversePrintDLL(DNode* (&A))
{
	cout << endl;
	DNode* temp = A;
	if (temp == NULL)
	{
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	cout << "Reverse: ";
	while (temp != NULL)
	{
		cout << temp->data << " <-> ";
		temp = temp->prev;
	}
	cout << "NULL";
}
//END OF DOUBLY LINKED LIST

//STACK (ARRAY) (DONE!)
class ztack
{
	int stackArray[101];
	int top = -1;
	friend void PushStackArray(ztack(&zoheb), int x);
	friend void PullStackArray(ztack(&zoheb));
	friend void PrintTop(ztack(&zoheb));
	friend void PrintStack(ztack(&zoheb));
};

void stackArrayLoop(ztack(&zoheb), bool x)
{
	while (x != false)
	{
		int y;
		cout << "\nThings you can do with the stack data structure:\n1. Push\n2. Pull\n3. Print Top value\n4. Print Stack\n5. Exit\nPlease select an option: ";
		cin >> y;
		switch (y)
		{
		case 1:
		{
			int value;
			cout << endl << "Value = ";
			cin >> value;
			PushStackArray(zoheb, value);
			break;
		}
		case 2:
		{
			PullStackArray(zoheb);
			break;
		}
		case 3:
		{
			PrintTop(zoheb);
			break;
		}
		case 4:
		{
			PrintStack(zoheb);
			break;
		}
		case 5:
		{
			x = false;
			break;
		}
		default:
		{
			cout << "\nPlease select a valid option.";
			break;
		}
		}
	}
}

void PushStackArray(ztack (&zoheb), int x)
{
	if (zoheb.top == 100)
	{
		cout << "\nError: Stack Overflow";
		return;
		//use the overflow function
	}
	zoheb.top++;
	zoheb.stackArray[zoheb.top] = x;
	return;
}

void PullStackArray(ztack (&zoheb))
{
	if (zoheb.top == -1)
	{
		cout << "\nError: Stack Underflow";
		return;
	}
	zoheb.top--;
	return;
}

void PrintTop(ztack(&zoheb))
{
	cout << "\nTop Index = " << zoheb.top << "\nValue at Top = " << zoheb.stackArray[zoheb.top];
}

void PrintStack(ztack(&zoheb))
{
	cout << "\nStack: ";
	for (int i = 0; i <= zoheb.top; i++)
	{
		cout << zoheb.stackArray[i];
		if (i != zoheb.top)
		{
			cout << ", ";
		}
	}
	return;
}
//END OF STACK (ARRAY)

//STACK (LL)
void StackLLloop(Node* (&top), bool x)
{
	while (x != false)
	{
		int y;
		cout << "\nThings you can do with your Stack (Linked List):\n1. Push element\n2. Pop element\n3. Print Stack\n4. Exit\nPlease pick an option: ";
		cin >> y;
		switch (y)
		{
		case 1:
		{
			int value;
			cout << "\nValue = ";
			cin >> value;
			PushStackLL(top, value);
			break;
		}
		case 2:
		{
			PopStackLL(top);
			break;
		}
		case 3:
		{
			PrintStackLL(top);
			break;
		}
		case 4:
		{
			x = true;
			break;
		}
		default:
		{
			cout << "\nPlease select a valid option!";
			break;
		}
		}
	}
}

void PushStackLL(Node* (&top), int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->next = top;
	top = temp;
}

void PopStackLL(Node* (&top))
{
	if (top == NULL)
	{
		cout << "\nError: Stack Underflow!";
		return;
	}
	Node* temp = top->next;
	top->next = NULL;
	top = temp;
}

void PrintStackLL(Node* top)
{
	cout << "\nTop to bottom order.\nStack(Linked List) : ";
	Node* i = top;
	while (i != NULL)
	{
		cout << i->data << ", ";
		i = i->next;
	}
	cout << "NULL";
}
//END OF STACK (LL)

//REVERSE STRING (USING STACK FROM STL) Please fix this!
void InitializeString(char takeIn[])
{
	cout << "Please enter a string (don't use space): ";
	cin >> takeIn;
}

void PrintString(char takeOut[], int n)
{
	cout << endl;
	if (takeOut[0] != NULL)
	{
		int i = 0;
		while (takeOut[i] != NULL)
		{
			cout << takeOut[i];
			i++;
		}
	}
	else
	{
		int i = 0;
		while (takeOut[i] == NULL)
		{
			i++;
		}
		for (i; i > 0; i--)
		{
			cout << takeOut[i];
		}
	}
	/*
	for (int i = 0; i < n; i++)
	{
		cout << takeOut[i];
	}*/
}

void Reverse(char *C, int n)
{
	stack<char> S;
	for (int i = 0; i < n; i++)
	{
		S.push(C[i]);
	}
	for (int i = 0; i < n; i++)
	{
		C[i] = S.top();
		S.pop();
	}
	//O(n)
} //space and time are both big o of n
//END OF REVERSE STRING (USING STACK FROM STL)

//QUEUE (ARRAY) DONE!
void PushQueueArray(int q[], int* tI, int v)
{
	if (*tI == 49)
	{
		cout << "\nError: Stack Overflow";
		return;
	}
	(*tI)++;
	q[(*tI)] = v;
}

void PopQueueArray(int q[], int* tI)
{
	int j = 1;
	if (*tI > 0)
	{
		for (int i = 0; i < (*tI) + 1; i++)
		{
			q[i] = q[j];
			j++;
		}
		q[j] = NULL;
		(*tI)--;
	}
	else if (*tI == 0)
	{
		q[(*tI)] = NULL;
		(*tI)--;
	}
	else
	{
		cout << "\nError: Stack Underflow";
		return;
	}
}

void PrintQueueArray(int q[], int* tI)
{
	cout << "\nFrom first to last.\nQueue (Array): ";
	if ((*tI) >= 0)
	{
		for (int i = 0; i < (*tI) + 1; i++)
		{
			cout << q[i] << ", ";
		}
	}
	else cout << "NULL";
}

void QueueLoop(int user[], int* tI, bool x)
{
	while (!x)
	{
		int y;
		cout << "\nThings you can do with a Queue (Array):\n1. Push\n2. Pop\n3. Print Queue\n4. Exit\nPlease select an option: ";
		cin >> y;
		switch (y)
		{
		case 1:
		{
			int value;
			cout << "Value = ";
			cin >> value;
			PushQueueArray(user, tI, value);
			break;
		}
		case 2:
		{
			PopQueueArray(user, tI);
			break;
		}
		case 3:
		{
			PrintQueueArray(user, tI);
			break;
		}
		case 4:
		{
			x = true;
			break;
		}
		default:
		{
			cout << "\nPlease enter a valid option!";
			break;
		}
		}
	}
}
//END OF QUEUE (ARRAY)

//QUEUE (LINKED LIST)
void QueueLLInitiate()
{
	/*int size, val;
	cout << "\nHow many elements would you like in the queue?\nPlease enter a value: ";
	cin >> size;
	cout << "\nElement 1 = ";
	cin >> val;
	Node* head = new Node(val);
	for (int i = 1; i < size; i++)
	{

	}*/
}

void QueueLLoop(bool loop, Node* head)
{
	while (loop == true)
	{
		int y;
		cout << "\nThings you can do with your Queue (Linked List):\n1. Insert element\n2. Remove element\n3. Print Queue\n4. Exit\nPlease pick an option: ";
		cin >> y;
		switch (y)
		{
		case 1:
		{
			int val;
			cout << "\nElement value: ";
			cin >> val;
			QueueLLInsert(head, val);
			break;
		}
		case 2:
		{
			QueueLLRemove(head);
			break;
		}
		case 3:
		{
			QueueLLPrint(head);
			break;
		}
		case 4:
		{
			loop = false;
			break;
		}
		}
	}
}

void QueueLLInsert(Node* parent, int val)
{
	Node* temp = parent;
	while (temp->next)
	{
		temp = temp->next;
	}
	Node* element = new Node(val);
	temp->next = element;
}

void QueueLLRemove(Node* parent)
{
	if (parent) parent = parent->next;
	else
	{
		cout << "Queue is empty. Try adding elements.";
	}
}

void QueueLLPrint(Node* parent)
{
	Node* temp = parent;
	while (temp->next)
	{
		cout << temp->data << "-> ";
		temp = temp->next;
	}
	cout << "NULL";
}

//END OF QUEUE (LINKED LIST)

//BST (this is janky initialization code i wrote in my second year, but no one is ever gonna read this anyways)
class BST 
{
	int data;
	BST* left, * right;

public:
	/*
	BST()
	{
		data = 0;
		left = right = NULL;
	}
	
		: data(0)
		, left(NULL)
		, right(NULL)
	{} //review contructor initialization...*/

	// Parameterized constructor.
	BST(int value)
	{
		data = value;
		left = right = NULL;
	};

	// Insert function.
	BST* Insert(BST* root, int value) //isn't balanced
	{
		/*if (!(root->data))
		{
			root->data = value;
			return root;
		}*/

		if (!root) //this means root is null
		{
			return new BST(value);
		}

		if (value > root->data)
		{
			root->right = Insert(root->right, value);
		}
		else
		{
			root->left = Insert(root->left, value);
		}

		return root;
	};
	friend void Inorder(BST* root);
	friend void Postorder(BST* root);
	friend void Preorder(BST* root);
	friend void BSTLoop(BST* bst, bool x);
	friend void printLevelOrder(BST* root);
	friend void printCurrentLevel(BST* root, int level);
	friend int height(BST* node);
};

//BFS traversal approach 1
void printLevelOrder(BST* root)
{
	int h = height(root);
	for (int i = 1; i <= h; i++)
	{
		printCurrentLevel(root, i);
	}
}

void printCurrentLevel(BST* root, int level)
{
	if (root == NULL) return;
	if (level == 1) //root node
	{
		cout << root->data << " ";
	}
	else if (level > 1)
	{
		printCurrentLevel(root->left, level - 1);
		printCurrentLevel(root->right, level - 1);
	}
}

int height(BST* node)
{
	if (node == NULL) return 0;
	else
	{
		int lHeight = height(node->left);
		int rHeight = height(node->right);

		if (lHeight > rHeight) return (++lHeight);
		else return (++rHeight);
	}
}
//BFS traversal approach 1

// Inorder traversal. LWR
void Inorder(BST* root)
{
	if (root->left) Inorder(root->left);
	std::cout << root->data << " ";
	if (root->right) Inorder(root->right);
};

// Postorder traversal. LRW
void Postorder(BST* root)
{
	if (root->left) Postorder(root->left);
	if (root->right) Postorder(root->right);
	std::cout << root->data << " ";
}

// Preorder traversal. WLR
void Preorder(BST* root)
{
	std::cout << root->data << " ";
	if (root->left) Postorder(root->left);
	if (root->right) Postorder(root->right);
}

void BSTLoop(BST* bst, bool x)
{
	while (x != false)
	{
		int y;
		cout << "\nThings you can do with your Binary Search Tree:\n1. Insert Element\n2. Print DFS: Inorder\n3. Print DFS: Preorder\n4. Print DFS: Postorder\n5. Print BFS (w/out Queue)\n6. Print BFS (using Queue)\n7. Exit\nPlease select an option: ";
		cin >> y;
		switch (y)
		{
		case 1:
		{
			int v;
			cout << "Value: ";
			cin >> v;
			bst = bst->Insert(bst, v);
			break;
		}
		case 2:
		{
			cout << endl;
			Inorder(bst);
			break;
		}
		case 3:
		{
			cout << endl;
			Preorder(bst);
			break;
		}
		case 4:
		{
			cout << endl;
			Postorder(bst);
			break;
		}
		case 5:
		{
			cout << endl;
			printLevelOrder(bst);
			break;
		}
		case 6:
		{
			break;
		}
		case 7:
		{
			x = false;
			break;
		}
		default:
		{
			cout << "\nPlease select a valid option!";
			break;
		}
		}
	}
}
//END OF BST

////Priority Queue/Heap Tree (Not the C++ container!)
/*void priorityQueueLoop(priority_queue<int> q, bool x)
{
	while (x != false)
	{
		int y;
		cout << "\nThings you can do with your Priority Queue (MAX):\n1. Push element\n2. Pop element\n3. Print Max Element (top)\nPlease select an option: ";
		cin >> y;
		switch (y)
		{
		case 1:
		{
			int v;
			cout << "\nValue: ";
			q.push(v);
			cin >> v;
			break;
		}
		case 2:
		{
			q.pop();
			break;
		}
		case 3:
		{
			cout << endl << q.top();
			break;
		}
		case 4:
		{
			break;
		}
		default:
		{
			cout << "\nPlease select a valid option.";
			break;
		}
		}
	}
}

template<typename T> void print_queue(T& q)
{
	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
}*/


//END OF PRIORITY QUEUE (NOT C++  CONTAINER)


//Graph (Adj. Matrix) Unweighted & Undirected (DONE!) Just ignore this loop now...
void GraphMatrixLoop(bool x)
{
	vector<vector<bool>> mainVector;
	cout << "\nThe adjacency matrix representation of the graph data structure uses a basic matrix where any given coordinate signifies a pair of vertices. The value stored is a boolean that represents whether an edge between the two vertices exists or not. Half of the matrix is the same as the other because this implementation is not directed.\n";
	while (x)
	{
		int y;
		cout << "\n1.Add vertex\n2.Print Adjacency Matrix\n3.Exit\nPlease select an option : ";
		cin >> y;
		switch (y)
		{
		case 1:
		{
			//need to add a new vector no matter what
			vector<bool> newVector;
			int newIndex = mainVector.size() + 1;
			cout << endl << "Return the following with '1' for true and '0' for false." << endl;
			for (int i = 0; i < mainVector.size(); i++) //should check all vectors including the new vector itself because i did till mainVector.size
			{
				bool j;
				cout << "Is vertex " << newIndex << " connected to vertex " << i + 1 << "?" << endl;
				cin >> j;
				newVector.push_back(j);
				mainVector[i].push_back(j);
			}
			mainVector.push_back(newVector);
			bool final;
			cout << "Is vertex " << newIndex << " connected to vertex " << newIndex << "?" << endl;
			cin >> final;
			mainVector[mainVector.size() - 1].push_back(final);
			cout << "Vertex " << newIndex << " successfuly added to Graph (and Adjacency Matrix)!";
			break;
		}
		case 2:
		{
			cout << " ";
			for (int x = 0; x < mainVector.size(); x++)
			{
				cout << x + 1 << " ";
			}
			cout << endl;
			for (int i = 0; i < mainVector.size(); i++)
			{
				cout << i + 1 << " ";
				for (int j = 0; j < mainVector.size(); j++)
				{
					if (mainVector[i][j])
						cout << "1 ";
					else
						cout << "0 ";
				}
				cout << endl;
			}
			break;
		}
		case 3:
		{
			x = false;
			break;
		}
		default:
		{
			cout << "Please select a valid option...";
		}
		}
	}
}

void GraphMatrixWeightedLoop(bool x)
{
	vector<vector<int>> mainVector;
	cout << "\nThe adjacency matrix representation of the graph data structure uses a basic matrix where any given coordinate signifies the weight of the edge connecting the two vertices. The value stored is an integer and is unique to the order of the way the vertices are paired (a to b is not the same as b to a).\n";
	while (x)
	{
		int y;
		cout << "\n1.Add vertex\n2.Print Adjacency Matrix\n3.Exit\nPlease select an option : ";
		cin >> y;
		switch (y)
		{
		case 1:
		{
			//need to add a new vector no matter what
			vector<int> newVector;
			int newIndex = mainVector.size() + 1;
			cout << endl << "Return the weight of the edge for the following vertices (with 0 representing no edge at all). Negative edges are allowed!" << endl;
			for (int i = 0; i < mainVector.size(); i++)
			{
				int j;
				cout << "Weight of edge from " << newIndex << " to " << i + 1 << "?" << endl;
				cin >> j;
				newVector.push_back(j);
				cout << "Weight of edge from " << i + 1 << " to " << newIndex << "?" << endl;
				cin >> j;
				mainVector[i].push_back(j);
			}
			mainVector.push_back(newVector);
			int final;
			cout << "Weight of edge from " << newIndex << " to " << newIndex << "?" << endl;
			cin >> final;
			mainVector[mainVector.size() - 1].push_back(final);
			cout << "Vertex " << newIndex << " successfuly added to Graph (and Adjacency Matrix)!";
			break;
		}
		case 2:
		{
			cout << " ";
			for (int x = 0; x < mainVector.size(); x++)
			{
				cout << x + 1 << " ";
			}
			cout << endl;
			for (int i = 0; i < mainVector.size(); i++)
			{
				cout << i + 1 << " ";
				for (int j = 0; j < mainVector.size(); j++)
				{
					cout << mainVector[i][j] << " ";
				}
				cout << endl;
			}
			break;
		}
		case 3:
		{
			x = false;
			break;
		}
		default:
		{
			cout << "Please select a valid option...";
		}
		}
	}
}
//Graph (Adj. Matrix) Unweighted & Undirected (DONE!) Just ignore this loop now...

//Graph (Adj. List)
void depthFirstPrintIterative(unordered_map<int, vector<int>*> List, int start) //iterative
{
	stack<int> printStack;
	unordered_map<int, bool> visited;
	printStack.push(start);

	while (printStack.size() > 0)
	{
		if (visited.find(printStack.top()) == visited.end() || visited[printStack.top()] == false)//then insert the number into the visited and print it
		{
			visited[printStack.top()] = true;
			int curr = printStack.top();
			printStack.pop();
			cout << curr << endl;
		}
		else
		{
			printStack.pop();
			if (printStack.size() <= 0) break;
		}
		int curr = printStack.top();
		printStack.pop();
		cout << curr << endl;

		for (auto i : (*List[curr])) //i represents the numbers in the vector associated to the vertex (curr)
		{
			printStack.push(i);
		}
	}
}

void depthFirstPrintRecursive(unordered_map<int, vector<int>*> List, unordered_map<int, bool>& visited, int start)//recursive
{
	visited[start] = true;
	cout << start << endl;

	for (auto i : (*List[start]))
	{
		if (!visited[i])
		{
			depthFirstPrintRecursive(List, visited, i);
		}
	}
}

void GraphListLoop(bool x)
{
	/*vector< vector< pair<int, int> > > mainVector; //maybe make a vector of unordered_maps where each index in the vector
	cout << "\nThe adjacency list representation of the graph data structure uses less space than the adjacency matrix representation. A main list stores a list per vertex where the list for a particular vertex stores only the vertices said vertex is connected (via a direct edge) with. I have only implemented the weighted and directed version because (as you may have already recognized from the adj. matrix code), there isn't much of a difference and an unweighted and undirected graph can still be made. Simply use '0' to denote that no edge exists (the code will detect the 0 and remove the edge), '1' to denote that it does, and store the same value for both values in the adjacency list in their respectful places.\n\n";
	while (x)
	{
		int y;
		cout << "\n1. Add vertex\n2. Add edge\n3. Print Adjacency List\n4. Depth-First Search\n5. Breadth-First Search\n6. Exit\nPlease select an option: ";
		cin >> y;
		switch (y)
		{
		case 1:
		{
			vector<pair<int,int>> newVertex;
			mainVector.push_back(newVertex);
			cout << "\nVertex added successfuly!\n";
			break;
		}
		case 2:
		{
			int v1, v2, weight;
			bool valid = false;
			cout << "\nFrom vertex: ";
			cin >> v1;
			cout << "\nTo vertex: ";
			cin >> v2;
			if (v1 > mainVector.size() || v2 > mainVector.size())
			{
				cout << "\nPlease enter valid vertices. There are only " << mainVector.size() << " vertices currently in the graph!\nKeep in mind that any vertex made so far is named by its index. Thus, all vertices in this graph are either less than or equal to " << mainVector.size() << ".";
				bool valid = false;
				while (!valid)
				{
					cout << "\nPlease try again...";
					cout << "\nFrom vertex: ";
					cin >> v1;
					cout << "\nTo vertex: ";
					cin >> v2;
					if (v1 <= mainVector.size() && v2 <= mainVector.size()) valid = true;
				}
			}
			cout << "\nWeight: ";
			cin >> weight;
			for (auto j : mainVector[v1 - 1])
			{
				if (j.first == v2 - 1) //the edge exists and now its weight is being updated
				{
					bool update;
					cout << "\nThis edge already exists. Would you really like to update its weight?\nPlease enter '1' for yes and '0' for no: ";
					cin >> update;
					if (update) j.second = weight;
				}
			}
			if (mainVector[v1 - 1][v2 - 1])mainVector[v1 - 1][v2 - 1] = weight; //v1 = 1 and v2 = 2 then mainVector[0][1] represents v1 to v2
			cout << "\nWeight from vertex " << v2 << " to vertex " << v1 << ": ";
			cin >> weight;
			mainVector[v2 - 1][v1 - 1] = weight;
			cout << "\nEdges added successfuly!";
			break;
		}
		case 3:
		{
			cout << "\nThe list for each source vertex represents the destination vertices and the weight of the respective edges to the respective destination vertices.\n";
			for (int i = 0; i < mainVector.size(); i++)
			{
				cout << "\nVertex " << i + 1 << ": ";
				for (int j = 0; j < mainVector[i].size(); j++)
				{
					cout << j + 1 << ", " << mainVector[i][j] << " | ";
				}
			}
			break;
		}
		case 6:
		{
			x = false;
			break;
		}
		default:
		{
			cout << "\nPlease select a valid option!";
			break;
		}
		}
	}*/

	//unweighted and undirected
	cout << "\nAdjacency list implementation of an unweighted and undirected graph.";
	unordered_map<int, vector<int>*> adjList; //starting with 1
	while (x)
	{
		int y;
		cout << "\n1. Add vertex\n2. Add edge\n3. Print Adjacency List\n4. DFS Print Adjacency List\n5. Depth-First Search\n6. Breadth-First Search\n7. Exit\nPlease select an option: ";
		cin >> y;
		switch (y)
		{
		case 1:
		{
			vector<int>* vertexList = new vector<int>;
			adjList[adjList.size() + 1] = vertexList;
			cout << "\nVertex added successfuly!\n";
			break;
		}
		case 2:
		{
			int v1, v2;
			bool valid = false;
			cout << "\nFrom vertex: ";
			cin >> v1;
			cout << "\nTo vertex: ";
			cin >> v2;
			if (v1 < 0 || v1 > adjList.size() || v2 < 0 || v2 > adjList.size())
			{
				cout << "\nPlease enter valid vertices. There are only " << adjList.size() << " vertices currently in the graph!\nKeep in mind that any vertex made so far is named by its index. Thus, all vertices in this graph are either less than or equal to " << adjList.size() << ", starting from 1.";
				bool valid = false;
				while (!valid)
				{
					cout << "\nPlease try again...";
					cout << "\nFrom vertex: ";
					cin >> v1;
					cout << "\nTo vertex: ";
					cin >> v2;
					if (v1 > 0 && v1 <= adjList.size() && v2 > 0 && v2 <= adjList.size()) valid = true;
				}
			}
			adjList[v1]->push_back(v2);
			adjList[v2]->push_back(v1); //please remember that the actual adjacency vector of a vertex doesn't store adjacent vertices in any order!
			cout << "\nEdges created successfuly!";
			break;
		}
		case 3:
		{
			cout << "Following is the Adjacency List of the graph:" << endl;
			for (auto i : adjList)
			{
				cout << i.first << ": ";
				for (auto j : *(i.second))
				{
					cout << j << ", ";
				}
				cout << endl;
			}
			break;
		}
		case 4:
		{
			depthFirstPrintIterative(adjList, 1);
			break;
		}
		default:
		{

			break;
		}
		}
	}
}

//Graph (Edge List)
void GraphEdgeListLoop(bool x)
{

}

//My Own Hash Map
/*class MyHashMap {
	vector<pair<int, int*>> ofKeys;
	//vector<int> justChecking;


public:
	MyHashMap() {
		ofKeys.reserve(1);
	}

	void put(int key, int value) {
		/*if (!(std::find(justChecking.begin(), justChecking.end(), key) != justChecking.end()))
		{
			justChecking.push_back(10);
		}*/
		/*if (!(std::find(ofKeys.begin(), ofKeys.end(), key) != ofKeys.end()))
		{
			cout << "ELEMENT NOT FOUND. ADD IT INTO THE ofKeys VECTOR!";
			/*pair<int, int*> testing;
			testing.first = key;
			*testing.second = value;
			ofKeys.push_back(testing);
		}*/
		/*else
		{
			cout << "ELEMENT FOUND????";
		}
	}

	int get(int key) {

	}

	void remove(int key) {

	}
};

void MyHashLoop(bool x)
{
	MyHashMap* zoheb = new MyHashMap();
	zoheb->put(10, 10);
	/*while (x != false)
	{
		
		int y;
		cout << "\n\nPlease select an option: ";
		cin >> y;
		switch (y)
		{
		case 1:
		{
			break;
		}
		}
	}
}*/