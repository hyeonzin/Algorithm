#include<stdio.h>
#include<stdlib.h>

#define LEN 33


typedef int Data;

typedef struct Stack {
	Data arr[LEN];
	int top;
} Stack;

void stack_init(Stack *S) {
	S->top = -1;
}

bool isEmpty(Stack *S) {
	if (S->top == -1)
		return true;
	else
		return false;
}

void push(Stack *S, Data Data) {
	S->top += 1;
	S->arr[S->top] = Data;
	return;
}

void pop(Stack *S) {

	if (isEmpty(S) == true) {
		printf("Null");
		exit(-1);
	}

	S->top -= 1;
	return;
}


void print(Stack *S) {
	int i;
	if (isEmpty(S) == true) {
		printf("NULL");
		exit(-1);
	}

	for (i = S->top; i >=0; i--) {
		printf("%d\n", S->arr[i]);
	}
	return;
}

void make_queue(Stack *S, int len) {

	Stack temp;
	stack_init(&temp);
	while (!isEmpty(S)) {
		push(&temp, S->arr[S->top]);
		pop(S);
	}
	print(&temp);
	
}

int main() {
	Stack S;
	stack_init(&S);
	int n;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){

		push(&S, i+1);

	}

	make_queue(&S, 1);
	
	print(&S);
	

	return 0;
}