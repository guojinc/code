#include <CUnit/Basic.h>
#include "2.c"

void test_infixToPostfix(void) {
    char infix1[MAX_SIZE] = "A+B*C";
    char postfix1[MAX_SIZE];
    infixToPostfix(infix1, postfix1);
    CU_ASSERT_STRING_EQUAL(postfix1, "ABC*+");

    char infix2[MAX_SIZE] = "(A+B)*C";
    char postfix2[MAX_SIZE];
    infixToPostfix(infix2, postfix2);
    CU_ASSERT_STRING_EQUAL(postfix2, "AB+C*");

    char infix3[MAX_SIZE] = "A*B+C";
    char postfix3[MAX_SIZE];
    infixToPostfix(infix3, postfix3);
    CU_ASSERT_STRING_EQUAL(postfix3, "AB*C+");
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite1 = CU_add_suite("postfix_test_suite", 0, 0);

    CU_add_test(suite1, "test_infixToPostfix", test_infixToPostfix);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}