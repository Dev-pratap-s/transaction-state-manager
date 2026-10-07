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


// create <id <amount>
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


// START 
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

// SUCCESS 
void successTransaction(const char *id)
{
    int index = findTransaction(id);

    if (index == -1) {
        printf("Error: transaction not found\n");
        return;
    }

    if (transactions[index].state != PROCESSING) {
        printf("Error: invalid state change\n");
        return;
    }

    transactions[index].state = SUCCESS;

    printf("Transaction %s is SUCCESS\n", id);
}



// FAIL 
void failTransaction(const char *id)
{
    int index = findTransaction(id);

    if (index == -1) {
        printf("Error: transaction not found\n");
        return;
    }

    if (transactions[index].state != PROCESSING) {
        printf("Error: invalid state change\n");
        return;
    }

    transactions[index].state = FAILED;

    printf("Transaction %s is FAILED\n", id);
}

// STATUS 
void showStatus(const char *id)
{
    int index = findTransaction(id);

    if (index == -1) {
        printf("Error: transaction not found\n");
        return;
    }

    printf("%s | %d | %s\n",
           transactions[index].id,
           transactions[index].amount,
           getStateName(transactions[index].state));
}

// LIST
void listTransactions(void)
{
    if (transactionCount == 0) {
        printf("No transactions\n");
        return;
    }

    for (int i = 0; i < transactionCount; i++) {
        printf("%s | %d | %s\n",
               transactions[i].id,
               transactions[i].amount,
               getStateName(transactions[i].state));
    }
}



// Main command loop
int main(void)
{
    char command[20];
    char id[50];
    int amount;

    printf("Transaction State Manager\n");
    printf("Enter commands:\n");

    while (1) {

        if (scanf("%19s", command) != 1) {
            break;
        }

        if (strcmp(command, "CREATE") == 0) {

            if (scanf("%49s %d", id, &amount) != 2) {
                printf("Error: invalid CREATE command\n");
                break;
            }

            createTransaction(id, amount);
        }

        else if (strcmp(command, "START") == 0) {

            if (scanf("%49s", id) != 1) {
                printf("Error: invalid START command\n");
                break;
            }

            startTransaction(id);
        }

        else if (strcmp(command, "SUCCESS") == 0) {

            if (scanf("%49s", id) != 1) {
                printf("Error: invalid SUCCESS command\n");
                break;
            }

            successTransaction(id);
        }

        else if (strcmp(command, "FAIL") == 0) {

            if (scanf("%49s", id) != 1) {
                printf("Error: invalid FAIL command\n");
                break;
            }

            failTransaction(id);
        }

        else if (strcmp(command, "STATUS") == 0) {

            if (scanf("%49s", id) != 1) {
                printf("Error: invalid STATUS command\n");
                break;
            }

            showStatus(id);
        }

        else if (strcmp(command, "LIST") == 0) {
            listTransactions();
        }

        else if (strcmp(command, "EXIT") == 0) {
            printf("Exiting...\n");
            break;
        }

        else {
            printf("Error: unknown command\n");
        }
    }

    return 0;
}
