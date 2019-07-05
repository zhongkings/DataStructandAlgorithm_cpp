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

//添加 删除
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
	for (int i = 1; i < index; i++) { //这里为一，是可以让它迭代到相同位置
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

	//先不实现
	Node* iterator = head;
	for (int i = 1; i < index; i++) { //这里为一，是可以让它迭代到相同位置
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

	Node* priexIt = NULL; //记录前面的Node
	Node* iterator = head;
	while (iterator)
	{
		if (iterator->getInfo() == info)
			break;

		priexIt = iterator;
		iterator = iterator->getNext();
	}

	if (iterator == NULL) //不存在值，直接退出
		return;
	Node* askDelNode = priexIt->getNext();
	priexIt->setNext(askDelNode->getNext());

	delete askDelNode;
	size--;
}

//是否空 清空 获取 读取 是否包含

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

//迭代器begin end
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
