    #include<stdio.h>

    #define size 100
    int top=-1;
    int arr[size];

    void push(int data){
        if( top!= size-1){
            top++;
            arr[top]=data;
        }
        else{
            printf("Satck overflow!!");
        }
    }
    int pop(){
        if( top!=-1){
            int c = arr[ top];
            top--;
            return c;
        }
    }
    int postfixEvaluation(char exp[]){
        for(int i=0;i<strlen(exp);i++){
            if(exp[i]>='0'&& exp[i]<='9'){
                push(exp[i]-'0');
            }
            else{
                int op2=pop();
                int op1=pop();
                switch(exp[i]){
                    case '+':
                        push(op1+op2);
                        break;
                    case '-':
                        push(op1-op2);
                        break;
                    case '*':
                        push(op1*op2);
                        break;
                    case '/':
                        push(op1/op2);
                        break;
                    case '^':
                        push(pow(op1,op2));
                        break;
                }
            }
        }
        return  arr[top];
    }

    int main(){
        char exp[size];
        printf("Enter the postfix expression: ");
        gets(exp);
        int result = postfixEvaluation(exp);
        printf("Evaluation :%d\n",result);
    }