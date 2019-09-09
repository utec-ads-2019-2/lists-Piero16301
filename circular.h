#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

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
                temporal->prev = temporal;
                temporal->next = temporal;
                this->head = temporal;
                this->tail = temporal;
            } else {
                temporal->next = this->head;
                temporal->prev = this->tail;
                this->tail->next = temporal;
                this->head->prev = temporal;
                this->head = temporal;
            }
        }

        void push_back(T value) {
            Node<T>* temporal = new Node(value);
            this->nodes++;
            if (this->head == nullptr) {
                temporal->prev = temporal;
                temporal->next = temporal;
                this->head = temporal;
                this->tail = temporal;
            } else {
                temporal->prev = this->tail;
                temporal->next = this->head;
                this->tail->next = temporal;
                this->head->prev = temporal;
                this->tail = temporal;
            }
        }

        void pop_front() {
            if (this->head == nullptr) {
                throw invalid_argument("Lista vacia");
            } else {
                Node<T> *temporal = this->head->next;
                delete this->head;
                temporal->prev = this->tail;
                this->tail->next = temporal;
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
                temporal->next = this->head;
                this->head->prev = temporal;
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
                Node<T>* actual = this->head->next;
                cout << this->head->data << ' ';
                while (actual != this->head) {
                    cout << actual->data << ' ';
                    actual = actual->next;
                }
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
            Node<T>* actual = this->head->next;
            delete this->head;
            while (actual != this->head) {
                delete actual;
                actual = actual->next;
            }
        }

        void sort() {
            if (this->head == nullptr) {
                throw invalid_argument("Lista vacia");
            } else {
                vector<T> numeros;
                Node<T> *actual = this->head->next;
                numeros.push_back(this->head->data);
                while (actual != this->head) {
                    numeros.push_back(actual->data);
                    actual = actual->next;
                }
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
                Node<T> *actual = this->head->next;
                numeros.push_back(this->head->data);
                while (actual != this->head) {
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
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            // TODO
        }

	    BidirectionalIterator<T> end() {
            // TODO
        }

        void merge(CircularLinkedList<T> &list) {
            if (this->head == nullptr || list.head == nullptr) {
                throw invalid_argument("No se puede realizar el merge, alguna de las listas esta vacia");
            } else {
                Node<T> *actual = list.head->next;
                this->push_back(list.head->data);
                while (actual != list.head) {
                    this->push_back(actual->data);
                    actual = actual->next;
                }
            }
        }

        ~CircularLinkedList() {
            clear();
        }
};

#endif