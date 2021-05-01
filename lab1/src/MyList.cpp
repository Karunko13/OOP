#include "MyList.h"

Element::Element(int val)
{
	data=val;
	next=nullptr;
}
MyList::MyList()
{
	head=nullptr;
	tail=nullptr;
	_size=0;
}

int MyList::empty()
{
	if(_size==0)
	{
		return 1;

	}
	else
	{
		return 0;
	}
}

void MyList::print()
{
	if(empty())
	{
		cout<<"["<<" "<<" ]";
		return;
	}
	cout<<"[";
	MyList *temp=head;
	if(head!=nullptr)
	{
		while(temp!=nullptr)
		{
			cout<<temp->data;
			temp=temp->next;
		}
	}
	cout<<"]";

}
void MyList::clear()
{
	if(head==tail)
	{
		delete head;
	}
	Element *temp=head;
	
	while(temp!=tail)
	{
		delete temp;
		temp=temp->next;
	}
	delete tail;
	delete head;
	delete temp;
	tail->next=nullptr;
}