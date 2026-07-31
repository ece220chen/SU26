#include <vector>
using namespace std; 

template <class T>
struct node{
	T data;
	node<T> *left;
	node<T> *right;
};

template <class T>
class bst{
	public:
		bst();
		~bst();
		void insert(T data);
		node<T> *search(T data);
		void inorder();
		int countnodes();

	private:
		void delete_tree(node<T> *root);
		void insert(T data, node<T> *root);
		node<T> *search(T data, node<T> *root);
		void inorder(node<T> *root, vector<T> &v);
		int countnodes(node<T> *root);
		node<T> *root;
};
