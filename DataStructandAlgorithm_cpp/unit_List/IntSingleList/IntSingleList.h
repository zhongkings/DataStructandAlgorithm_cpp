#pragma once
#include <stdio.h>

class IntSingleList
{
	// node
private:
	class Node
	{
	public:
		Node(int info = 0, Node * next = NULL);
		~Node();
		void setInfo(int info);
		void setNext(Node* next);
		int getInfo() const;
		Node* getNext() const;
	private:
		int info;
		Node* next;
	};

private:
	Node* head, * tail;
	int size;

public:
	typedef Node* Iterator;
	IntSingleList();
	~IntSingleList();

	//��� ɾ��
	void addtoHead(int info);
	void addtoTail(int info);
	void insert(int info, int index);
	void deltoHead();
	void deltoTail();
	void remove(int index);
	void removeOfValue(int info);

	//�Ƿ�� ��� ��ȡ ��ȡ �Ƿ����
	bool isEmpty();
	void clear();
	int howsize();
	bool isContain(int info);

	//������begin end
	Node* Begin();
	Node* End();
	Node* Find(int index);
};
