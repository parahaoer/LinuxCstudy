/* push.c */
extern char stack[512];
extern int top;
void push(char c)
{
    stack[++top] = c;
}

int is_empty(void)
{
    return top == -1;
}