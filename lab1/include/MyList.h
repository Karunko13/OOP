#pragma once

using namespace std;

class Element{
	private:
	int data;
	int head;
	int tail;
	public:
	Element(int val);
	Element *next;

};

class MyList{

private:
Element *head;
Element *tail;
int _size;


public:
	//konstruktor domyślny
	MyList();
	//konstruktor jednoargumentowy
	MyList(int x);
  //konstrukotr kopiujacy
	MyList(MyList &src);

	int empty();
	void print();
	int size();
	void clear();
};
