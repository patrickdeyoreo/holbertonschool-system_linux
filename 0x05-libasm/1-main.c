#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton School"
#define S2  ""
#define S3  "Holberton Socool"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    printf("strcmp: %2d, asm_strcmp: %2d\n", strcmp(S1, S1), asm_strcmp(S1, S1));
    printf("strcmp: %2d, asm_strcmp: %2d\n", strcmp(S1, S2), asm_strcmp(S1, S2));
    printf("strcmp: %2d, asm_strcmp: %2d\n", strcmp(S1, S3), asm_strcmp(S1, S3));
    printf("strcmp: %2d, asm_strcmp: %2d\n", strcmp(S2, S2), asm_strcmp(S2, S2));
    printf("strcmp: %2d, asm_strcmp: %2d\n", strcmp(S2, S3), asm_strcmp(S2, S3));
    printf("strcmp: %2d, asm_strcmp: %2d\n", strcmp(S3, S3), asm_strcmp(S3, S3));

    printf("All good!\n");
    return (EXIT_SUCCESS);
}
