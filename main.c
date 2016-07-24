#include <stdio.h>
#include "lib/cexception/CException.h"
#include "test/list_double.h"

int main() {
    List(double) lst = new_List_double();
    List(double) for_append = new_List_double();
    List(double) for_prepend = new_List_double();
    List(double) for_embed = new_List_double();

    for (int i = 0; i < 3; ++i) {
        for_append->push_back(for_append, 888.888);
        for_prepend->push_back(for_prepend, 999.999);
    }

    void* $ = for_embed;

    for_embed->push_back($, 123.456);
    for_embed->push_back($, 234.567);
    for_embed->push_back($, 345.678);

    $ = NULL;


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
    lst->insert(lst, 2, -666.666);      // [-444.444, 333.333, -666.666, 111.111, -222.222, 555.555]

    lst->append(lst, for_append);
    lst->prepend(lst, for_prepend);
    lst->embed(lst, 6, for_embed);

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
    puts("");

    printf("size=%d\n", lst->_size);
    printf("%lf, ", lst->pop(lst, 8));      // pop an element from the middle,
    printf("%lf, ", lst->pop(lst, 0));      // from the beginning
    printf("%lf\n", lst->pop(lst, -1));     // and from the end
    printf("size=%d\n", lst->_size);

    puts("");

    for (int i = 0; i < (int) lst->_size; ++i) {
        printf("%d: %lf\n", i, lst->at(lst, i));
    }
    puts("");

    lst->swap(lst, 3, 7);

    for (int i = 0; i < (int) lst->_size; ++i) {
        printf("%d: %lf\n", i, lst->at(lst, i));
    }
    puts("");

    List(double) dup = lst->copy(lst);

    delete_List_double(lst);
    delete_List_double(for_append);
    delete_List_double(for_prepend);
    delete_List_double(for_embed);

    for (int i = 0; i < (int) dup->_size; ++i) {
        printf("%d: %lf\n", i, dup->at(dup, i));
    }
    puts("");

    List(double) slc_1 = dup->slice(dup, 2, 7, 1);
    List(double) slc_2 = dup->slice(dup, -1, 10, -2);

    for (int i = 0; i < (int) slc_1->_size; ++i) {
        printf("%d: %lf\n", i, slc_1->at(slc_1, i));
    }
    puts("");

    for (int i = 0; i < (int) slc_2->_size; ++i) {
        printf("%d: %lf\n", i, slc_2->at(slc_2, i));
    }
    puts("");

    slc_2->reverse(slc_2);

    for (int i = 0; i < (int) slc_2->_size; ++i) {
        printf("%d: %lf\n", i, slc_2->at(slc_2, i));
    }
    puts("");

    List(double) rev = slc_1->reversed(slc_1);

    for (int i = 0; i < (int) rev->_size; ++i) {
        printf("%d: %lf\n", i, rev->at(rev, i));
    }
    puts("");

    delete_List_double(dup);
    delete_List_double(slc_1);
    delete_List_double(slc_2);
    delete_List_double(rev);

    return 0;
}
