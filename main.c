#include <stdio.h>
#include "lib/cexception/CException.h"
#include "test/list_double.h"

int main() {
    List(double) lst = new_List_double();

    printf("lst is empty: %d\n", lst->is_empty(lst));

    lst->push_back(lst, 111.111);
    lst->push_back(lst, -222.222);
    lst->push_front(lst, 333.333);
    lst->push_front(lst, -444.444);

    printf("lst is empty: %d\n", lst->is_empty(lst));

    for (int i = 0; !lst->is_empty(lst); ++i) {
        printf_s("%d: %lf\n", i, lst->pop_back(lst));
    }

    printf("lst is empty: %d\n", lst->is_empty(lst));

    lst->push_back(lst, 111.111);       // [111.111]
    lst->push_back(lst, -222.222);      // [111.111, -222.222]
    lst->push_front(lst, 333.333);      // [333.333, 111.111, -222.222]
    lst->push_front(lst, -444.444);     // [-444.444, 333.333, 111.111, -222.222]
    lst->push_back(lst, 555.555);       // [-444.444, 333.333, 111.111, -222.222, 555.555]

    for (int i = 0; i < (int) lst->_size; ++i) {
        printf("%d: %lf\n", i, lst->at(lst, i));
    }
    puts("");

    for (int i = 0; i < (int) lst->_size; ++i) {
        lst->set(lst, i, (i + 1) * 111.111);
    }

    for (int i = 0; i < (int) lst->_size; ++i) {
        printf("%d: %lf\n", i, lst->at(lst, i));
    }

    delete_List_double(lst);

    return 0;
}
