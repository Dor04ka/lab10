#include <iostream>
#include <string>
using namespace std;

template <typename T>
class MyBinaryTree {
private:

	struct Node
	{
		T value;
		Node* left;
		Node* right;

		Node(T value) {
			this->value = value;
			left = nullptr;
			right = nullptr;
		}
	};

	// корень дерева
	Node* root;

	// очистка дерева
	void clean(Node *root) {
		if (root != nullptr) {
			root->left = nullptr;
			root->right = nullptr;
			delete root;
		}
	}

	// проверка наличия значения в дереве
	bool inclusion(Node* root, T value) {
		if (root == nullptr) {
			return false;
		}
		else if (root->value == value) {
			return true;
		}
		else if (value < root->value) {
			inclusion(root->left, value);
		}
		else {
			inclusion(root->right, value);
		}
	}

	// печать дерева
	void print(Node* root, size_t len) const {
		if (root == nullptr) {
			for (size_t i = 0; i < len; i++) {
				cout << "\t";
			}
			cout << "?" << endl;
		}
		else {
			print(root->right, len + 1);
			for (size_t i = 0; i < len; i++)
				cout << "\t";
			cout << root->value << endl;
			print(root->left, len + 1);
		}
	}


public:

	// конструктор по умолчанию
	MyBinaryTree() {
		root = nullptr;
	}

	// конструктор с параметром
	MyBinaryTree(T value) {
		root = new Node(value);
	}
	
	// деструктор
	~MyBinaryTree() {
		clean(root);
	}

	// добавление значения в дерево
	void push(T value) {
		// если такой элемент уже есть
		if (inclusion(root, value) == true) {
			return;
		}
		else if (root == nullptr) {
			root = new Node(value);
		}
		else {
			// делаем копию, чтобы не менять основной root
			Node* newRoot = root;
			while (true) {
				// если меньше -> идем влево
				if (value < newRoot->value) {
					if (newRoot->left == nullptr) {
						newRoot->left = new Node(value);
						break;
					}
					else {
						newRoot = newRoot->left;
					}
				}
				// если больше -> тдем вправо
				else if (value > newRoot->value) {
					if (newRoot->right == nullptr) {
						newRoot->right = new Node(value);
						break;
					}
					else {
						newRoot = newRoot->right;
					}
				}
			}
			
		}
	}

	// перегрузка <<
	friend ostream& operator << (ostream& os, const MyBinaryTree& tree) {
		tree.print(tree.root, 0);
		return os;
	}

};

int main() {

	setlocale(LC_ALL, "ru");

	// Дерево с элементами типа int
	{
		cout << "Дерево №1. Тип данных int" << endl;
		MyBinaryTree<int> tree1;
		cout << "Сколько элементов будет в дереве? ";
		size_t size1;
		cin >> size1;
		for (size_t i = 0; i < size1; i++) {
			cout << "Введите элемент под номером " << i + 1 << ": ";
			int value;
			cin >> value;
			tree1.push(value);
		}
		cout << "Ваше дерево №1:" << endl;
		cout << tree1 << endl << endl << endl;
	}

	// Дерево с элементами типа double
	{
		cout << "Дерево №2. Тип данных double" << endl;
		MyBinaryTree<double> tree2;
		cout << "Сколько элементов будет в дереве? ";
		size_t size2;
		cin >> size2;
		for (size_t i = 0; i < size2; i++) {
			cout << "Введите элемент под номером " << i + 1 << ": ";
			double value;
			cin >> value;
			tree2.push(value);
		}
		cout << "Ваше дерево №2:" << endl;
		cout << tree2 << endl << endl << endl;
	}

	// Дерево с элементами типа string
	{
		cout << "Дерево №3. Тип данных string" << endl;
		MyBinaryTree<string> tree3;
		cout << "Сколько элементов будет в дереве? ";
		size_t size3;
		cin >> size3;
		for (size_t i = 0; i < size3; i++) {
			cout << "Введите элемент под номером " << i + 1 << ": ";
			string value;
			cin >> value;
			tree3.push(value);
		}
		cout << "Ваше дерево №3:" << endl;
		cout << tree3 << endl << endl << endl;
	}

}