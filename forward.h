#ifndef FORWARD_H
#define FORWARD_H

#include <algorithm>
#include "list.h"
#include "iterators/forward_iterator.h"

using namespace std;

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

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
            // Falta el template
            Node<T>* temporal = new Node(value);
            this->nodes++;
            if (this->head == nullptr) {
                this->head = temporal;
                this->tail = temporal;
            } else {
                temporal->next = this->head;
                this->head = temporal;
            }
        }

        void push_back(T value) {
            // Falta el template
            Node<T>* temporal = new Node(value);
            this->nodes++;
            if (this->head == nullptr) {
                this->head = temporal;
                this->tail = temporal;
            } else {
                this->tail->next = temporal;
                this->tail = temporal;
            }
        }

        void pop_front() {
            if (this->head == nullptr) {
                throw invalid_argument("Lista vacia");
            } else {
                Node<T>* temporal = this->head->next;
                delete this->head;
                this->head = temporal;
                this->nodes--;
            }
        }

        void pop_back() {
            if (this->head == nullptr) {
                throw invalid_argument("Lista vacia");
            } else {
                Node<T>* temporal = nullptr;
                Node<T>* actual = this->head;
                do {
                    if (actual->next == this->tail) {
                        temporal = actual;
                        break;
                    }
                    actual = actual->next;
                } while (actual != nullptr);
                delete this->tail;
                this->tail = temporal;
                this->tail->next = nullptr;
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
        }
    
        void reverse() {
            // Hay mejores formas de implementar esta parte
            if (this->head == nullptr) {
                throw invalid_argument("Lista vacia");
            } else {
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
        }

        string name() {
            return "Forward List";
        }

        // Falta el template
        ForwardIterator<T> begin() {
            return ForwardIterator(this->head);
        }

        // Falta el template
	    ForwardIterator<T> end() {
            return ForwardIterator(this->tail->next);
        }

        void merge(ForwardList<T> &list) {
            // Debería permitir aún si las listas están vacías
            if (this->head == nullptr && list.head == nullptr) {
                throw invalid_argument("No se puede realizar el merge, alguna de las listas esta vacia");
            } else {
                Node<T>* actual = list.head;
                do {
                    this->push_back(actual->data);
                    actual = actual->next;
                } while (actual != nullptr);
            }
        }
	
	T findMiddleElement() {
            Node<T>* actual = this->head;
            Node<T>* resultado = this->head;
            int par = 0;
            while (actual) {
                if (par > 0  && par%2 == 0) {
                    resultado = resultado->next;
                }
                par++;
                actual = actual->next;
            }
            return resultado->data;
        }

        ~ForwardList() {
            clear();
        }
};

#endif
