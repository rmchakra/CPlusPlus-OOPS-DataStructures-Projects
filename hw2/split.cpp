#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;

    Node(int v, Node *n)
    {
    	value = v;
    	next = n;
    }
    Node()
    {
    	value = 0;
    	next = NULL;
    }
};

//helper to solve everyhting and then just set in = NULL
/*
if(in->next == NULL)
	{
		in = NULL;
		return;
   //base case is the end of the list
	}
*/
	void helper (Node*& in, Node*& odds, Node*& evens);
	void append(Node*& list, Node*& value);
	void print(Node*& list);

void split (Node*& in, Node*& odds, Node*& evens)
{
	helper (in, odds, evens);
	in = NULL;
}

void helper (Node*& in, Node*& odds, Node*& evens)
{
	if(in == NULL)
	{
		return;
	}

	Node* next = in->next;

		if(in->value % 2 ==0)
		{//if even
			append(evens, in);
		}

		else
		{//if odd
			append(odds, in);
		}	
		//if(in->next->next == NULL)
		//{
		//	in->next = NULL;
		//}
		//return;
	//if(next != NULL)
	//{//recurse through to the end of the list 
		helper(next, odds, evens);

	//}

}


//*& is a pointer to the reference from &
void append(Node*& list, Node*& value)
{
	if (list == NULL)
	{//adding to first of 
		list = value;
		value->next = NULL;
		return;
	} 
	if(list->next == NULL)
	{//adding further elements
		list->next = value;
		value->next = NULL;
		return;
	}
	append(list->next, value);
}

void print(Node*& list)
{
	if(list==NULL)
	{
		cout << "List is NULL"<< endl;
		return;
	}
	//if(list->next == NULL)
	//{
		//cout << list->value <<endl;
	//	return;
	//}
	cout << list->value<<endl;
	print(list->next);
}

int main()
{
	Node n1, n2, n3;
	n1.value = 1;
	n2.value = 2;
	n3.value = 3;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;
	Node* list_head = &n1;
	Node* odds_head = NULL;
	Node* evens_head = NULL;

	//to check append
	Node n4;
	n4.value = 56;
	Node* n4_ptr = &n4;

	append(list_head,n4_ptr);
	print(list_head);

	split (list_head, odds_head, evens_head);
	//cout << "print n1" << endl;
	//print(list_head);
	cout << "print odds" << endl;
	print(odds_head);
	cout << "print evens" << endl;
	print(evens_head);
	
	return 0;
}