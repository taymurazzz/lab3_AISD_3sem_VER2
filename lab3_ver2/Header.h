#include <iostream>
#include "iteratorShirina.h"
#include "iteratorGlubina.h"
using namespace std;

class node {
public:
	int key;
	node* p;
	node* l;
	node* r;
	node() {
		p = NULL;
		l = NULL;
		r = NULL;
	}
};

class tree {
public:
	int size;
	node* head;
	tree() {
		head = new node;
	}

	node* ptrAt(int i) {					// поступают индексы не с нуля а с единицы, единица указывает на голову;
		int arr[64];
		int j = 0;
		while (i > 0) {
			arr[j] = i % 2;
			i = i / 2;
			j++;
		}
		j = j - 2;
		node* cur = head;
		while (j >= 0) {
			if (arr[j] == 0) {
				cur = cur->l;
			}
			if (arr[j] == 1) {
				cur = cur->r;
			}
			j = j - 1;
		}
		return cur;
	}

	void swap(int i, int j) {
		int temp = ptrAt(i)->key;
		ptrAt(i)->key = ptrAt(j)->key;
		ptrAt(j)->key = temp;
	}

	void siftUp(int index) {
		while (ptrAt(index)->key < ptrAt(index / 2)->key) {
			swap(index, index / 2);
			index = index / 2;
		}
	}

	void siftDown(int index) {
		int left, right, j = 0;
		while ((2 * index) < size) {
			left = 2 * index;
			right = 2 * index + 1;
			j = left;
			if (right < size && ptrAt(right)->key < ptrAt(left)->key) {
				j = right;
			}
			if (ptrAt(index)->key < ptrAt(j)->key) {
				break;
			}
			swap(index, j);
			index = j;
		}
	}

	bool contains(int newKey) {
		node* cur = head;
		int ans = 0;
		for (int i = 1; i <= size; i++) {
			if (ptrAt(i)->key == newKey) {
				ans = 1;
			}
		}
		return ans;
	}

	void insert(int data) {
		node* cur = ptrAt(size + 1);
		cur->l = new node;
		cur->r = new node;
		if (size == 0) {
			cur->p = NULL;
		}
		else {
			cur->p = ptrAt((size + 1) / 2);
		}
		cur->key = data;
		size++;
		siftUp(size);
		siftDown(size);
	}

	void remove(int newKey) {
		node* cur = head;
		if (contains(newKey) == 1) {
			int keyindex = 0;
			int i = 1;
			while (1) {
				if (ptrAt(i)->key == newKey) {
					keyindex = i;
					break;
				}
				i++;
			}
			swap(keyindex, size);
			size = size - 1;
			siftUp(keyindex);
			siftDown(keyindex);
		}
	}

	// итератор в ширину 
	iteratorS* create_iteratorS() {
		return new Shirina(head, size);
	}
	class Shirina : public iteratorS
	{
	public:
		node* head;
		int size;
		int ii;

		Shirina(node* start, int sz) {
			head = start;
			size = sz;
			ii = 1;
		}
		node* ptrAt(int i) {					// поступают индексы не с нуля а с единицы, единица указывает на голову;
			int arr[64];
			int j = 0;
			while (i > 0) {
				arr[j] = i % 2;
				i = i / 2;
				j++;
			}
			j = j - 2;
			node* cur = head;
			while (j >= 0) {
				if (arr[j] == 0) {
					cur = cur->l;
				}
				if (arr[j] == 1) {
					cur = cur->r;
				}
				j = j - 1;
			}
			return cur;
		}
		bool has_next() {
			return ii <= size;
		}
		int next() {
			if (!has_next()) {
				throw out_of_range("No more elements");
			}
			int toret = ptrAt(ii)->key;
			ii++;
			return toret;
		}
	};

	// итератор в глубину 
	iteratorG* create_iteratorG() {
		return new Glubina(head, size);
	}

	class Glubina : public iteratorG
	{
	public:
		int size;
		node* head;
		node* cur;
		node* arr[1000];
		int i = 1;
		int jj = 0;
		int z = 1;
		int tmp;
		Glubina(node* h, int s) {
			head = h;
			cur = h;
			size = s;
		}
		node* ptrAt(int ii) {					// поступают индексы не с нуля а с единицы, единица указывает на голову;
			int arr[64];
			int j = 0;
			while (ii > 0) {
				arr[j] = ii % 2;
				ii = ii / 2;
				j++;
			}
			j = j - 2;
			node* curr = head;
			while (j >= 0) {
				if (arr[j] == 0) {
					curr = curr->l;
				}
				if (arr[j] == 1) {
					curr = curr->r;
				}
				j = j - 1;
			}
			return curr;
		}
		bool has_Left() {
			if (ptrAt(i)->l->l != NULL) {
				return 1;
			}
			else {
				return 0;
			}
		}
		bool has_Right() {
			if (ptrAt(i)->r->r != NULL) {
				return 1;
			}
			else {
				return 0;
			}
		}

		int Next() {
			tmp = ptrAt(i)->key;
			if (has_Right()) {
				arr[jj] = ptrAt(i)->r;
				jj++;
			}
			if (has_Left()) {
				cur = ptrAt(i)->l;
				i = 2 * i;
			}
			else {
				cur = arr[jj - 1];
				jj = jj - 1;
				for (z = 1; z <= size; z++) {
					if (ptrAt(z) == cur) {
						i = z;
					}
				}
			}
			return tmp;
		}

	};

	void print() {
		node* cur = head;
		for (int i = 1; i <= size; i++) {
			cout << ptrAt(i)->key;
		}
	}


};
