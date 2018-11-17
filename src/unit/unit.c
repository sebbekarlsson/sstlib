#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../includes/ss_vector.h"


typedef struct APPLE_STRUCT {
    int id;
} apple;

apple* init_apple(int id) {
    apple* a;
    a = malloc(sizeof(apple));
    a-> id = id;
    return a;
};


static void ss_vector_test_success(void **state){
    apple* a = init_apple(0);
    ss_vector* vector = ss_init_vector(a);
    free(a);

    for (int i = 0; i < 10; i++)
        ss_vector_append(vector, init_apple(i));


    for (int i = 0; i < vector->size; i++)
        assert_int_equal(((apple*)vector->items[i])->id, i);

    ss_vector_free(vector);
}


int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(ss_vector_test_success),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
