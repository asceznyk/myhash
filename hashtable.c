#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define CAPACITY 10

typedef struct entry {
	char* key;
	int val;
	struct entry* next; 
} entry;

entry* hashtable[CAPACITY]; //an array of pointers

unsigned int hash(char* key) {
	unsigned int hashval = 0;
	for (int i = 0; key[i] != '0'; i++) {
		hashval = key[i] + (hashval << 5) - hashval;
	}
	return hashval % CAPACITY;
}

void insert(char* key, int val) {
	unsigned int bucket = hash(key);
	entry* curr = hashtable[bucket];
	while (curr) {
		if (strcmp(key, curr->key) == 0) {
			printf("key %s exists already!\n", key);
			return;
		};
		curr = curr->next;
	}
	entry* entry = malloc(sizeof(Entry));
	entry->key = strdup(key);
	entry->val = val;
	entry->next = hashtable[bucket];
	hashtable[bucket] = entry;
}

int get(char* key) {
	unsigned int bucket = hash(key);
	entry* curr = hashtable[bucket];
	while (curr) {
		if (strcmp(key, curr->key) == 0) {
			printf("hashtable['%s'] = %d\n", key, curr->val);
			return curr->val;
		};
		curr = curr->next;
	}
	printf("could not get: key '%s' does not exist!\n", key);
	return INT_MAX;
};

void update(char* key, int val) {
	printf("updating '%s'... ", key);
	unsigned int bucket = hash(key);
	entry* curr = hashtable[bucket];
	while (curr) {
		if (strcmp(key, curr->key) == 0) {
			curr->val = val;
			printf("\n");
			return;
		};
		curr = curr->next;
	}
	printf("key '%s' does not exist!\n", key);
}

void delete(char* key) {
	printf("deleting key '%s' ... ", key);
	unsigned int bucket = hash(key);
	entry* curr = hashtable[bucket];
	if (curr != 0 && strcmp(key, curr->key) == 0) {
		hashtable[bucket] = curr->next;
		free(curr);
		printf("\n");
		return;
	}
	while (curr) {
		if (curr->next != NULL && strcmp(key, curr->next->key) == 0) {
			entry* tmp = curr->next;
			curr->next = curr->next->next;
			free(tmp);
			printf("\n");
			return;
		}
		curr = curr->next;
	}
	printf("key '%s' does not exist!\n", key);
}

void show_hashtable() {
	printf("hashtable -> \n");
	for (unsigned int b = 0; b < CAPACITY; b++) {
		entry* curr = hashtable[b];
		if (curr == NULL) continue;
		printf("b = %d\t", b);
		while (curr) {
			printf("%s, %d -> ", curr->key, curr->val);
			curr = curr->next;
		}
		printf("NULL\n");
	}
	printf("---\n");
}

