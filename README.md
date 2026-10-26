
# Challenge 09 — Patient Priority Queue (C)

## Project Description

This project implements a Patient Priority Queue using a Min-Heap in C. It determines which patient should be treated next based on their medical priority.

## Priority Rules

- Priority 1: Emergency
- Priority 2: Urgent
- Priority 3: Routine

A patient with a lower priority number is treated first. If two patients have the same priority, the patient who arrived first is treated first.

## Features

- Add a patient with a name and priority number.
- Treat the next patient according to priority.
- Automatically reorder patients using a Min-Heap.
- Handle patients with equal priorities in arrival order.
- Allow a new Emergency patient to move ahead of waiting Urgent and Routine patients.

## Technologies Used

- Programming Language: C
- Data Structure: Min-Heap
- Algorithm: Priority Queue

## Test Cases

The program adds the following patients:

| Patient | Priority |
|---------|----------|
| P1      | 3        |
| P2      | 1        |
| P3      | 2        |
| P4      | 1        |
| P5      | 3        |
| P6      | 2        |

### Expected Treatment Order

Initially, the patients are treated in this order:

1. P2 — Emergency
2. P4 — Emergency
3. P3 — Urgent

A new Emergency patient then arrives.

The remaining treatment order is:

4. Emergency — Priority 1
5. P6 — Urgent
6. P1 — Routine
7. P5 — Routine

## How to Compile and Run

Compile the program using GCC:

```bash
gcc -std=c11 -Wall -Wextra -pedantic challenge09.c -o challenge09
```

Run the program:

```bash
./challenge09
```

On Windows, run:

```bash
challenge09.exe
```

## How It Works

The program uses a Min-Heap to keep the most urgent patient at the root. When a patient is added, the heap restores its order. When the next patient is treated, the root is removed and the heap is rearranged.

Patients with priority 1 are always treated before patients with priority 2 or 3. For equal priorities, arrival order is preserved.

## Conclusion

This project demonstrates how a priority queue can manage hospital patients efficiently. It ensures that Emergency patients receive treatment before less urgent patients, even when they arrive later.

## Author

Student Project — Challenge 09
