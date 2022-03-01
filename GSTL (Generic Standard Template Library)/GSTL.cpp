#include<iostream>
using namespace std;

template <class T>
struct node1
{
	T data1;
	struct node1 *next;
};

template <class T>
struct node2
{
	T data2;
	struct node2 *next;
	struct node2 *previous;
};

template <class T>
struct node3
{
	T data3;
	struct node3 *lchild;
	struct node3 *rchild;
};

template <class T>
class SinglyLL
{
	private:
		struct node1 <T>*first;
		int size;
	public:
		SinglyLL();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T, int);
		void Display();
		int Count();
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
};

template <class T>
class DoublyLL
{
	private:
		struct node2 <T>*first;
		int size;
	public:
		DoublyLL();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T, int);
		void Display();
		int Count();
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
};

template <class T>
class SinglyCL
{
	private:
		struct node1 <T>*first;
		struct node1 <T>*last;
		int size;
	public:
		SinglyCL();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T, int);
		void Display();
		int Count();
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
};

template <class T>
class DoublyCL
{
	private:
		struct node2 <T>*first;
		struct node2 <T>*last;
		int size;
	public:
		DoublyCL();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T, int);
		void Display();
		int Count();
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
};

template <class T>
class Queue
{
	private:
		struct node1 <T>*first;
		int size;
	public:
		Queue();
		void Enqueue(T);
		T Dequeue();
		void Display();
		int Count();
};

template <class T>
class Stack
{
	private:
		struct node1 <T>*first;
		int size;
	public:
		Stack();
		void push(T);
		T pop();
		void Display();
		int Count();
};

template <class T>
class Tree
{
	public:
		int size;
		struct node3 <T>*first;
	public:
		Tree();
		void Insert(T);
		bool Search(T);
		int Count(struct node3 <T>*);
		int CountLeafNode(struct node3 <T>*);
		int CountParentNode(struct node3 <T>*);
		void Inorder(struct node3 <T>*);
		void Preorder(struct node3 <T>*);
		void Postorder(struct node3 <T>*);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
	first = NULL;
	size = 0;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
	struct node1 <T>*newn = new struct node1<T>;
	newn->data1 = no;
	newn->next = NULL;
	
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		newn->next = first;
		first = newn;
	}
	size++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
	struct node1 <T>*newn = new struct node1<T>;
	newn->data1 = no;
	newn->next = NULL;
	
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		struct node1 <T>*temp = first;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
	size++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
{
	int i = 0;
	if((iPos < 0) || (iPos > size+1))
	{
		return;
	}
	if(iPos == 1)
	{
		InsertFirst(no);
	}
	else if(iPos == size+1)
	{
		InsertLast(no);
	}
	else
	{
		struct node1 <T>*temp = first;
		struct node1 <T>*newn = new struct node1<T>; 
		newn->data1 = no;
		newn->next = NULL;
		
		for(i = 1;i<iPos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
		size++;
	}
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
	if(first == NULL)
	{
		return;
	}
	else if(first->next == NULL)
	{
		delete first;
		first = NULL;
	}
	else
	{
		struct node1 <T>*temp = first;
		first = first->next;
		delete temp;
	}
	size--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
	if(first == NULL)
	{
		return;
	}
	else if(first->next == NULL)
	{
		delete first;
		first = NULL;
	}
	else
	{
		struct node1 <T>*temp = first;
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		delete temp->next;
		temp->next = NULL;
	}
	size--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
	if((iPos < 1) || (iPos > size))
	{
		return;
	}
	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == size)
	{
		DeleteLast();
	}
	else
	{
		struct node1 <T>*temp = first;
		for(int i = 1;i < iPos-1;i++)
		{
			temp = temp->next;
		}
		struct node1 <T>*targeted = temp->next;
		temp->next = temp->next->next;
		delete targeted;
		size--;
	}
		
}

template <class T>
void SinglyLL<T>::Display()
{
	struct node1 <T>*temp = first;
	while(temp != NULL)
	{
		cout<<"|"<<temp->data1<<"|  ";
		temp = temp->next;
	}
	cout<<"\n";
}

template <class T>
int SinglyLL<T>::Count()
{
	return size;
}

template <class T>
DoublyLL<T>::DoublyLL()
{
	first = NULL;
	size = 0;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
	struct node2 <T>*newn = new struct node2<T>;
	newn->data2 = no;
	newn->next = NULL;
	newn->previous = NULL;
	
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		newn->next = first;
		first->previous = newn;
		first = newn;
	}
	size++;
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
	struct node2 <T>*newn = new struct node2<T>;
	newn->data2 = no;
	newn->next = NULL;
	newn->previous = NULL;
	
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		struct node2 <T>*temp = first;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
		newn->previous = temp;
	}
	size++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no, int iPos)
{
	int i = 0;
	if((iPos < 0) || (iPos > size+1))
	{
		return;
	}
	if(iPos == 1)
	{
		InsertFirst(no);
	}
	else if(iPos == size+1)
	{
		InsertLast(no);
	}
	else
	{
		struct node2 <T>*temp = first;
		struct node2 <T>*newn = new struct node2<T>; 
		newn->data2 = no;
		newn->next = NULL;
		newn->previous = NULL;
		
		for(i = 1;i<iPos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next->previous = newn;
		temp->next = newn;
		newn->previous = temp;
		size++;
	}
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
	if(first == NULL)
	{
		return;
	}
	else if(first->next == NULL)
	{
		delete first;
		first = NULL;
	}
	else
	{
		first = first->next;
		delete first->previous;
		first->previous = NULL;
	}
	size--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
	if(first == NULL)
	{
		return;
	}
	else if(first->next == NULL)
	{
		delete first;
		first = NULL;
	}
	else
	{
		struct node2 <T>*temp = first;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->previous->next = NULL;
		delete temp;
	}
	size--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
	if((iPos < 1) || (iPos > size))
	{
		return;
	}
	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == size)
	{
		DeleteLast();
	}
	else
	{
		struct node2 <T>*temp = first;
		for(int i = 1;i < iPos-1;i++)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		delete (temp->next->previous);
		temp->next->previous = temp;
		
		size--;
	}
		
}

template <class T>
void DoublyLL<T>::Display()
{
	struct node2 <T>*temp = first;
	while(temp != NULL)
	{
		cout<<"|"<<temp->data2<<"|  ";
		temp = temp->next;
	}
	cout<<"\n";
}

template <class T>
int DoublyLL<T>::Count()
{
	return size;
}

template <class T>
SinglyCL<T>::SinglyCL()
{
	first = NULL;
	last = NULL;
	size = 0;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
	struct node1 <T>*newn = new struct node1<T>;
	newn->data1 = no;
	newn->next = NULL;
	
	if((first == NULL) && (last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		newn->next = first;
		first = newn;
	}
	last->next = first;
	size++;
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{

	struct node1 <T>*newn = new struct node1<T>;
	newn->data1 = no;
	newn->next = NULL;
	
	if(first == NULL)
	{
		first = newn;
		last = newn;
	}
	else
	{	
		last->next = newn;
		last = newn;
	}
	last->next = first;
	size++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int iPos)
{
	int i = 0;
	if((iPos < 0) || (iPos > size+1))
	{
		return;
	}
	if(iPos == 1)
	{
		InsertFirst(no);
	}
	else if(iPos == size+1)
	{
		InsertLast(no);
	}
	else
	{
		struct node1 <T>*temp = first;
		struct node1 <T>*newn = new struct node1<T>;
		newn->data1 = no;
		newn->next = NULL;
		
		for(i = 1;i<iPos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
		size++;
	}
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
	if((first == NULL)&&(last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{
		first = first->next;
		delete last->next;
		last->next = first;
	}
	size--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
	if((first == NULL) && (last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{
		struct node1 <T>*temp = first;
		while(temp->next != last)
		{
			temp = temp->next;
		}
		delete last;
		last = temp;
		last->next = first;
	}
	size--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
	if((iPos < 1) || (iPos > size))
	{
		return;
	}
	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == size)
	{
		DeleteLast();
	}
	else
	{
		struct node1 <T>*temp = first;
		for(int i = 1;i < iPos-1;i++)
		{
			temp = temp->next;
		}
		struct node1 <T>*targeted = temp->next;
		temp->next = temp->next->next;
		delete targeted;
		size--;
	}	
}

template <class T>
void SinglyCL<T>::Display()
{
	struct node1 <T>*temp = first;
	if((first == NULL)&&(last == NULL))
	{
		return;
	}
	do
	{
		cout<<"|"<<temp->data1<<"|  ";
		temp = temp->next;
	}while(temp != last->next);
	cout<<"\n";
}

template <class T>
int SinglyCL<T>::Count()
{
	return size;
}

template <class T>
DoublyCL<T>::DoublyCL()
{
	first = NULL;
	last = NULL;
	size = 0;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
	struct node2 <T>*newn = new struct node2<T>;
	newn->data2 = no;
	newn->next = NULL;
	newn->previous = NULL;
	
	if((first == NULL) && (last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		newn->next = first;
		first->previous = newn;
		first = newn;
	}
	last->next = first;
	first->previous = last;
	
	size++;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
	struct node2 <T>*newn = new struct node2<T>;
	newn->data2 = no;
	newn->next = NULL;
	newn->previous = NULL;
	
	if(first == NULL)
	{
		first = newn;
		last = newn;
	}
	else
	{	
		last->next = newn;
		newn->previous = last;
		last = newn;
	}
	last->next = first;
	first->previous = last;
	size++;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no, int iPos)
{
	int i = 0;
	if((iPos < 0) || (iPos > size+1))
	{
		return;
	}
	if(iPos == 1)
	{
		InsertFirst(no);
	}
	else if(iPos == size+1)
	{
		InsertLast(no);
	}
	else
	{
		struct node2 <T>*temp = first;
		struct node2 <T>*newn = new struct node2<T>; 
		newn->data2 = no;
		newn->next = NULL;
		newn->previous = NULL;
		
		for(i = 1;i<iPos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		newn->next->previous = newn;
		newn->previous = temp;
		temp->next = newn;
		size++;
	}
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
	if((first == NULL)&&(last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{
		first = first->next;
		delete last->next;
		first->previous = last;
		last->next = first;
	}

	size--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
	if((first == NULL) && (last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{
		last = last->previous;
		delete last->next;
		last->next = first;
		first->previous = last;
	}
	size--;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
	if((iPos < 1) || (iPos > size))
	{
		return;
	}
	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == size)
	{
		DeleteLast();
	}
	else
	{
		struct node2 <T>*temp = first;
		for(int i = 1;i < iPos-1;i++)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		delete (temp->next->previous);
		temp->next->previous = temp;
		size--;
	}
		
}

template <class T>
void DoublyCL<T>::Display()
{
	struct node2 <T>*temp = first;
	for(int i = 1;i<=size;i++)
	{
		cout<<"|"<<temp->data2<<"|->";
		temp = temp->next;
	}
	cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
	return size;
}

template <class T>
Queue<T>::Queue()
{
	first = NULL;
	size = 0;
}

template <class T>
void Queue<T>::Enqueue(T no)
{
	struct node1 <T>*newn = new struct node1<T>;
	newn->data1 = no;
	newn->next = NULL;
	
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		struct node1 <T>*temp = first;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}	
		temp->next = newn;
	}
	size++;
}

template <class T>
T Queue<T>::Dequeue()
{
	T no = 0 ;
	if(first == NULL)
	{
		return -1;
	}
	else if(first->next == NULL)
	{
		no = first->data1;
		delete first;
		first = NULL;
	}
	else
	{
		struct node1 <T>*temp = first;
		no = first->data1;
		first = first->next;
		delete temp;
	}
	size--;
	return no;
}

template <class T>
void Queue<T>::Display()
{
	struct node1 <T>*temp = first;
	while(temp != NULL)
	{
		cout<<"|"<<temp->data1<<"|  ";
		temp = temp->next;
	}
	cout<<"\n";
}

template <class T>
int Queue<T>::Count()
{
	return size;
}

template <class T>
Stack<T>::Stack()
{
	first = NULL;
	size = 0;
}

template <class T>
void Stack<T>::push(T no)
{
	struct node1 <T>*newn = new struct node1<T>;
	newn->data1 = no;
	newn->next = NULL;
	
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		newn->next = first;
		first = newn;
	}
	size++;
}

template <class T>
T Stack<T>::pop()
{
	T no = 0 ;
	if(first == NULL)
	{
		return -1;
	}
	else if(first->next == NULL)
	{
		no = first->data1;
		delete first;
		first = NULL;
	}
	else
	{
		struct node1 <T>*temp = first;
		no = first->data1;
		first = first->next;
		delete temp;
	}
	size--;
	return no;
}

template <class T>
void Stack<T>::Display()
{
	struct node1 <T>*temp = first;
	while(temp != NULL)
	{
		cout<<"|"<<temp->data1<<"|  ";
		temp = temp->next;
	}
	cout<<"\n";
}

template <class T>
int Stack<T>::Count()
{
	return size;
}

template <class T>
Tree<T>::Tree()
{
	this->size = 0;
	this->first = NULL;
}

template <class T>		
void Tree<T>::Insert(T no)
{
	struct node3 <T>*temp = first;
	
	struct node3 <T>*newn = new struct node3<T>;
	newn->data3 = no;
	newn->lchild = NULL;
	newn->rchild = NULL;
	
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		while(1)
		{
			if(no == temp->data3)
			{
				cout<<no<<" is Duplicate node\n";
				delete newn;
				break;
			}
			else if(no < temp->data3)
			{
				if(temp->lchild == NULL)
				{
					temp->lchild = newn;
					break;
				}
				temp = temp->lchild;
			}
			else if(no > temp->data3)
			{
				if(temp->rchild == NULL)
				{
					temp->rchild = newn;
					break;
				}
				temp = temp->rchild;
			}
		}
	}
	size++;
}

template <class T>
bool Tree<T>::Search(T no)
{
	struct node3 <T>*temp = first;
	bool flag = false;
	
	if(first == NULL)
	{
		return false;
	}
	else
	{
		while(temp != NULL)
		{		
			if(no == temp->data3)
			{
				flag = true;
				break;
			}
			else if(no < temp->data3)
			{
				temp = temp->lchild;
			}
			else if(no > temp->data3)
			{
				temp = temp->rchild;
			}
		}
	}
	return flag;
}

template <class T>
int Tree<T>::Count(struct node3 <T>*temp)
{
	static int iCnt = 0;
	if(temp != NULL)
	{
		iCnt++;
		Count(temp->lchild);
		Count(temp->rchild);
	}
	return iCnt;
}

template <class T>
int Tree<T>::CountLeafNode(struct node3 <T>*temp)
{
	static int iCnt = 0;
	if(temp != NULL)
	{
		if((temp->lchild == NULL) && (temp->rchild == NULL))
		{
			iCnt++;
		}
		CountLeafNode(temp->lchild);
		CountLeafNode(temp->rchild);
	}
	return iCnt;
}

template <class T>
int Tree<T>::CountParentNode(struct node3 <T>*temp)
{
	static int iCnt = 0;
	if(temp != NULL)
	{
		if((temp->lchild != NULL) || (temp->rchild != NULL))
		{
			iCnt++;
		}
		CountParentNode(temp->lchild);
		CountParentNode(temp->rchild);
	}
	return iCnt;
}

template <class T>
void Tree<T>::Inorder(struct node3 <T>*temp)
{
	if(temp != NULL)
	{
		Inorder(temp->lchild);
		cout<<temp->data3<<"\n";
		Inorder(temp->rchild);
	}
}

template <class T>
void Tree<T>::Preorder(struct node3 <T>*temp)
{
	if(temp != NULL)
	{
		cout<<temp->data3<<"\n";
		Preorder(temp->lchild);
		Preorder(temp->rchild);
	}	
}

template <class T>
void Tree<T>::Postorder(struct node3 <T>*temp)
{
	if(temp != NULL)
	{
		Postorder(temp->lchild);
		Postorder(temp->rchild);
		cout<<temp->data3<<"\n";
	}	
}

int main()
{
	SinglyLL<char> slobj;
	slobj.InsertFirst('A');
	slobj.InsertFirst('B');
	slobj.InsertFirst('C');
	slobj.InsertLast('d');
	cout<<"SinglyLL\n";
	slobj.Display();
	
	DoublyLL<int> dlobj;
	dlobj.InsertFirst(11);
	dlobj.InsertFirst(21);
	dlobj.InsertFirst(51);
	dlobj.InsertLast(101);
	cout<<"DoublyLL\n";
	dlobj.Display();
	
	SinglyCL<float> scobj;
	scobj.InsertFirst(11.5);
	scobj.InsertFirst(21.5);
	scobj.InsertFirst(51.5);
	scobj.InsertLast(101.5);
	cout<<"SinglyCL\n";
	scobj.Display();

	DoublyCL<int> dcobj;
	dcobj.InsertFirst(11);
	dcobj.InsertFirst(21);
	dcobj.InsertFirst(51);
	dcobj.InsertLast(101);
	cout<<"DoublyCL\n";
	dcobj.Display();

	Queue<char> qobj;
	qobj.Enqueue('x');
	qobj.Enqueue('y');
	qobj.Enqueue('z');
	char ch = qobj.Dequeue();
	cout<<ch<<"\n";
	qobj.Display();
	
	Stack<double> sobj;
	sobj.push(11.5);
	sobj.push(21.5);
	sobj.push(51.5);
	double d = sobj.pop();
	cout<<d<<"\n";
	sobj.Display();
	
	Tree<int> tobj;
	tobj.Insert(51);
	tobj.Insert(21);
	tobj.Insert(101);
	cout<<"Inorder\n";
	tobj.Inorder(tobj.first);
	cout<<"Preorder\n";
	tobj.Preorder(tobj.first);
	cout<<"Postorder\n";
	tobj.Postorder(tobj.first);
	
	return 0;
}