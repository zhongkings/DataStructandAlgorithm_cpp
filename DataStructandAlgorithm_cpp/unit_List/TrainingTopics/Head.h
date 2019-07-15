#pragma once
#include <iostream>
#include <list>
typedef void(ttFun)(std::string msg);

ttFun MergeList;
ttFun TheSameList;
ttFun ReverseList;
ttFun LinkList;
ttFun SortList_FindIntermediateValue;

template<class T>
static std::ostream& operator << (std::ostream& os, std::list<T> ls)
{
	auto it = ls.begin();
	for (it; it != ls.end(); it++)
		os << *it << " ";
	return os;
}