typedef struct node Node;
typedef struct stack Stack;

Stack* create();

void push(Stack* stack, int value);
void pop(Stack* stack);

bool isEmpty(Stack* stack);

void freeStack(Stack* stack);
void printStack(Stack* stack);
