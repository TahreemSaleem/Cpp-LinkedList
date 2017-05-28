#include<iostream>
using namespace std;
/////////// One Element of the list/////////////////
template <typename T>

struct Node
{
	T data;	//data item
	Node* next;	//pointer to next link
};
////////Linked List Class///////////////////////////////
template <typename T>
class linklist //a list of links
{
private:

	Node<T>* head; //pointer to first node
	public:
			linklist(){
				head = NULL;
			} //Constructor: empty linked list
			void insertItem(T d); //insert items in the list
			
			void deleteItem(T d); 
			void displayList();
		
			void Average();
};
//function for inserting items
template <typename T>
void linklist<T>::insertItem(T d) //add data item
{
	Node<T> *newNode = new Node<T>;
	Node<T> *nodePtr, *previousNode = NULL;
	newNode->data = d;
	newNode->next = NULL;

	// If there are no nodes in the list
	// make newNode the first node
	if (!head)
		// head == NULL
		head = newNode;

	else// Otherwise,
	{
		// Initialize nodePtr to head of list
		nodePtr = head;
		// Skip all
		//nodes whose value member is less than num.
		while
			(nodePtr != NULL && nodePtr->data<d)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		// If the new node is to be the 1st in the list,
		// insert it before all other nodes.
		if
			(previousNode == NULL)

		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}
//fuction to delete an item from the list 
template <typename T>
void linklist<T>::deleteItem(T d)
//add data item
{
	Node<T> *nodePtr, *previousNode = NULL;
	// If there are no nodes in the list
	// do nothing
	if (!head)
	return;
	// Determine if the first node is the one
	if (head->data == d){
		nodePtr = head->next;
		head = nodePtr;
		delete head;
	}
	else{
		// Initialize nodePtr to head of list
		nodePtr = head;
		// Skip all nodes whose value member is not equal to num.
		while (nodePtr != NULL && nodePtr->data != d)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// Link the previous node to the node after nodePtr, then delete nodeptr
		previousNode->next = nodePtr->next;
		delete nodePtr;
	}

}
//function to display the list 
template <typename T>
void linklist<T>::displayList(void)
{
	Node<T> *nodePtr;

	nodePtr = head;
	while (nodePtr)
	{
		cout << nodePtr->data << endl;
		nodePtr = nodePtr->next;
	}
}
template <typename T>
void linklist<T>::Average(void)
{
	Node<T> *nodePtr;
	int sum = 0;
	int count = 0;
	nodePtr = head;
	while (nodePtr)
	{
		sum += nodePtr->data;
		nodePtr = nodePtr->next;
		count++;
	}
	int avg = (sum / count);
	
	cout << "Average is =" << avg << endl;
}


int main(int argc, const char * argv[])
{
	linklist<int> myIntList;
	myIntList.insertItem(10);     //inserting items 
	myIntList.insertItem(15);
	myIntList.insertItem(5);
	myIntList.insertItem(20);
	myIntList.displayList();
	cout << "AFTER DELETING 15 " << endl;
	myIntList.deleteItem(15);	//deleting the specific item
	myIntList.displayList();
	return 0;
}
