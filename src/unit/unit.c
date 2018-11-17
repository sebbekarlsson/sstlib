#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../includes/ss_vector.h"
#include "../includes/ss_strutils.h"


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

static void ss_strutils_test_success(void **state) {
    char* int_str0 = "-16";
    char* int_str1 = "+16";
    char* int_str2 = "16";
    char* int_str3 = "abc16";

    assert_int_equal(ss_is_int(int_str0), 1);
    assert_int_equal(ss_is_int(int_str1), 1);
    assert_int_equal(ss_is_int(int_str2), 1);
    assert_int_equal(ss_is_int(int_str3), 0);
}


int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(ss_vector_test_success),
        cmocka_unit_test(ss_strutils_test_success),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
