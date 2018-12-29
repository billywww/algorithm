#include<iostream>
using namespace std;
const int defaultSize = 100;

template<class T>
class MinHeap {
public:
	MinHeap(int sz = defaultSize);
	MinHeap(T arr[], int sz);
	~MinHeap();
	bool insert(const T& x);
	bool removeMin(T& x);
	bool isEmpty();
	bool isFull();
	void makeEmpty();
	void display();
private:
	T* _heap;
	int _currentSize;
	int _maxHeapSize;
	void shifDown(int start, int end);
	void shifUp(int start);
};



template<class T>
MinHeap<T>::MinHeap(int sz /*= defaultSize*/) {
	_maxHeapSize = (sz > defaultSize) ? sz : defaultSize;
	_heap = new T[_maxHeapSize];
	if (_heap == nullptr) {
		cerr << "内存分配错误！" << endl;
		exit(0);
	}
	_currentSize = 0;
}


template<class T>
MinHeap<T>::MinHeap(T arr[], int sz) {
	_maxHeapSize = (sz > defaultSize) ? sz : defaultSize;
	_heap = new T[_maxHeapSize];
	if (_heap == nullptr) {
		cerr << "内存分配错误！" << endl;
		exit(0);
	}

	for (int i = 0; i < sz; i++)
		_heap[i] = arr[i];
	_currentSize = sz;

	int currentPos = (_currentSize - 2) / 2;
	while (currentPos >= 0) {
		shifDown(currentPos, _currentSize - 1);
		currentPos--;
	}
}



template<class T>
void MinHeap<T>::shifDown(int start, int end) {

	int i = start;
	int j = 2 * i + 1;
	T tempValue = _heap[i];
	while (j <= end) {
		if (j < end && _heap[j]> _heap[j + 1])
			j++;
		if (tempValue <= _heap[j])
			break;
		else {
			_heap[i] = _heap[j];
			i = j;
			j = 2 * i + 1;
		}
	}
	_heap[i] = tempValue;
}


template<class T>
MinHeap<T>::~MinHeap() {
	if (_heap != nullptr)
		delete _heap;
}


template<class T>
bool MinHeap<T>::removeMin(T& x) {
	if (isEmpty())
		return false;
	 x = _heap[0];
	 _heap[0] = _heap[_currentSize - 1];
	 _currentSize--;
	shifDown(0, _currentSize - 1);
	return true;
}


template<class T>
bool  MinHeap<T>::isEmpty() {
	return _currentSize == 0;
}


template<class T>
bool MinHeap<T>::insert(const T& a){
  // if(isFull()) return false;
  _heap[_currentSize] = a;
  shifUp(_currentSize);
  _currentSize++;
  return true;
}

template <class T>
void MinHeap<T>::shifUp(int start){
  int temp = (start-1)/2;
  while(temp>=0 && start > 0){
    if(_heap[start]>_heap[temp])
     break;
    else{
      T t = _heap[start];
      _heap[start] = _heap[temp];
      _heap[temp] = t;
      start = temp;
      temp = (start-1)/2;
    }
  }
}
