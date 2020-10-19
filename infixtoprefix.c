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
	char s[20], pre[20];
	printf("\nenter infix expression : ");
	gets(s);
	int l = 0;
	push('(');
	int len = strlen(s);

	puts(s);
//	strrev(s);
	char t;
	for(int i=0; i<(len)/2; i++)
	{
		t = s[i];
		s[i] = s[len-i-1];
		s[len-i-1] = t;
	}
	for(int i=0; s[i] != '\0'; i++)
	{
		if(s[i] == '(')
			s[i] = ')';
		else if(s[i] == ')')
			s[i] = '(';
	}
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
			pre[l++] = s[i];	
		}
		else if(s[i] == '-' || s[i] == '+')
		{
			while(peek() == '*' || peek() == '/' || peek() == '^' || peek() == '+' || peek() == '-')
			{
				pre[l++] = pop();
			} 
			push(s[i]);
		}
		else if(s[i] == '*' || s[i] == '/')
		{
			while(peek() == '*' || peek() == '/' || peek() == '^')
			{
				pre[l++] = pop();
			} 
			push(s[i]);	
		}
		else if(s[i] == '^')
		{
			while(peek() == '^')
			{
				pre[l++] = pop();
			}
			push(s[i]);
		}
		else if(s[i] == ')')
		{
			while(peek() != '(')
			{
				pre[l++] = pop();
			}
			char z = pop();
		}
		else
			printf("\nERROR\n");
	}
//	strrev(pre);
	len = strlen(pre);
	for(int i=0; i<(len)/2; i++)
	{
		t = pre[i];
		pre[i] = pre[len-i-1];
		pre[len-i-1] = t;
	}
	printf("\n");
	puts(pre);
}











