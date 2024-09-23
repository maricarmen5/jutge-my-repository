#include "llista.hpp"

void Llista::separa(Llista &l2) {
    node* actual = _prim;
    node* anteriorl1 = NULL;
    node* anteriorl2 = NULL;

    while (actual != NULL) {
        if (actual->seg != NULL) {
            node* parell = new node;
            parell->info = actual->seg->info;
            parell->seg = NULL;

            if (anteriorl2 == NULL) {
                anteriorl2 = parell;
                l2._prim = parell;
            }
            else {
                anteriorl2->seg = parell;
                anteriorl2 = parell;
            }

            ++l2._long;
            --_long;

            if (anteriorl1 == NULL) anteriorl1 = actual;
            else {
                anteriorl1->seg = actual;
                anteriorl1 = actual;
            }

            actual = actual->seg->seg;
            anteriorl1->seg = NULL;
        }
        else {
            if (anteriorl1 != NULL) anteriorl1->seg = actual;
            actual = actual->seg;
        }
    }
}