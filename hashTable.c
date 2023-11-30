#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

//定义哈希表节点
struct Node {
	int key;
	int value;
	struct Node* next;
};

//创建哈希表
struct Node* hashTable[TABLE_SIZE];

//初始化哈希表
void initHashTable(void) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		hashTable[i] = NULL;
	}
}

//哈希函数
int hashFunction(int key) {
	return key % TABLE_SIZE;
}

//插入键值对到哈希表