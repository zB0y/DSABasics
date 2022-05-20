#include <iostream>
#include "DataStructures.h"
#include <stack>
#include <queue>
#include <vector>
using namespace std;

//allow the user to only enter one data structure and then make it necessary for them to exit the program to use any other data structure (which obviously deletes the previous data)

int main()
{
	/*Node* zoheb = CreateList(10);
	PrintLinkedList(zoheb);*/
	int value;
	cout << "Welcome\n1. Array (DONE)\n2. Linked List (DONE)\n3. 2D Array (DONE)\n4. Doubly Linked List (DONE)\n5. Stack (Array Implementation) (DONE)\n6. Stack (Linked List Implementation)\n7. Using The STL Stack to Reverse a String (NEEDS TO BE FIXED)\n8. Queue (Array Implementation) (DONE)\n9. Queue (Linked List Implementation)\n10. Binary Search Tree\n11. Priority Queue/Heap Tree\n12. AVL Tree (Please practice rotation concepts and algorithms)\n13. Graph (Adjacency Matrix)\n14. Graph (Adjacency List)\n15. Graph (Edge List)\n16. My Own Hash Map Implementation for LeetCode\n17. Unordered Map (STL)\nWhich Data Structure would you like to use: "; //add more data structures to this list and then host this program on your personal website and/or on git InshaAllah
	cin >> value;
	cout << endl;
	switch (value)
	{
	case 1: //Array DONE!
	{
		vector<int>* user = new vector<int>;
		bool x = true;
		ArrayLoop(user, x);
		break;
	}
	case 2: //LL DONE!
	{
		int number, y;
		bool x = false;
		cout << "Linked List: This data structure links nodes by saving the address of the next node in each respective node. Let's create a linked list." << endl << "How many nodes would you like in the linked list? ";
		cin >> number;
		Node* user = CreateList(number);
		PrintLinkedList(user);
		LLloop(user, x);
		break;
	}
	case 3: //2D Array DONE!
	{
		vector<vector<int>> user;
		bool x = false;
		TwoDArrayLoop(user, x);
		break;
	}
	case 4: //DLL DONE!
	{
		cout << "Doubly Linked List: Each node (other than the first and last node) points to the node ahead and the node prior to itself. Let's create a doubly linked list.";
		DNode* user = NULL;	
		bool check = true;
		DLLloop(user, check);
		break;
	}
	case 5: //Stack (Array) DONE!
	{
		ztack user;
		bool lol = true;
		stackArrayLoop(user, true);
		break;
	}
	case 6: //Stack (LL)
	{
		Node* stackLL = NULL;
		bool x = true;
		StackLLloop(stackLL, x);
		break;
	}
	case 7: //Using The STL Stack to Reverse a String
	{
		char user[51];
		InitializeString(user);
		int size = sizeof(user) / sizeof(user[0]);
		PrintString(user, size);
		Reverse(user, size);
		cout << endl;
		PrintString(user, size);
	}
	case 8: //Queue (Array) DONE!
	{
		bool x = false;
		int user[50];
		int topIndex = -1;
		QueueLoop(user, &topIndex, x);
		break;
	}
	case 9: //Queue (LL) (PLEASE FINISH THIS)
	{
		/*QueueLLInitiate();
		Node* head = new Node();
		bool loop = true;
		QueueLLoop(true, head);*/
		break;
	}
	case 10: //BST (NEEDS TO BE CHECKED)
	{
		BST* zoheb = NULL;
		bool check = true;
		BSTLoop(zoheb, check);
		break;
	}
	case 11: //Priority Queue/Heap Tree (Not the C++ container!)
	{
		priority_queue<int> user; //NOT THIS!
		break;
	}
	case 12: //AVL Tree
	{
		break;
	}
	case 13: //Graph (Adj. Matrix)
	{
		int weightedAndDirected;
		cout << "Would you like the graph to be unweighted and undirected or weighted and directed?\n1. Unweighted + Undirected\n2. Weigthed + Directed\nPlease select an option: ";
		cin >> weightedAndDirected;
		switch (weightedAndDirected)
		{
		case 1: //unweighted and undirected
		{
			bool x = true; //this is so straight forward... why have i made it so weird in other loops?
			GraphMatrixLoop(x);
			break;
		}
		case 2: //weighted and directed
		{
			bool x = true;
			GraphMatrixWeightedLoop(x);
			break;
		}
		default:
		{
			cout << "Invalid option selected. Exiting program.";
			break;
		}
		}
		break;
	}
	case 14: //Graph (Adj. List)
	{
		bool x = true;
		GraphListLoop(x);
		break;
	}
	case 15: //Graph (Edge List)
	{
		break;
	}
	case 16: //Hash Table
	{
		//MyHashLoop(false);
		break;
	}
	case 17: //Unordered Map (STL)
	{
		break;
	}
	default:
		cout << "Invalid option selected. Exiting program.";
		break;
	}
}