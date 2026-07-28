#include <iostream>

using namespace std;

template <class T>
class List;

template <class T>
class Node{
	public:
	T data;
	Node(T new_data){
		data = new_data;
		next = NULL;
	}	
	private:
	Node<T> *next;
	friend class List<T>; //List is a friend class of Node, it can directly access everything in Node
};

template <class T>
class List{
	public:
	List(){//ctor - init head
		head = NULL;
	}
	~List(){//dtor - deallocate nodes on this list
		Node<T> *cur = head;
		while(cur!=NULL){
			Node<T> *next = cur->next;
			delete cur;
			cur = next;
		}
		head = NULL;
	}
	void add(T data){ //add a new node at head
		//allocate a new node
		Node<T> *temp = new Node<T>(data);
		//connect this new node to the list
		temp->next = head;
		head = temp;
	}
	void print(){
		Node<T> *temp = head;
		while(temp != NULL){
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
	private:
		Node<T> *head;
};


int main(){
	List<int> list1;
	cout<<"list1:"<<endl;
	list1.add(5);
	list1.add(2);
	list1.add(4);
	list1.print();

	List<float> list2;
	cout<<"list2:"<<endl;
	list2.add(3.5);
	list2.add(1.2);
	list2.add(4.6);
	list2.print();

	return 0;
}
