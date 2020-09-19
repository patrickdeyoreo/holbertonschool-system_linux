#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton Schoop School"
#define S2  "School"
#define S3  "Socool"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    printf("strchr: %p, asm_strchr: %p\n",
		(void *) strstr(S1, S1), (void *) asm_strstr(S1, S1));
    assert(strstr(S1, S1) == asm_strstr(S1, S1));
    printf("strchr: %p, asm_strchr: %p\n",
		(void *) strstr(S1, S2), (void *) asm_strstr(S1, S2));
    assert(strstr(S1, S2) == asm_strstr(S1, S2));
    printf("strchr: %p, asm_strchr: %p\n",
		(void *) strstr(S1, S3), (void *) asm_strstr(S1, S3));
    assert(strstr(S1, S3) == asm_strstr(S1, S3));
    printf("strchr: %p, asm_strchr: %p\n",
		(void *) strstr(S2, S2), (void *) asm_strstr(S2, S2));
    assert(strstr(S2, S2) == asm_strstr(S2, S2));
    printf("strchr: %p, asm_strchr: %p\n",
		(void *) strstr(S2, S3), (void *) asm_strstr(S2, S3));
    assert(strstr(S2, S3) == asm_strstr(S2, S3));
    printf("strchr: %p, asm_strchr: %p\n",
		(void *) strstr(S3, S3), (void *) asm_strstr(S3, S3));
    assert(strstr(S3, S3) == asm_strstr(S3, S3));

    printf("All good!\n");
    return (EXIT_SUCCESS);
}
