#pragma once
template<class T>
class SkipList 
{
//Node
private:
	class SkipNode
	{
	public:
		SkipNode() {};
		T key;
		SkipNode** next;
	};

private:
	const static int maxLevel = 4;
	SkipNode* root[maxLevel];
	int powers[maxLevel];

public:
	typedef SkipNode* Iterator;
	SkipList();
	bool isEmpty() const;
	void choosePowers();
	int chooseLevel();
	T* search(const T&);
	void insert(const T&);

};
