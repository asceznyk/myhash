#include <assert.h>
#include "./hashtable.c"

int main() {
	insert("bar", 5);
	insert("cap", 10);
	insert("foo", 6);
	insert("lake", 7);
	insert("brad", 3);
	insert("pitt", 7);
	insert("clooney", 8);
	showHashTable();
	assert(get("cap") == 10);
	assert(get("clooney") == 8);
	assert(get("brad") == 3);
	update("brad", 5);
	assert(get("brad") == 5);
	delete("brad");
	delete("lake");
	assert(get("brad") == INT_MAX);
	assert(get("lake") == INT_MAX);
	showHashTable();
	assert(get("gal") == INT_MAX);
	update("gal", 3);
	delete("gal");
	showHashTable();
	insert("clooney", 7);
	assert(get("clooney") == 8);
	return 0;
}
