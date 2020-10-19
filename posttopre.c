#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node
{
	char data[10];
	struct node *next;
};
struct node *top = NULL;
void push(char x[])
{
	struct node *p = (struct node*)malloc(sizeof(struct node));
	strcpy(p->data, x);
	if(top == NULL)
	{
		top = p;
		p->next = NULL;
		return;
	}
	p->next = top;
	top = p;
}
char* pop()
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
char* peek()
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
	printf("\nenter postfix expression : ");
	gets(s);
	int l = 0;
	int len = strlen(s);
	for(int i=0; s[i] != '\0'; i++)
	{
		char t[10];
		t[0] = s[i];
		t[1] = '\0';
		if(toupper(s[i]) >= 'A' && toupper(s[i]) <= 'Z')
		{
			push(t);
		}
		else if(s[i] == '-' || s[i] == '+' || s[i] == '*' || s[i] == '/' || s[i] == '^')
		{
			char s1[10];
			strcpy(s1,pop());
			char s2[10];
			strcpy(s2,pop());
			char ch[10] = "";
			strcat(ch, t);
			strcat(ch, s2);
			strcat(ch, s1);
			push(ch);
		}
		else
			printf("\nERROR\n");
	}
	printf("\n");
	strcpy(pre,pop());
	puts(pre);
}











