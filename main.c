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


    return 0;
}
