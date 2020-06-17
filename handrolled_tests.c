#include <stdio.h>
#include <assert.h>

#include "hash_table.h"

#define run_test(fn_name)\
	printf("%s\n", #fn_name);\
	fn_name();

void test_create_ht() {
	ht_hash_table* ht = ht_new();
	assert(0 == ht->count);
}

int main(){
	run_test(test_create_ht);
	printf("\nOK\n");
	return 0;
}