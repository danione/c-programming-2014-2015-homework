#include <stdio.h>
#include <stdlib.h>

struct stack_t
{
	int size_,top_;
	char *data_;
};

int create(char brackets[])
{
	scanf("%s", brackets);
}
int are_they_a_pair(char, char);

int balanced_or_not();

void stack_init();

int pop();

void push(struct stack_t* , char);

void release();

int main()
{
	struct stack_t stack;
	char brackets[100];
	
	stack_init(&stack);
	create(brackets);
	balanced_or_not(brackets);
	release(&stack);
	
	return 0;
}

int are_they_a_pair(char part1, char part2)
{
	if( part1 == '{' && part2 == '}')
	{
		return 0;
	}else if( part1 == '(' && part2 == ')')
	{
		return 0;
	}else if( part1 == '[' && part2 == ']')
	{ 
		return 0;
	}else 
	{
		return -1;
	}
}

void stack_init(struct stack_t *stack)
{
	stack->top_ = 0;
	stack->size_ = 100;
	stack->data_ = (char*) malloc(stack->size_ * sizeof(char));
}

int pop(struct stack_t *stack)
{
	return stack->data_[stack->top_] = stack->data_[--stack->top_];
}


void release(struct stack_t *stack)
{
	free(stack->data_);
	stack->top_ = 0;
	stack->size_ = 0;
}
int balanced_or_not(char brackets[])
{
	int index;
	struct stack_t stack;
	
	for(index = 0; brackets[index] != '\0'; index ++)
	{
		if(brackets[index] == '{' || brackets[index] == '[' || brackets[index] == '(')
		{
			push(&stack,brackets[index]);
		}else if (brackets[index] == '}' || brackets[index] == ']' || brackets[index] == ')')
		{
			if((stack.top_ == 0) || (!are_they_a_pair(stack.data_[stack.top_],brackets[index])) )
			{
				printf("Not balanced\n");
				return -1;
			}else {
			pop(&stack);
			}
		}
	}
	if(stack.top_ == 0)
	{
		printf("Balanced\n");
		return 0;
	}else 
	{
		printf("Not balanced\n");
		return -1;
	}
}
void push(struct stack_t *stack, char part1)
{
	stack->data_[stack->top_] = part1;
	stack->top_ ++;
}	
