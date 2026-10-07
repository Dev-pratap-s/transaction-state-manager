#include <stdio.h>

// transaction states 
typedef enum {
    CREATED,
    PROCESSING,
    SUCCESS,
    FAILED
} TransactionState;


typedef struct {
    char id[50];
    int amount;
    TransactionState state;
} Transaction;











int main(void)
{
    printf("Transaction State Manager\n");

    return 0;
}
