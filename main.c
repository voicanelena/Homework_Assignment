#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main()
{  char S[100], grammar_rule[100];
    printf("Enter the input string: ");
    scanf("%s", S);
    printf("Enter the grammar rule: ");
    scanf("%s", grammar_rule);

    printf("minimum operations required: %d\n", min_operations_to_correct(S, grammar_rule));
    return 0;
    return 0;
}
