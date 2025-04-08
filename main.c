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
	get("cap");
	get("clooney");
	get("brad");
	update("brad", 5);
	get("brad");
	delete("brad");
	delete("lake");
	showHashTable();
	get("gal");
	update("gal", 3);
	delete("gal");
	showHashTable();
	insert("clooney", 7);
	return 0;
}
