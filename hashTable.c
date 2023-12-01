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
void insert(int key, int value) {
	int index = hashFunction(key);

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL) {
		printf("Memory allocation failed. Exiting...\n");
		return; // 或者采取其他错误处理方式
	}
	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;

	if (hashTable[index] == NULL) {
		hashTable[index] = newNode;
	}
	else {
		struct Node* temp = hashTable[index];
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

//查找键对应的值
int search(int key) {
	int index = hashFunction(key);

	struct Node* temp = hashTable[index];
	while (temp != NULL) {
		if (temp->key == key) {
			return temp->value;
		}
		temp = temp->next;
	}
	return -1;//没有找到
}

int main(void) {
	initHashTable();

	insert(5, 10);
	insert(2, 20);
	insert(15, 30);

	printf("Value for key 5: %d\n", search(5));	//应该输出10
	printf("Value for key 15: %d\n", search(15));	//应该输出30
	printf("Value for key 8: %d\n", search(8));	//应该输出-1（未找到）

	return 0;
}