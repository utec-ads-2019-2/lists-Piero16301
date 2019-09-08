#include <iostream>
#include "test/tester.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "\tLists Practice" << endl;
    cout << "===========================================================" << endl << endl;

    //Tester::execute();
    //=========== Forward list test ===========//
    /*ForwardList<int> forwardList;
    ForwardList<int> listaSimple;
    forwardList.push_back(34);
    forwardList.push_back(12);
    forwardList.push_back(364);
    forwardList.push_back(9);
    forwardList.push_back(3);
    cout << forwardList[3] << endl;
    cout << forwardList.size() << endl;
    forwardList.print();
    forwardList.sort();
    forwardList.print();
    forwardList.reverse();
    forwardList.print();
    listaSimple.push_back(1000);
    listaSimple.push_back(2000);
    listaSimple.push_back(3000);
    listaSimple.print();
    forwardList.merge(listaSimple);
    forwardList.print();
    listaSimple.print();*/

    //=========== Linked list test ===========//

    LinkedList<int> linkedList;
    LinkedList<int> listaDoble;
    linkedList.push_back(34);
    linkedList.push_back(26);
    linkedList.push_back(3);
    linkedList.push_back(624);
    linkedList.push_back(84);
    cout << linkedList[3] << endl;
    cout << linkedList.size() << endl;
    linkedList.print();
    linkedList.sort();
    linkedList.print();
    linkedList.reverse();
    linkedList.print();
    listaDoble.push_back(1000);
    listaDoble.push_back(2000);
    listaDoble.push_back(3000);
    listaDoble.print();
    linkedList.merge(listaDoble);
    linkedList.print();
    listaDoble.print();

    return EXIT_SUCCESS;
}
