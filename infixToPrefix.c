#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a new stack
struct Stack* create(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to push an element onto the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '\0'; // You can return some error value here
}

// Function to get the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to check if a character is an operand
int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void reverse (char *exp)
{

  int size = strlen (exp);
  int j = size, i = 0;
  char temp[size];

  temp[j--] = '\0';
  while (exp[i] != '\0')
    {
      temp[j] = exp[i];
      j--;
      i++;
    }
  strcpy (exp, temp);
}
void brackets (char *exp)
{
  int i = 0;
  while (exp[i] != '\0')
    {
      if (exp[i] == '(')
	exp[i] = ')';
      else if (exp[i] == ')')
	exp[i] = '(';
      i++;
    }
}

void postfixToInfix(char *exp){
    reverse (exp);
    brackets (exp);
    getPostfix (exp);
    reverse (exp);

    printf("Prefix is: %s", exp);
}
// Function to convert infix expression to postfix expression
void getPostfix(char* expression) {
    int i, j;

    struct Stack* stack = create(strlen(expression));
    if (!stack) {
        printf("Memory allocation error\n");
        return;
    }

    for (i = 0, j = -1; expression[i]; ++i) {
        if (isOperand(expression[i]))
            expression[++j] = expression[i];
        else if (expression[i] == '(')
            push(stack, expression[i]);
        else if (expression[i] == ')') {
            while (!isEmpty(stack) && stack->array[stack->top] != '(')
                expression[++j] = pop(stack);
            if (!isEmpty(stack) && stack->array[stack->top] != '(') {
                printf("Invalid expression\n");
                return;
            } else
                pop(stack);
        } else {
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(stack->array[stack->top]))
                expression[++j] = pop(stack);
            push(stack, expression[i]);
        }
    }
    while (!isEmpty(stack))
        expression[++j] = pop(stack);

    expression[++j] = '\0';
}

int main() {
    char infixExpression[100];
    printf("Enter an infix expression: ");
    scanf("%s", infixExpression);

    getPostfix(infixExpression);

    printf("Postfix expression: %s\n", infixExpression);
    postfixToInfix(infixExpression);

    return 0;
}
