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


//find transaction by id
int findTransaction(const char *id)
{
    for (int i = 0; i < transactionCount; i++) {
        if (strcmp(transactions[i].id, id) == 0) {
            return i;
        }
    }

    return -1;
}

//convert state into text
const char *getStateName(TransactionState state)
{
    switch (state) {
        case CREATED:
            return "CREATED";

        case PROCESSING:
            return "PROCESSING";

        case SUCCESS:
            return "SUCCESS";

        case FAILED:
            return "FAILED";

        default:
            return "UNKNOWN";
    }
}




int main(void)
{
    printf("Transaction State Manager\n");

    return 0;
}
