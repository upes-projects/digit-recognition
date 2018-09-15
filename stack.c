#include"matrix.c"

struct stack_node{
	struct matrix * data;
	struct stack_node * point;
};

struct stack{
	long size;
	struct stack_node *top;
};

struct stack * newStack(){
	struct stack * sta = (struct stack *) malloc(sizeof(struct stack));
	sta->size = 0;
	sta->top = NULL;

	return sta;
}

long countStackElement(struct stack *sta){
	return sta->size;
}

void pushStackElement(struct stack *sta, struct matrix *mat){
	sta->size++;
	
	struct stack_node * node = (struct stack_node*) malloc(sizeof(struct stack_size));
	node->data = mat;

	node->point = sta->top;

	sta->top = node;
}

struct matrix * popStackElement(struct stack *sta){
	struct matrix * mat = (sta->top)->data;
	struct stack_node * temp = sta->top;
	sta->top = temp->point;
	free(temp);

	return mat;
}

void popStackElementDeleteMatrix(struct stack *sta){
	struct matrix * mat = popStackElement(sta); 
	deleteMatrix(mat);

}



struct matrix * viewStackElement(struct stack *sta){
	return (sta->top)->data;
}


void deleteStack(struct stack *sta){
	while(sta->size){
		popStackElementDeleteMatrix(sta);
		sta->size--;
	}

	free(sta);
}




