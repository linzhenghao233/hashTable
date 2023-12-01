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
void insert(int key, int value) {
	int index = hashFunction(key);

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL) {
		printf("Memory allocation failed. Exiting...\n");
		return; // ���߲�ȡ����������ʽ
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

//���Ҽ���Ӧ��ֵ
int search(int key) {
	int index = hashFunction(key);

	struct Node* temp = hashTable[index];
	while (temp != NULL) {
		if (temp->key == key) {
			return temp->value;
		}
		temp = temp->next;
	}
	return -1;//û���ҵ�
}

int main(void) {
	initHashTable();

	insert(5, 10);
	insert(2, 20);
	insert(15, 30);

	printf("Value for key 5: %d\n", search(5));	//Ӧ�����10
	printf("Value for key 15: %d\n", search(15));	//Ӧ�����30
	printf("Value for key 8: %d\n", search(8));	//Ӧ�����-1��δ�ҵ���

	return 0;
}