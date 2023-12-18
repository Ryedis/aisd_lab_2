#pragma once 
#include <iostream>
#include <random>


using namespace std;

namespace linkedlist {
	template <typename T>
	struct Node {
		T value;
		Node* next;

		Node(const T& value, Node<T>* next = nullptr) : value(value), next(next) {}
	};

	template <typename T>
	class LinkedList {
	private:
		Node<T>* _head;
	public:

		Node<T>* get_head() const {
			return _head;
		}

		LinkedList() : _head(nullptr) {}

		LinkedList(const LinkedList& list) : _head(nullptr) {
			auto ptr = list._head;
			while (ptr) {
				push_tail(ptr->value);
				ptr = ptr->next;
			}
		}

		LinkedList(size_t size) {};

		LinkedList<T>& operator=(const LinkedList<T>& lst) {
			LinkedList<T> a(lst);
			std::swap(a._head, _head);
			return a;
		}

		~LinkedList() {
			while (_head) {
				auto ptr = _head;
				_head = _head->next;
				delete ptr;
			}

			_head = nullptr;
		}

		void push_tail(const T value) {
			if (_head == nullptr) {
				_head = new Node<T>(value, nullptr);
				return;
			}
			Node<T>* ptr = _head;
			while (ptr->next) {
				ptr = ptr->next;
			}
			ptr->next = new Node<T>(value, nullptr);
		}

		void push_tail(const LinkedList<T>& list) {
			auto ptr = list._head;
			while (ptr) {
				this->push_tail(ptr->value);
				ptr = ptr->next;
			}
		}

		void push_head(const T value) {
			_head = new Node<T>(value, _head);
		}

		void push_head(const LinkedList<T>& list) {
			LinkedList<T> copy(list);
			copy.push_tail(*this);
			std::swap(_head, copy._head);
		}

		void pop_head() {
			if (!_head) {
				throw out_of_range("Linked list is empty");
			}
			auto ptr = _head;
			_head = _head->next;
			delete ptr;
			ptr = nullptr;

		}

		void pop_tail() {
			if (!_head) {
				throw out_of_range("Linked list is empty");
			}
			auto ptr = _head;
			while (ptr->next->next) {
				ptr = ptr->next;
			}
			delete ptr->next;
			ptr->next = nullptr;
		}

		void delete_node(const T& value) {
			if (!_head) {
				return;
			}
			Node* ptr = _head;
			Node* previous_ptr = nullptr;

			while (ptr) {
				if (ptr->data == value) {
					if (ptr == _head) {
						_head = ptr->next;
					}
					else {
						previous_ptr->next = ptr->next;
					}
					delete ptr;
					break;
				}
				previous_ptr = ptr;
				ptr = ptr->next;
			}
		}

		T operator[](size_t index) const {
			if (index < 0 || index >= this->size()) {
				throw out_of_range("Index it out of range");
			}
			auto ptr = _head;
			for (int i = 0; i < index; i++) {
				ptr = ptr->next;
			}
			return ptr->value;
		}

		T& operator[](size_t index) {
			if (index < 0 || index >= this->size()) {
				throw out_of_range("Index it out of range");
			}
			auto ptr = _head;
			for (int i = 0; i < index; i++) {
				ptr = ptr->next;
			}
			return ptr->value;
		}

		size_t size() const {
			auto ptr = _head;
			size_t size = 0;
			while (ptr) {
				ptr = ptr->next;
				size++;
			}
			return size;
		}
	};

	template <typename T>
	ostream& operator<<(ostream& a, const LinkedList<T>& list) {
		Node<T>* ptr = list.get_head();
		while (ptr) {
			a << ptr->value << " ";
			ptr = ptr->next;
		}
		return a;
	}

	template <>
	LinkedList<int>::LinkedList(size_t size) : _head(nullptr) {
		for (int i = 0; i < size; i++) {
			this->push_tail(rand());
		}
	}

	template <>
	LinkedList<bool>::LinkedList(size_t size) : _head(nullptr) {
		for (int i = 0; i < size; i++) {
			this->push_tail(rand() % 2);
		}
	}

	template <>
	LinkedList<float>::LinkedList(size_t size) : _head(nullptr) {
		for (int i = 0; i < size; i++) {
			this->push_tail(rand() + 0.00001 * rand());
		}
	}

	template <>
	LinkedList<double>::LinkedList(size_t size) : _head(nullptr) {
		for (int i = 0; i < size; i++) {
			this->push_tail(rand() + 0.00001 * rand());
		}
	}
}