#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define CAPACITY 10

typedef struct Entry {
	char* key;
	int val;
	struct Entry* next; 
} Entry;

Entry* hashTable[CAPACITY]; //an array of pointers

unsigned int hash(char* key) {
	unsigned int hashval = 0;
	for (int i = 0; key[i] != '0'; i++) {
		hashval = key[i] + (hashval << 5) - hashval; 
	}
	return hashval % CAPACITY;
}

void insert(char* key, int val) {
	unsigned int bucket = hash(key);
	Entry* curr = hashTable[bucket];
	while (curr) {
		if (strcmp(key, curr->key) == 0) {
			printf("key %s exists already!\n", key);
			return;
		};
		curr = curr->next;
	}
	Entry* entry = malloc(sizeof(Entry));
	entry->key = strdup(key);
	entry->val = val;
	entry->next = hashTable[bucket];
	hashTable[bucket] = entry;
}

int get(char* key) {
	unsigned int bucket = hash(key);
	Entry* curr = hashTable[bucket];
	while (curr) {
		if (strcmp(key, curr->key) == 0) {
			printf("hashTable['%s'] = %d\n", key, curr->val);
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
	Entry* curr = hashTable[bucket];
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
	Entry* curr = hashTable[bucket];
	if (curr != 0 && strcmp(key, curr->key) == 0) {
		hashTable[bucket] = curr->next;
		free(curr);
		printf("\n");
		return;
	}
	while (curr) {
		if (curr->next != NULL && strcmp(key, curr->next->key) == 0) {
			Entry* tmp = curr->next;
			curr->next = curr->next->next;
			free(tmp);
			printf("\n");
			return;
		}
		curr = curr->next;
	}
	printf("key '%s' does not exist!\n", key);
}

void showHashTable() {
	printf("HashTable -> \n");
	for (unsigned int b = 0; b < CAPACITY; b++) {
		Entry* curr = hashTable[b];
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

