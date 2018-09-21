#include<stdio.h.>
#include<string.h>
#include<stdlib.h>


typedef struct Node
{
	int data;
	struct Node *next;
}Node;


typedef struct Queue
{
	Node *front;
	Node *rear;
	int count; // ť�� ���� ������

}Queue;


void InitQueue(Queue *queue)
{
	/* �ڵ带 �ۼ��Ͻÿ� */
	queue->front = NULL;
	queue->rear = NULL; 
	queue->count = 0;
}

int IsEmpty(Queue *queue)
{
	/* �ڵ带 �ۼ��Ͻÿ� */
	if (queue->count == 0)
		return 1;
	else
		return 0;

}


void Enqueue(Queue *queue, int data)
{

	Node *cur = (Node *)malloc(sizeof(Node)); //��� ����
	cur->data = data;
	cur->next = NULL;
	
	if (IsEmpty(queue)==1) {
		
		queue->front = cur;
	}
	else {
		queue->rear->next = cur;
	}
	queue->rear = cur;
	(queue->count)++;
}

int Dequeue(Queue *queue)
{
	if (IsEmpty(queue)) {
		printf("NULL\n");
		return 0;
	} 
	else{
		int res = queue->front->data;
		queue->front = queue->front->next;
		(queue->count)--;
		return res;
	}
}

int main(void)
{

	Queue queue; // ť ����
	InitQueue(&queue);

	for (int i = 1; i <= 5; i++)
		Enqueue(&queue, i);

	while (!IsEmpty(&queue)) {
		printf("%d\n",Dequeue(&queue));
	}

	for (int i = 1; i <= 3; i++)
		Enqueue(&queue, i);

	for (int i = 0; i < 4; i++)
		Dequeue(&queue);

	Enqueue(&queue, 10);

	while (!IsEmpty(&queue)) {
		printf("%d\n",Dequeue(&queue));
	}
	return 0;
}