//
//  main.c
//  strcalc
//
//  Created by Александр Гелета on 12.10.2017.
//  Copyright © 2017 Александр Гелета. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

#define ARGS_COUNT 4

#define DO_OP(o, l, r, p) fprintf(stdout, "%g\n", round_to(l o r, p));

#define INPUT_ERROR_MSG                                 \
"Error while passing expression string.                 \
Please use:\n\tstrcalc <left> {+, -, *, /} <right> <precision>\n"

#define INVALID_OP_ERROR_MSG                            \
"Unknown operation character!\n"

double round_to(double value, int chars);

int main(int argc, const char * argv[]) {
    double  left = 0.0f,            // left operand of the expression
            right = 0.0f;           // right operand of the expression
    int     rPrecision = 0;         // round precision
    char    operationChar;          // operation ASCII character
    
    // Read data from standard input and check whether expression
    // matches with %lf%c%lf format string
    if (fscanf(stdin, "%lf %c %lf %d", &left, &operationChar, &right, &rPrecision) != ARGS_COUNT) {
        fprintf(stderr, "%s", INPUT_ERROR_MSG);
        return EINVAL; // Data was invalid
    }
    
    // Check mathematic operand and use matching
    switch (operationChar) {
        case '+':
            DO_OP(+, left, right, rPrecision)
            break;
            case '-':
            DO_OP(-, left, right, rPrecision)
            break;
            case '*':
            DO_OP(*, left, right, rPrecision)
            break;
            case '/':
            DO_OP(/, left, right, rPrecision)
            break;
        default:
            fprintf(stderr, "%s", INVALID_OP_ERROR_MSG);
            return EINVAL; // Unknown operation
    }
    
    return EXIT_SUCCESS;
}

double round_to(double value, int chars) {
    int offset = pow(10, chars);
    return round(value * offset) / offset;
}
