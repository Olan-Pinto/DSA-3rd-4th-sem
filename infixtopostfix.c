#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node
{
	char data;
	struct node *next;
};
struct node *top = NULL;
void push(char x)
{
	struct node *p = (struct node*)malloc(sizeof(struct node));
	p->data = x;
	if(top == NULL)
	{
		top = p;
		p->next = NULL;
		return;
	}
	p->next = top;
	top = p;
}
char pop()
{
	if(top == NULL)
	{
		return;
	}
	struct node *p = top;
	top = top->next;
	return p->data;
	free(p);	
}
char peek()
{
	if(top == NULL)
	{
		return;
	}	
	return top->data;
}
void main()
{
	
/*	do
	{
		printf("\nenter option : 1-push, 2-pop, 3-peek, 0-quit\n");
		scanf("%d", &o);
		switch(o)
		{
			case 1:
				printf("\nenter data : ");
				scanf("%d", &x);
				push(x);
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
				
		}
	}while(o != 0);
*/
	char s[20], post[20];
	printf("\nenter infix expression : ");
	gets(s);
	int l = 0;
	push('(');
	int len = strlen(s);
	s[len] = ')';
	s[len + 1] = '\0';
	for(int i=0; s[i] != '\0'; i++)
	{
		if(s[i] == '(')
		{
			push(s[i]);			
		}
		else if(toupper(s[i]) >= 'A' && toupper(s[i]) <= 'Z')
		{
			post[l++] = s[i];	
		}
		else if(s[i] == '-' || s[i] == '+')
		{
			while(peek() == '*' || peek() == '/' || peek() == '^' || peek() == '+' || peek() == '-')
			{
				post[l++] = pop();
			} 
			push(s[i]);
		}
		else if(s[i] == '*' || s[i] == '/')
		{
			while(peek() == '*' || peek() == '/' || peek() == '^')
			{
				post[l++] = pop();
			} 
			push(s[i]);	
		}
		else if(s[i] == '^')
		{
			while(peek() == '^')
			{
				post[l++] = pop();
			}
			push(s[i]);
		}
		else if(s[i] == ')')
		{
			while(peek() != '(')
			{
				post[l++] = pop();
			}
			char z = pop();
		}
		else
			printf("\nERROR\n");
	}
	printf("\n");
	puts(post);
}











