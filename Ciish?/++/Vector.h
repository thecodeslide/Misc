#ifndef vector_h
#define vector_h

#include <iostream>
#include <string>
#include <vector>
//const int SIZE = 7;

template<class myT>
class Vector
{
	std::vector<myT> m_vec;
//	vector<myT> vec;
//	myT *list;
	int length, SIZE;
public:
	Vector();
	~Vector();
	myT atPos(int i) const { /*return list[i];*/ return m_vec.at(i); };
	void insert(const myT &);
	/*void isFull();
	bool isEmpty();*/
//	void removeEle(const myT &);
	int getLen();
	void removeLastEle();
//	void removePos(int);
	void resetVector();
};

//implementation
template<class myT>
Vector<myT>::Vector()
{
	length = 7;
	SIZE = 0;
//	list = new myT[length];
}

template<class myT>
void Vector<myT>::insert(const myT &ele)
{
	m_vec.push_back(ele);
//	list[SIZE++] = ele;
	++SIZE;
}

//template<class myT>
//void Vector<myT>::isFull()
//{
//	/*if(Obj.getLen() == length-1)
//		return true;
//	return false;*/
//	cout << getLen();
//}
//
//template<class myT>
//bool Vector<myT>::isEmpty()
//{
//	if(list[0] == 0)
//		return true;
//	return false;
//}

//template<class myT>
//void Vector<myT>::removeEle(const myT &ele)
//{
//	int i=0;
//	if(SIZE == 0)
//		cout << "EMPTY LIST" << endl;
//	else
//	{
//		for (i; i < length; ++i) 
//		{
//			if (list[i] == ele)
//			{
//				removePos(i);
//				break;
//			}
//		}
//	}
//}

template<class myT>
void Vector<myT>::removeLastEle()
{
	--SIZE;
}

template<class myT>
int Vector<myT>::getLen()
{
	return SIZE;
}

//template<class myT>
//void Vector<myT>::removePos(int m)
//{
//	if(m < length-1 || m>=0)
//	{
//		for(int i = m;i < length-1; i++)
//		{
//			 list[i] = list[i+1];
//		}
//		--SIZE;
//	}
//	else
//		cerr << "\nError. Length is out of range or use remove last ele." << endl;
//}

template<class myT>
void Vector<myT>::resetVector()
{
	//delete [] list;
	//list = NULL;
	SIZE = 0;
	length =0;
}

template<class myT>
Vector<myT>::~Vector()
{
	//delete [] list;
	//list = NULL;
	/*SIZE = 0;
	length =0;*/
}

#endif
