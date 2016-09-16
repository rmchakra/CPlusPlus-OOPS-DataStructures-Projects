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

	void helper (Node*& in, Node*& odds, Node*& evens);
	void append(Node*& list, Node*& value);

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
		helper(next, odds, evens);
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