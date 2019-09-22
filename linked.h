#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"
#include <vector>

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

        T front() {
            if (this->head == nullptr) {
                throw invalid_argument("Lista vacia");
            } else {
                return this->head->data;
            }
        }

        T back() {
            if (this->head == nullptr) {
                throw invalid_argument("Lista vacia");
            } else {
                return this->tail->data;
            }
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
            if (this->head == nullptr) {
                throw invalid_argument("Lista vacia");
            } else {
                Node<T> *temporal = this->head->next;
                delete this->head;
                this->head = temporal;
                this->nodes--;
            }
        }

        void pop_back() {
            if (this->head == nullptr) {
                throw invalid_argument("Lista vacia");
            } else {
                Node<T> *temporal = this->tail->prev;
                delete this->tail;
                this->tail = temporal;
                this->nodes--;
            }
        }

        T operator[](int index) {
            int indice = 0;
            Node<T>* actual = this->head;
            if (index >= this->nodes || index < 0) {
                throw invalid_argument("Indice fuera de rango");
            } else {
                while (indice != index) {
                    indice++;
                    actual = actual->next;
                }
                return actual->data;
            }
        }

        void print() {
            if (this->head == nullptr) {
                throw invalid_argument("Lista vacia");
            } else {
                Node<T>* actual = this->head;
                do {
                    cout << actual->data << ' ';
                    actual = actual->next;
                } while (actual != nullptr);
                cout << endl;
            }
        }

        bool empty() {
            return this->head == nullptr;
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            // El primer if está de más
            if (this->head == nullptr) {
                this->head = nullptr;
                this->tail = nullptr;
            } else {
                this->head->killSelf();
                this->head = nullptr;
                this->tail = nullptr;
                this->nodes = 0;
            }
        }

        void sort() {
            if (this->head == nullptr) {
                throw invalid_argument("Lista vacia");
            } else {
                vector<T> numeros;
                Node<T> *actual = this->head;
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
        }
    
        void reverse() {
            if (this->head == nullptr) {
                throw invalid_argument("Lista vacia");
            } else {
                vector<T> numeros;
                Node<T> *actual = this->head;
                for (int j = 0; j < this->nodes; ++j) {
                    numeros.push_back(actual->data);
                    actual = actual->next;
                }
                std::reverse(numeros.begin(), numeros.end());
                actual = this->head;
                for (int i = 0; i < this->nodes; ++i) {
                    actual->data = numeros[i];
                    actual = actual->next;
                }
            }
        }

        string name() {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            return BidirectionalIterator(this->head);
        }

	    BidirectionalIterator<T> end() {
            return BidirectionalIterator(this->tail->next);
        }

        void merge(LinkedList<T> &list) {
            if (this->head == nullptr && list.head == nullptr) {
                throw invalid_argument("No se puede realizar el merge, alguna de las listas esta vacia");
            } else {
                Node<T> *actual = list.head;
                do {
                    this->push_back(actual->data);
                    actual = actual->next;
                } while (actual != nullptr);
            }
        }

        ~LinkedList() {
            clear();
        }
};

#endif