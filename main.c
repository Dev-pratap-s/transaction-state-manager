#include <stdio.h>

// transaction states 
typedef enum {
    CREATED,
    PROCESSING,
    SUCCESS,
    FAILED
} TransactionState;

int main(void)
{
    printf("Transaction State Manager\n");

    return 0;
}
