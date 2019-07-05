#include "IntSingleList.h"
#include "dsError.h"
#include <iostream>

//IntSingleList->Node
IntSingleList::Node::Node(int info, Node * next) 
{
	this->info = info;
	this->next = next;
}

IntSingleList::Node::~Node()
{
	info = 0;
	next = NULL;
}

void IntSingleList::Node::setInfo(int info) 
{
	this->info = info;
}

void IntSingleList::Node::setNext(Node* next) 
{
	this->next = next;
}

int IntSingleList::Node::Node::getInfo() const {
	return info;
}

IntSingleList::Node* IntSingleList::Node::getNext() const {
	return next;
}

//IntSingleList Operation

IntSingleList::IntSingleList() 
{
	size = 0;
	head = tail = NULL;
}

IntSingleList::~IntSingleList() 
{
	if (size != 0) {
		clear();
	}
}

//��� ɾ��
void IntSingleList::addtoHead(int info) 
{
	Node* newNode = new Node(info, NULL);
	if (!head) {
		head = newNode;
		tail = head;
	}
	else {
		newNode->setNext(head);
		head = newNode;
	}

	size++;
}

void IntSingleList::addtoTail(int info)
{
	Node* newNode = new Node(info, NULL);
	if (!tail) {
		tail = newNode;
		head = tail;
	}
	else {
		tail->setNext(newNode);
		tail = newNode;
	}

	size++;
}

void IntSingleList::insert(int info, int index)
{
	if (index < 0)
		throw (dsERROR_UNINDEX);

	if (index == 0) {
		addtoHead(info);
		return;
	}
	else if (index >= size) {
		addtoTail(info);
		return;
	}

	Node* newNode = new Node(info, NULL);
	Node* iterator = head;
	for (int i = 1; i < index; i++) { //����Ϊһ���ǿ���������������ͬλ��
		iterator = iterator->getNext();
	}

	newNode->setNext(iterator->getNext());
	iterator->setNext(newNode);
	size++;
}

void IntSingleList::deltoHead() 
{
	if (isEmpty())
		throw(dsERROR_EMPTYEM);

	Node* askDelNode = head;
	head = head->getNext();

	delete askDelNode;
	size--;
}

void IntSingleList::deltoTail()
{
	if (isEmpty())
		throw(dsERROR_EMPTYEM);

	if (head == tail) {
		delete head;
		head = tail = NULL;
		size--;
		return;
	}

	Node* i = head;
	while (i != tail)
		i = i->getNext();

	delete i->getNext();
	i->setNext(NULL);
	size--;
}

void IntSingleList::remove(int index) {
	if (isEmpty())
		throw(dsERROR_EMPTYEM);

	if (index == 0) {
		deltoHead();
		return;
	}
	else if (index >= size) {
		deltoTail();
		return;
	}

	//�Ȳ�ʵ��
	Node* iterator = head;
	for (int i = 1; i < index; i++) { //����Ϊһ���ǿ���������������ͬλ��
		iterator = iterator->getNext();
	}

	Node* askDelNode = iterator->getNext();
	iterator->setNext(askDelNode->getNext());

	delete askDelNode;
	size--;
}

void IntSingleList::removeOfValue(int info) {
	if (isEmpty())
		throw(dsERROR_EMPTYEM);
	
	if (head == tail) {
		deltoHead();
		return;
	}

	Node* priexIt = NULL; //��¼ǰ���Node
	Node* iterator = head;
	while (iterator)
	{
		if (iterator->getInfo() == info)
			break;

		priexIt = iterator;
		iterator = iterator->getNext();
	}

	if (iterator == NULL) //������ֵ��ֱ���˳�
		return;
	Node* askDelNode = priexIt->getNext();
	priexIt->setNext(askDelNode->getNext());

	delete askDelNode;
	size--;
}

//�Ƿ�� ��� ��ȡ ��ȡ �Ƿ����

bool IntSingleList::isEmpty()
{
	return size == 0;
}

void IntSingleList::clear() 
{
	if (isEmpty())
		throw(dsERROR_EMPTYEM);

	Node* delIter = head;
	while (delIter->getNext()) {
		Node* askDelNode = delIter->getNext();
		delIter->setNext(askDelNode->getNext());

		delete askDelNode;
		size--;
	}

	delete delIter;
	head = tail = NULL;
	size = 0;
}

int IntSingleList::howsize()
{
	return this->size;
}

bool IntSingleList::isContain(int info)
{
	if (isEmpty())
		throw(dsERROR_EMPTYEM);

	Node* iterator = head;
	while (head) 
	{
		if (head->getInfo() == info)
			return true;

		head = head->getNext();
	}

	return false;
}

//������begin end
IntSingleList::Node* IntSingleList::Begin()
{
	if (isEmpty())
		throw(dsERROR_EMPTYEM);

	return head;
}

IntSingleList::Node* IntSingleList::End()
{
	if (isEmpty())
		throw(dsERROR_EMPTYEM);

	return tail;
}

IntSingleList::Node* IntSingleList::Find(int index)
{
	if (isEmpty())
		throw(dsERROR_EMPTYEM);

	return NULL;
}
