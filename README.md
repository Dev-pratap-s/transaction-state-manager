# Transaction State Manager

A command-line **Transaction State Manager** developed in **C (C11)**.

The program creates transactions, stores their details, and manages their state according to valid transaction flow.

## Problem Statement

The system manages payment transactions using the following commands:

```text
CREATE <id> <amount>
START <id>
SUCCESS <id>
FAIL <id>
STATUS <id>
LIST
EXIT
```

Each transaction has:

- Transaction ID
- Amount
- Current State

## Transaction State Flow

A transaction follows this valid state flow:

```text
              START
CREATED ----------------> PROCESSING
                              |
                    +---------+---------+
                    |                   |
                 SUCCESS              FAIL
                    |                   |
                    v                   v
                 SUCCESS              FAILED
```

`SUCCESS` and `FAILED` are final states.

A transaction cannot be moved back to `CREATED` or `PROCESSING` after reaching a final state.

## Technologies

- C
- C11 Standard
- GCC
- Standard C Library

## Concepts Used

This project demonstrates the following C programming concepts:

- `enum`
- `struct`
- Arrays
- Strings
- Functions
- Function parameters
- `if-else`
- `for` loop
- `while` loop
- `switch-case`
- `return`
- `strcmp()`
- `strcpy()`
- Command-line input using `scanf()`
- Basic state-machine logic
- Input validation and error handling

## Data Structures

### Transaction State

An `enum` is used to represent the fixed transaction states:

```c
typedef enum {
    CREATED,
    PROCESSING,
    SUCCESS,
    FAILED
} TransactionState;
```

### Transaction Structure

A `struct` stores the complete information of one transaction:

```c
typedef struct {
    char id[50];
    int amount;
    TransactionState state;
} Transaction;
```

### Transaction Storage

The program supports up to 100 transactions using a fixed-size array:

```c
#define MAX_TRANSACTIONS 100

Transaction transactions[MAX_TRANSACTIONS];
int transactionCount = 0;
```

## Commands

### 1. CREATE

Creates a new transaction.

```text
CREATE TXN101 500
```

Expected output:

```text
Transaction TXN101 created
```

A newly created transaction starts in the `CREATED` state.

---

### 2. START

Moves a transaction from `CREATED` to `PROCESSING`.

```text
START TXN101
```

Expected output:

```text
Transaction TXN101 is PROCESSING
```

---

### 3. SUCCESS

Moves a transaction from `PROCESSING` to `SUCCESS`.

```text
SUCCESS TXN101
```

Expected output:

```text
Transaction TXN101 is SUCCESS
```

---

### 4. FAIL

Moves a transaction from `PROCESSING` to `FAILED`.

```text
FAIL TXN101
```

Expected output:

```text
Transaction TXN101 is FAILED
```

---

### 5. STATUS

Displays the transaction ID, amount and current state.

```text
STATUS TXN101
```

Example output:

```text
TXN101 | 500 | PROCESSING
```

---

### 6. LIST

Displays all stored transactions.

```text
LIST
```

Example output:

```text
TXN101 | 500 | SUCCESS
TXN102 | 1000 | FAILED
```

---

### 7. EXIT

Exits the program.

```text
EXIT
```

Expected output:

```text
Exiting...
```

## Validation and Error Handling

The program safely handles invalid operations.

### Duplicate Transaction ID

```text
CREATE TXN101 500
CREATE TXN101 1000
```

Output:

```text
Error: transaction ID already exists
```

### Invalid Amount

```text
CREATE TXN102 0
```

Output:

```text
Error: amount must be greater than 0
```

### Unknown Transaction

```text
START TXN999
```

Output:

```text
Error: transaction not found
```

### Invalid State Change

For example, after a transaction reaches `SUCCESS`:

```text
START TXN101
```

Output:

```text
Error: invalid state change
```

### Unknown Command

```text
PAY TXN101
```

Output:

```text
Error: unknown command
```

## Program Structure

The major responsibilities are separated into functions:

```text
findTransaction()
        |
        v
Find transaction by ID

getStateName()
        |
        v
Convert enum state to readable text

createTransaction()
        |
        v
Create new transaction

startTransaction()
        |
        v
CREATED -> PROCESSING

successTransaction()
        |
        v
PROCESSING -> SUCCESS

failTransaction()
        |
        v
PROCESSING -> FAILED

showStatus()
        |
        v
Display one transaction

listTransactions()
        |
        v
Display all transactions

main()
        |
        v
Read and process user commands
```

## Approach / Thinking

The program treats the transaction state as a simple state machine.

When a transaction is created:

```text
CREATED
```

The only valid next state is:

```text
PROCESSING
```

From `PROCESSING`, the transaction can move to either:

```text
SUCCESS
```

or:

```text
FAILED
```

Once the transaction reaches `SUCCESS` or `FAILED`, no further state change is allowed.

The program first searches for a transaction using its unique ID. If the transaction exists, the requested operation checks whether the state transition is valid before changing the state.

## Assumptions

- Maximum 100 transactions are supported.
- Transaction IDs must be unique.
- Transaction amount must be greater than 0.
- Transaction IDs are treated as strings.
- `SUCCESS` and `FAILED` are final states.
- Transactions are stored in memory only.
- Data is lost when the program exits.
- Commands are entered in uppercase as specified by the assignment.

## Build

Compile the program using GCC:

```bash
gcc -std=c11 -Wall -Wextra main.c -o transaction_manager
```

## Run

### Linux / macOS

```bash
./transaction_manager
```

### Windows

```bash
transaction_manager.exe
```

## Sample Run

### Input

```text
CREATE TXN101 500
START TXN101
STATUS TXN101
SUCCESS TXN101
START TXN101
LIST
EXIT
```

### Output

```text
Transaction State Manager
Enter commands:
Transaction TXN101 created
Transaction TXN101 is PROCESSING
TXN101 | 500 | PROCESSING
Transaction TXN101 is SUCCESS
Error: invalid state change
TXN101 | 500 | SUCCESS
Exiting...
```

## Project Structure

```text
transaction-state-manager/
│
├── main.c
└── README.md
```

## Git Commit History

The project was developed incrementally using meaningful Git commits:

```text
initial Setup
add transaction states
add transaction structure
add transaction storage
Implement findTransaction function
add state name helper
create
start functionality
success functionality
fail functionality
add status functionality
Add functionality list all transaction
update main fuction acc. to input and output then error handling
```

This incremental approach makes it easier to understand how each part of the application was developed.

## Author

**Dev Pratap Singh Chauhan**

GitHub: `Dev-pratap-s`

## Assignment

**Assignment 1 - C: Transaction State Manager**

The project is implemented according to the provided assignment requirements using C11, `struct`, `enum`, separate functions, state validation, transaction storage, and command processing.
