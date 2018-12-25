#include<iostream>
#include<string.h>
#include"uf.h"
using namespace std;
#define defaultSize 100
//

template <class Type>
class eagle{
public:
  eagle(int a,int b,int c){
    weight =a;
    u=b;
    v=c;
  }
  eagle(){};
  Type weight;
  int u,v;
};



//
template<class T>
class MinHeap {
public:
	MinHeap(int sz = defaultSize);         //最小堆的默认构造函数
	MinHeap(T arr[], int sz);             //通过一个数组创建构造函数
	~MinHeap();                            //析构函数
	bool insert(const T& x);              //将x插入到最小堆中
	bool removeMin(T& x);                //删除最小堆中最小的元素，保存至x中
	bool isEmpty();                       //判断最小堆是否为空
	bool isFull();                       //判断最小堆是否满
	void makeEmpty();                     //将最小堆置空
	void display();                      //输出最小堆
private:
	T* _heap;                              //存放堆中元素的数组
	int _currentSize;                       //最小堆中当前元素的个数
	int _maxHeapSize;                       //最小堆中最多允许的个数
	void shifDown(int start, int end);      //从start 到end下滑调整为最小堆
	void shifUp(int start);                //从start 到0上滑调整为最小堆
};


//最小堆的默认构造函数
template<class T>
MinHeap<T>::MinHeap(int sz /*= defaultSize*/) {
	_maxHeapSize = (sz > defaultSize) ? sz : defaultSize;          //_maxHeapSize为参数sz与defaultSize中的较大者
	_heap = new T[_maxHeapSize];                                   //为存放堆元素的数组分配内存
	if (_heap == nullptr) {                                        //内存分配失败
		cerr << "内存分配错误！" << endl;
		exit(-1);
	}
	_currentSize = 0;                                             //当前堆元素数量为0
}

//通过一个数组创建构造函数
template<class T>
MinHeap<T>::MinHeap(T arr[], int sz) {
	_maxHeapSize = (sz > defaultSize) ? sz : defaultSize;          //_maxHeapSize为参数sz与defaultSize中的较大者
	_heap = new T[_maxHeapSize];                                   //为存放堆元素的数组分配内存
	if (_heap == nullptr) {                                        //内存分配失败
		cerr << "内存分配错误！" << endl;
		exit(-1);
	}

	for (int i = 0; i < sz; i++)                                     //将参数数组中的元素一一赋值给堆元素
		_heap[i] = arr[i];
	_currentSize = sz;                                             //为堆元素数量赋值，和参数数组大小相同

	int currentPos = (_currentSize - 2) / 2;                       //临时变量，指向最后一个有叶节点的堆
	while (currentPos >= 0) {
		shifDown(currentPos, _currentSize - 1);                    //自底向上(对于整个堆而言)-自上而下(对于局部堆而言)调整为堆
		currentPos--;
	}
}


//从start 到end下滑调整为最小堆
template<class T>
void MinHeap<T>::shifDown(int start, int end) {
	//私有函数：从结点start开始，到end为止，自上向下比较，如果
	//子女的值小于父节点的值，则关键码小的值上浮，继续向下层比较
	//这样将一个集合局部调整为最小堆
	int i = start;
	int j = 2 * i + 1;                             //指向i的左结点
	T tempValue = _heap[i];                        //临时保存下标为start结点的值
	while (j <= end) {                             //未达到end结束结点，一直循环
		if (j < end && _heap[j].weight > _heap[j + 1].weight)    //如果有右结点，并且右结点小于左结点
			j++;                                    //j就指向右结点
		if (tempValue.weight <= _heap[j].weight)                 //如果父节点小于等于左右结点，就直接进行下一层循环
			break;
		else {
			_heap[i] = _heap[j];                     //否则将子结点的值赋值给父节点
			i = j;                                   //使i指向子节点
			j = 2 * i + 1;                           //j指向i的子结点
		}
	}
	_heap[i] = tempValue;                            //回返
}

//析构函数
template<class T>
MinHeap<T>::~MinHeap() {
	if (_heap != nullptr)
		delete _heap;
}

//删除最小堆中最小的元素，保存至x中
template<class T>
bool MinHeap<T>::removeMin(T& x) {
	if (isEmpty())                                         //如果已空,就不能进行删除
		return false;
	 x = _heap[0];                                         //堆顶元素赋值给返回参数x
	 _heap[0] = _heap[_currentSize - 1];                   //将最后一个元素赋值给堆顶元素
	 _currentSize--;                                     //参数个数自减减一
	shifDown(0, _currentSize - 1);                        //调用shifDown函数进行最小堆调整
	return true;
}

//判断最小堆是否为空
template<class T>
bool  MinHeap<T>::isEmpty() {
	return _currentSize == 0;
}



template <class Type>
int mst(int n,int e,eagle<Type>E[],eagle<Type>t[]){
  MinHeap<eagle<Type>>H(E,n);
  UF U(n+1);
  int k = 0;
  while(k<e-1&&n){
    eagle<int> x;
    H.removeMin(x);
    n--;
    int a=U.find(x.u);
    int b=U.find(x.v);
    if(a!=b){
      t[k++]=x;
      U.union_A(a,b);
    }
  }
  return 0;
}


int main(){
  eagle<int> e[10];
  eagle<int> t[10];
  e[0]=eagle<int>(1,1,3);
  e[1]=eagle<int>(2,4,6);
  e[2]=eagle<int>(3,2,5);
  e[3]=eagle<int>(4,3,6);
  e[4]=eagle<int>(5,2,3);
  e[5]=eagle<int>(5,3,4);
  e[6]=eagle<int>(5,1,4);
  e[7]=eagle<int>(6,1,2);
  e[8]=eagle<int>(6,3,5);
  e[9]=eagle<int>(6,5,6);
  mst<int>(10,6,e,t);
  for(int i = 0;i<5;i++){
    cout<<t[i].u;
    cout<<t[i].v<<endl;
  }


}
