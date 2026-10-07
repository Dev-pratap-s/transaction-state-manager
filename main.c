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


// create <id> <amount>
void createTransaction(const char *id, int amount)
{
    if (transactionCount >= MAX_TRANSACTIONS) {
        printf("Error: transaction limit reached\n");
        return;
    }

    if (amount <= 0) {
        printf("Error: amount must be greater than 0\n");
        return;
    }

    if (findTransaction(id) != -1) {
        printf("Error: transaction ID already exists\n");
        return;
    }

    strcpy(transactions[transactionCount].id, id);
    transactions[transactionCount].amount = amount;
    transactions[transactionCount].state = CREATED;

    transactionCount++;

    printf("Transaction %s created\n", id);
}


// START <id>
void startTransaction(const char *id)
{
    int index = findTransaction(id);

    if (index == -1) {
        printf("Error: transaction not found\n");
        return;
    }

    if (transactions[index].state != CREATED) {
        printf("Error: invalid state change\n");
        return;
    }

    transactions[index].state = PROCESSING;

    printf("Transaction %s is PROCESSING\n", id);
}




int main(void)
{
    printf("Transaction State Manager\n");

    return 0;
}
