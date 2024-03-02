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

	// ������ ������
	Node* root;

	// ������� ������
	void clean(Node *root) {
		if (root != nullptr) {
			root->left = nullptr;
			root->right = nullptr;
			delete root;
		}
	}

	// �������� ������� �������� � ������
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

	// ������ ������
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

	// ����������� �� ���������
	MyBinaryTree() {
		root = nullptr;
	}

	// ����������� � ����������
	MyBinaryTree(T value) {
		root = new Node(value);
	}
	
	// ����������
	~MyBinaryTree() {
		clean(root);
	}

	// ���������� �������� � ������
	void push(T value) {
		// ���� ����� ������� ��� ����
		if (inclusion(root, value) == true) {
			return;
		}
		else if (root == nullptr) {
			root = new Node(value);
		}
		else {
			// ������ �����, ����� �� ������ �������� root
			Node* newRoot = root;
			while (true) {
				// ���� ������ -> ���� �����
				if (value < newRoot->value) {
					if (newRoot->left == nullptr) {
						newRoot->left = new Node(value);
						break;
					}
					else {
						newRoot = newRoot->left;
					}
				}
				// ���� ������ -> ���� ������
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

	// ���������� <<
	friend ostream& operator << (ostream& os, const MyBinaryTree& tree) {
		tree.print(tree.root, 0);
		return os;
	}

};

int main() {

	setlocale(LC_ALL, "ru");

	// ������ � ���������� ���� int
	{
		cout << "������ �1. ��� ������ int" << endl;
		MyBinaryTree<int> tree1;
		cout << "������� ��������� ����� � ������? ";
		size_t size1;
		cin >> size1;
		for (size_t i = 0; i < size1; i++) {
			cout << "������� ������� ��� ������� " << i + 1 << ": ";
			int value;
			cin >> value;
			tree1.push(value);
		}
		cout << "���� ������ �1:" << endl;
		cout << tree1 << endl << endl << endl;
	}

	// ������ � ���������� ���� double
	{
		cout << "������ �2. ��� ������ double" << endl;
		MyBinaryTree<double> tree2;
		cout << "������� ��������� ����� � ������? ";
		size_t size2;
		cin >> size2;
		for (size_t i = 0; i < size2; i++) {
			cout << "������� ������� ��� ������� " << i + 1 << ": ";
			double value;
			cin >> value;
			tree2.push(value);
		}
		cout << "���� ������ �2:" << endl;
		cout << tree2 << endl << endl << endl;
	}

	// ������ � ���������� ���� string
	{
		cout << "������ �3. ��� ������ string" << endl;
		MyBinaryTree<string> tree3;
		cout << "������� ��������� ����� � ������? ";
		size_t size3;
		cin >> size3;
		for (size_t i = 0; i < size3; i++) {
			cout << "������� ������� ��� ������� " << i + 1 << ": ";
			string value;
			cin >> value;
			tree3.push(value);
		}
		cout << "���� ������ �3:" << endl;
		cout << tree3 << endl << endl << endl;
	}

}