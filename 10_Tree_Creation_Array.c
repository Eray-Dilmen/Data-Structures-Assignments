#include <stdio.h>
#include <stdlib.h>


char treeChar[20];
int treeInt[20];


void initArrays() {
    for(int i = 0; i < 20; i++) {
        treeChar[i] = '\0';
        treeInt[i] = -1;
    }
}




// Rule-> root -> left -> right
void preOrderChar(int index) {
    if (index >= 20 || treeChar[index] == '\0') return;

    printf("%c ", treeChar[index]); // root
    preOrderChar(2 * index + 1);    // go Left
    preOrderChar(2 * index + 2);    // go right
}



void preOrderInt(int index) {
    if (index >= 20 || treeInt[index] == -1) return;

    printf("%d ", treeInt[index]);
    preOrderInt(2 * index + 1);
    preOrderInt(2 * index + 2);
}





int main(void)
{

    /// HW 10.1:  Create simple Tree with array like in below:




    // Ex: For the expression a = b + c * 2, AST is:

/*
       =
      / \
     a   +
        / \
       b   *
          / \
         c   2
*/

    initArrays();

    // Root
    treeChar[0] = '=';

    // Level 1
    treeChar[1] = 'a'; // Left of Root
    treeChar[2] = '+'; // Right of Root

    // Level 2 (Children of '+')
    // Parent is at index 2. Left = 2*2+1 = 5. Right = 2*2+2 = 6.
    treeChar[5] = 'b';
    treeChar[6] = '*';

    // Level 3 (Children of '*')
    // Parent is at index 6. Left = 6*2+1 = 13. Right = 6*2+2 = 14.
    treeChar[13] = 'c';
    treeChar[14] = '2';

    printf("root node: %c\n", treeChar[0]); // output -> =
    printf("on the right operation of the root: %c\n", treeChar[2]); // output -> +

    printf("Pre-Order Traversal of Expression Tree: ");
    preOrderChar(0);
    printf("\n");







    /// HW 10.2:
    printf("\n---------\n");

    // let's creating that example on below with code, after that we'll turn this tree into pre-order
/*
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
*/


    // Root
    treeInt[0] = 1;

    // Children of 1
    treeInt[1] = 2;
    treeInt[2] = 3;

    // Children of 2 (Index 1 -> Left: 3, Right: 4)
    treeInt[3] = 4;
    treeInt[4] = 5;

    // Children of 3 (Index 2 -> Left: 5, Right: 6)
    treeInt[5] = 6;
    treeInt[6] = 7;

    printf("Pre-Order output: ");
    preOrderInt(0); // 1 2 4 5 3 6 7
    printf("\n");






    /// HW 10.3: why we use Pre-order Traversal in trees ?

//    1-Tree Cloning (Copying): It is the primary method used to create a copy of a tree because the root is processed before its children, allowing you to build the structure from the top down.
//    2-Serialization: It is used to store a tree in a file or database in a way that preserves the original hierarchy when it is reconstructed later.
//    3-Expression Trees: It helps in converting expression trees into Prefix notation (Polish Notation), which is useful for certain compiler designs.
//    4-Directory Structures: It is ideal for listing directories and files in a hierarchical folder structure, where the parent folder must be accessed before its contents.

    return 0;
}