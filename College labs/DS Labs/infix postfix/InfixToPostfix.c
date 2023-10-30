    #include <stdio.h>
    #include<conio.h>
    #define MAX 100

    char stack[MAX];
    int top = -1,i,x;

    void push(char);
    char pop(void);
    int priority(char);
    void infixToPostfix(char exp[])
    {
        char postfix[100];
        int i=0,j=0;
        while(exp[i]!=0)
        {
            if((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= '0' && exp[i] <= '9'))
            {
                postfix[j]=exp[i];
                j++;
            }
            else if(exp[i]=='(')
            {
                push(exp[i]);
                
            }
            else if(exp[i]==')')
            {
                while((x = pop()) != '(')
                    {
                        postfix[j]=x;
                        j++;
                    }

            }
            else {
                while(priority(exp[i]) <= priority(stack[top])) {
                    postfix[j]=pop();
                    j++;
                }
                push(exp[i]);
            }
            i++;
        }
        
        while(top != -1) {
            postfix[j]=pop();
            j++;
        }
        postfix[j]=0;
        printf("The postfix of given expression is : %s\n",postfix);
    }


    int main()
    {
        char exp[100],postfix[100];
        printf("Enter the Infix Expression :");
        gets(exp);
        infixToPostfix(exp);
        return 0;
    }


    int priority(char c)
    {
        if(c=='^'||c=='$') return 3;
        else if(c=='*'||c=='/') return 2;
        else if(c=='+'||c=='-') return 1;
        else return 0;
    }

    void push(char x)
    {
        if (top == MAX - 1)
        {
            printf("\nSTACK is over flow");
            exit(0);
        }
        else
        {
            top++;
            stack[top] = x;
        }
    }

    char pop()
    {

        if (top == -1)
        {
            printf("\nStack is under flow");
            exit(0);
        }
        else return (stack[top--]);
    }