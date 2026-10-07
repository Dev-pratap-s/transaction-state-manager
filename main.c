#include <stdio.h>


#define MAX_TRANSACTIONS 100

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

Transaction transactions[MAX_TRANSACTIONS];
int transactionCount = 0;









int main(void)
{
    printf("Transaction State Manager\n");

    return 0;
}
