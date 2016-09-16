#include <iostream>

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
    	value = NULL;
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

	/*

	void split (Node*& in, Node*& odds, Node*& evens)
	{
		helper (in, odds, evens);
		in = NULL;
	}

void helper (Node*& in, Node*& odds, Node*& evens)
{
	if(in->next != NULL)
	{//recurse through to the end of the list first
		helper(in->next, odds, evens);
	}
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
}

void append(Node*& list, Node*& value)
{
	if (list->value == NULL) return;

	if(list->next == NULL)
	{
		list->next = &value;
		value->next = NULL;
		return;
	}
	append(list->next, value);
}

*/

void print(Node*& list)
{
	if(list->next == NULL)
	{
		cout << list->value <<endl;
		return;
	}
	cout << list->value<<endl;
	print(list->next);
}

void main()
{
	Node n1, n2, n3, odds, evens;
	n1.value = 0;
	n2.value = 1;
	n3.value = 2;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;

	print(n1);
/*
	split (n1, Node*& odds, Node*& evens);
	cout << "print n1" << endl;
	print(n1);
	cout << "print odds" << endl;
	print(odds);
	cout << "print evens" << endl;
	print(evens);
	*/
}