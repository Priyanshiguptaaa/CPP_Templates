#include <bits/stdc++.h>

using namespace std;


class node
{
public:
    int data;
    node* next;
    node* prev;

    //constructor for Node class
    node(int d)
    {
        data=d;
        next=NULL;
        prev=NULL;
    }

};

class LinkedList
{
public:
    node*head;
    node*tail;
    int size;

    //constructor for Linked List
    LinkedList()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }

    //function to push element at the front of list
    void push_front(int d)
    {
        node* new_head= new node(d);

        //
        if(head == NULL)
            tail=new_head, head=new_head;
        else
        {
            new_head->next=head;
            head->prev=new_head;
            head=new_head;

        }

        size++;

    }
    void push_back(int d)
	{
		node *new_tail = new node(d);

		if (tail == NULL)
			head = new_tail, tail = new_tail;

		else
		{
			tail->next = new_tail;
			new_tail->prev = tail;
			tail = new_tail;
		}

		size++;
	}

	node* insert(node *cur, int d) //insert just after the cur node
	{
		node *new_node = new node(d);

		new_node->next = cur->next;
		cur->next = new_node;

		new_node -> prev = cur;

		if (new_node->next)
			new_node->next->prev = new_node;

		else
			tail = new_node;

		size++;

		return new_node;
	}

	void pop_back()
	{
		if (!tail)
			return;

		if (!(tail->prev))
		{
			delete tail;
			head = tail = NULL;
		}

		else
		{
			node *new_tail = tail->prev;

			new_tail->next = NULL;
			delete tail;

			tail = new_tail;
		}

		size--;
	}

	void pop_front()
	{
		if (!head)
			return;

		if (!(head->next))
		{
			delete head;
			head = tail = NULL;
		}

		else
		{
			node *new_head = head->next;

			delete head;
			new_head->prev = NULL;

			head = new_head;
		}
		size--;
	}

	void pop(node* cur) //Delete this node
	{
		if (size == 1)
		{
			delete cur;
			head = tail = NULL;
		}

		//prev->next = next, next->prev = cprev

		if (cur->prev)
			cur->prev->next = cur->next;

		if (cur->next)
			cur->next->prev = cur->prev;

		if (cur == head)
			head = cur->next;

		if (cur == tail)
			tail = cur->prev;

		delete cur;
		size--;
	}

	void print_iter()
	{
		node *cur = head;

		while (cur)
		{
			cout << cur->data << ' ';
			cur = cur->next;
		}

		cout << '\n';
	}

	void print_rec_aux(node *cur)
	{
		if (!cur)
			return;

		cout << cur->data << ' ';
		print_rec_aux(cur->next);
	}

	void print_rec()
	{
		print_rec_aux(head);
		cout << '\n';
	}

	void reverse()
	{
		node *cur = head;

		while (cur)
		{
			//node *old_next = cur->next;
			swap(cur->next, cur->prev);
			//cur = old_next;
			cur = cur->prev;
		}

		swap(head, tail);
	}

	void reverse_singly()
	{
		node *cur = head, *prev = NULL;

		while (cur)
		{
			node *next_node = cur->next;

			cur->next = prev;

			prev = cur;
			cur = next_node;
		}

		swap(head, tail);
	}

};

int main()
{
	LinkedList l;

	for (int i = 1; i <= 10; ++i)
		l.push_back(i);

	l.print_iter();

	l.pop_back();
	l.print_iter();

	l.pop_front();
	l.print_iter();

	node *eleven = l.insert(l.head, 11);
	l.print_iter();

	cout << l.size << '\n';

	l.pop(eleven);
	l.print_iter();

	l.pop(l.head);
	l.print_iter();

	l.pop(l.tail);
	l.print_iter();

	l.reverse();
	l.print_iter();

	l.reverse_singly();
	l.print_iter();

	return 0;
}
