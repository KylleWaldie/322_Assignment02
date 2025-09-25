char * AUTHOR_NAME = (char *) "Jakub Pach";
char * AUTHOR_AUTHORSHIP = (char *) "I acknowledge that I have worked on this assignment independently, except where explicitly noted and referenced. Any collaboration or use of external resources has been properly cited. I am fully aware of the consequences of academic dishonesty and agree to abide by the university's academic integrity policy. I understand the seriousness and implications of plagiarism.";


//#define clearBuffer() while (getchar() != '\n');
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "math_ops.h"

//#include "tests\tests.c"
// ----------------- MAIN PROGRAM -----------------

int main(int argc, char *argv[]) 
{

// To change the command-line parameters, modify the following line:
// lanuch.json.10:
// "args": ["--help"], 
// "args": ["--subtraction", "5", "3.0"] , // argues! attention not ["--subtraction 5 3.0"] <-- whole string in argv[1]!!!
// etc.

    float angle = 45.0;       // degrees
    int steps = 10;           // number of terms in Taylor series

    float sin_result = my_sin(angle, steps);
    float cos_result = my_cos(angle, steps);

    printf("sin(%.1f) = %.6f\n", angle, sin_result);
    printf("cos(%.1f) = %.6f\n", angle, cos_result);
    
    int failed_tests  = 0;

    printf("%s\n", argv[0]);
    printf("%s\n", argv[1]);
    printf("%s\n", argv[2]);
    printf("%s\n", argv[3]);
    printf("%f\n", atof(argv[2]) );

    if (argc > 1 )
    {
        if(strcmp(argv[1], "--author") == 0) 
            printf("author"); //printf(AUTHOR_NAME);
        else if(strcmp(argv[1], "--authorship") == 0) 
           printf("AUTHOR"); //printf(AUTHOR_AUTHORSHIP);
        else if(strcmp(argv[1], "--help") == 0) 
        {
            printf("\nOptions:\n");
            printf("  --author             Print author name\n");
            printf("  --authorship         Print academic honesty statement\n");
            printf("  --addition a b       Add two numbers\n");
            printf("  --subtraction a b    Subtract two numbers\n");
            printf("  --multiplication a b Multiply two numbers\n");
            printf("  --division a b       Divide two numbers\n");
            printf("  --power a b          Raise a to the power of b\n");
            printf("  --square a           Square of a number\n");
            printf("  --cube a             Cube of a number\n");
        }
    }
    else
    {
        printf("Wrong parameter. Use --help to see available options.\n");
        return 1; // Wrong parameter
    }

    getchar(); // pause before exit (Windows)

    return failed_tests; // cmd/powershell:  echo $LASTEXITCODE
}

