#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

        T front() {
            return this->head->data;
        }

        T back() {
            return this->head->data;
        }

        void push_front(T value) {
            Node<T>* temporal = new Node(value);
            this->nodes++;
            if (this->head == nullptr) {
                this->head = temporal;
                this->tail = temporal;
            } else {
                temporal->next = this->head;
                this->head->prev = temporal;
                this->head = temporal;
            }
        }

        void push_back(T value) {
            Node<T>* temporal = new Node(value);
            this->nodes++;
            if (this->head == nullptr) {
                this->head = temporal;
                this->tail = temporal;
            } else {
                this->tail->next = temporal;
                temporal->prev = this->tail;
                this->tail =  temporal;
            }
        }

        void pop_front() {
            Node<T>* temporal = this->head->next;
            delete this->head;
            this->head = temporal;
            this->nodes--;
        }

        void pop_back() {
            Node<T>* temporal = this->tail->prev;
            delete this->tail;
            this->tail = temporal;
            this->nodes--;
        }

        T operator[](int index) {
            int indice = 0;
            Node<T>* actual = this->head;
            if (index >= this->nodes) {
                throw invalid_argument("Index out of range");
            } else {
                while (indice != index) {
                    indice++;
                    actual = actual->next;
                }
                return actual->data;
            }
        }

        void print() {
            Node<T>* actual = this->head;
            do {
                cout << actual->data << ' ';
                actual = actual->next;
            } while (actual != nullptr);
            cout << endl;
        }

        bool empty() {
            return this->head == nullptr;
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            this->head->killSelf();
            this->head = nullptr;
            this->tail = nullptr;
        }

        void sort() {
            vector <T> numeros;
            Node<T>* actual = this->head;
            do {
                numeros.push_back(actual->data);
                actual = actual->next;
            } while (actual != nullptr);
            std::sort(numeros.begin(), numeros.end());
            actual = this->head;
            for (int i = 0; i < this->nodes; ++i) {
                actual->data = numeros[i];
                actual = actual->next;
            }
        }
    
        void reverse() {
            vector <T> numeros;
            Node<T>* actual = this->head;
            do {
                numeros.push_back(actual->data);
                actual = actual->next;
            } while (actual != nullptr);
            std::reverse(numeros.begin(), numeros.end());
            actual = this->head;
            for (int i = 0; i < this->nodes; ++i) {
                actual->data = numeros[i];
                actual = actual->next;
            }
        }

        string name() {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            // TODO
        }

	    BidirectionalIterator<T> end() {
            // TODO
        }

        void merge(LinkedList<T> &list) {
            Node<T>* actual = list.head;
            do {
                this->push_back(actual->data);
                actual = actual->next;
            } while (actual != nullptr);
        }

        ~LinkedList() {
            clear();
        }
};

#endif