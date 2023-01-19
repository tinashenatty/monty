#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @top: top of the stack
 * @line_number: number of line in editor
 *
 * Return: void
 */
void add(stack_t **top, unsigned int line_number)
{
	stack_t *popped;
	unsigned int length;

	length = stack_length(*top);
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free(data.line), fclose(data.file);
		exit(EXIT_FAILURE);
	}
	else if (length < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free(data.line), fclose(data.file);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	else
	{
		popped = *top;
		*top = (*top)->prev;
		(*top)->next = NULL;
		popped->prev = NULL;
		/* Performing The Addition */
		(*top)->n += popped->n;
		free(popped);
	}
}


/**
 * subtract - subtracts the top element from the next element on the stack
 * @top: top of the stack
 * @line_number: number of current line of code in editor
 *
 * Return: void
 */
void subtract(stack_t **top, unsigned int line_number)
{
	stack_t *popped;
	unsigned int length;

	length = stack_length(*top);
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free(data.line), fclose(data.file);
		exit(EXIT_FAILURE);
	}
	else if (length < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free(data.line), fclose(data.file);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	else
	{
		popped = *top;
		*top = (*top)->prev;
		(*top)->next = NULL;
		popped->prev = NULL;
		/* Performing The Subtraction */
		(*top)->n -= popped->n;
		free(popped);
	}
}


/**
 * divide - divide the second element by the first element on the stack
 * @top: top of the stack
 * @line_number: number of current line of code in editor
 *
 * Return: void
 */
void divide(stack_t **top, unsigned int line_number)
{
	stack_t *popped;
	unsigned int length;

	length = stack_length(*top);
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free(data.line), fclose(data.file);
		exit(EXIT_FAILURE);
	}
	else if (length < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free(data.line), fclose(data.file);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	else if ((*top)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free(data.line), fclose(data.file);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	else
	{
		popped = *top;
		*top = (*top)->prev;
		(*top)->next = NULL;
		popped->prev = NULL;
		/* Performs the Division */
		(*top)->n /= popped->n;
		free(popped);
	}
}


/**
 * multiply - multiplies the second element by the first element on the stack
 * @top: top of the stack
 * @line_number: number of current line of code in editor
 *
 * Return: void
 */
void multiply(stack_t **top, unsigned int line_number)
{
	stack_t *popped;
	unsigned int length;

	length = stack_length(*top);
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free(data.line), fclose(data.file);
		exit(EXIT_FAILURE);
	}
	else if (length < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free(data.line), fclose(data.file);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	else
	{
		popped = *top;
		*top = (*top)->prev;
		(*top)->next = NULL;
		popped->prev = NULL;
		/* Performing The Subtraction */
		(*top)->n *= popped->n;
		free(popped);
	}
}


/**
 * modulus - gets the modulus of the top two elements of the stack
 * @top: top of the stack
 * @line_number: number of current line of code in editor
 *
 * Return: void
 */
void modulus(stack_t **top, unsigned int line_number)
{
	stack_t *popped;
	unsigned int length;

	length = stack_length(*top);
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free(data.line), fclose(data.file);
		exit(EXIT_FAILURE);
	}
	else if (length < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free(data.line), fclose(data.file);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	else if ((*top)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free(data.line), fclose(data.file);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	else
	{
		popped = *top;
		*top = (*top)->prev;
		(*top)->next = NULL;
		popped->prev = NULL;
		/* Performs the Division */
		(*top)->n %= popped->n;
		free(popped);
	}
}
