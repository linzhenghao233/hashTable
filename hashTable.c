#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

//�����ϣ��ڵ�
struct Node {
	int key;
	int value;
	struct Node* next;
};

//������ϣ��
struct Node* hashTable[TABLE_SIZE];

//��ʼ����ϣ��
void initHashTable(void) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		hashTable[i] = NULL;
	}
}

//��ϣ����
int hashFunction(int key) {
	return key % TABLE_SIZE;
}

//�����ֵ�Ե���ϣ��