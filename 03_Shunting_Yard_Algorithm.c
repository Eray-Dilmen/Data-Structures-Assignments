#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>





char stack[100];
int top = -1;

/// Adding element to the stack
void push(char item) {
    if (top >= 100 - 1) {
        printf("Stack is full!\n");
    } else {
        stack[++top] = item;
    }
}




/// extract element from the stack
char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}





int oncelik(char ch) {
    if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}







void infixToPostfix(char* infix, char* postfix) {
    int i = 0; // infix index
    int j = 0; // postfix index
    char item;
    char x;

    while (infix[i] != '\0') {
        item = infix[i];

        if (isalnum(item)) {
            postfix[j++] = item;
        }

        else if (item == '(') {
            push(item);
        }
        else if (item == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        }
        else {
            while (top != -1 && oncelik(stack[top]) >= oncelik(item)) {
                postfix[j++] = pop();
            }
            push(item);
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}





/// Ex 1 in table --> a*b+c
///     Token (Read)      Stack     Output (Postfix)    Action / Description
//          a                       a                   Operand (variable) add to output
//          *               *       a                   Stack is empty, push operator *
//          b               *       ab                  Operand, add to output
//          +               +       ab*                 Precedence of * (in stack) > + Pop * to output, push +
//          c               +       ab*c                Operand, add to output."
// End                              ab*c+               Input ended, pop remaining operator +


/// Ex 2 in table --> (a+b)*c

///     Token (Read)       Stack     Output (Postfix)    Action / Description
//          (               (                            Left parenthesis, push to stack
//          a               (           a                Operand, add to output
//          +               (+          a                Push operator + to stack
//          b               (+          ab               Operand, add to output
//          )                           ab+              Right parenthesis found. Pop stack until (, discard parens
//          *               *           ab+              Stack is empty, push operator *
//          c               *           ab+c             Operand, add to output
//          End                         ab+c*            Input ended, pop remaining operator *





/// Shunting Yard Algoritması,  yazdığımız  'karmaşık', parantezli Infix ifadeleri alır;
/// bilgisayarın "tek seferde, soldan sağa, hiç duraksamadan" hesaplayabileceği Postfix ifadeye dönüştürür.

/// "The Shunting Yard Algorithm takes the 'complex', parenthesized Infix expressions we write
/// and converts them into a Postfix expression that the computer can calculate 'in a single pass, from left to right, without pausing'.




int main(void)
{

	/// HW 3: Converting an infix expression to a postfix expression using the Shunting Yard algorithm.




    /// Ex 1
    char def1[] = "a*b+c";
    char result1[100];

    top = -1;
    infixToPostfix(def1, result1);
    printf("Infix: %s  --> Postfix: %s\n", def1, result1); // postfix result: ab*c+

    /// Ex 2
    char def2[] = "(a+b)*c";
    char result2[100];

    top = -1;
    infixToPostfix(def2, result2);
    printf("Infix: %s --> Postfix: %s\n", def2, result2); //  postfix result: ab+c*

    return 0;


}