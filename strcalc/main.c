//
//  main.c
//  strcalc
//
//  Created by Александр Гелета on 12.10.2017.
//  Copyright © 2017 Александр Гелета. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define ARGS_COUNT 3

#define INPUT_ERROR_MSG                             \
"Error while passing expression string.             \
Please use:\n\tstrcalc <left> {+, -, *, /} <right>"

int main(int argc, const char * argv[]) {
    double  left = 0.0f,            // left operand of the expression
            right = 0.0f;           // right operand of the expression
    char    operationChar;          // operation ASCII character
    
    if (fscanf(stdin, "%lf%c%lf", &left, &operationChar, &right) != ARGS_COUNT) {
        fprintf(stderr, "%s", INPUT_ERROR_MSG);
        return EINVAL;
    }
    
    return EXIT_SUCCESS;
}
