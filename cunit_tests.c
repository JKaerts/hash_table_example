#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "hash_table.h"

#define UNUSED(x) (void)(x)

void test_create_ht(void) {
	ht_hash_table* ht = ht_new();
	CU_ASSERT_EQUAL(0, ht->count);
}

int main(int argc, char** argv) {
	UNUSED(argc);
	UNUSED(argv);
	if (CU_initialize_registry() != CUE_SUCCESS)
		errx(EXIT_FAILURE, "can't initialize test registry");
	CU_pSuite htSuite = CU_add_suite("hash_table", NULL, NULL);
	if (CU_get_error() != CUE_SUCCESS)
		errx(EXIT_FAILURE, "%s", CU_get_error_msg());
	CU_add_test(htSuite, "can create hash table", test_create_ht);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return EXIT_SUCCESS;
}
