
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int priority;
    int order;
} Patient;

Patient heap[MAX];
int size = 0;
int arrivalOrder = 0;

// Swap two patients
void swap(Patient *a, Patient *b) {
    Patient temp = *a;
    *a = *b;
    *b = temp;
}

// Check priority; earlier arrival wins ties
int higherPriority(Patient a, Patient b) {
    if (a.priority != b.priority)
        return a.priority < b.priority;

    return a.order < b.order;
}

// Add a patient to the priority queue
void addPatient(char name[], int priority) {
    if (size >= MAX) {
        printf("Queue is full!\n");
        return;
    }

    Patient p;
    strcpy(p.name, name);
    p.priority = priority;
    p.order = arrivalOrder++;

    int i = size++;
    heap[i] = p;

    // Move patient upward in the heap
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (higherPriority(heap[parent], heap[i]))
            break;

        if (heap[parent].priority == heap[i].priority &&
            heap[parent].order < heap[i].order)
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }

    printf("Added: %s (Priority %d)\n", name, priority);
}

// Treat and remove the next patient
void treatNextPatient() {
    if (size == 0) {
        printf("No patients waiting.\n");
        return;
    }

    printf("Treating: %s (Priority %d)\n",
           heap[0].name, heap[0].priority);

    heap[0] = heap[--size];

    // Restore the min-heap
    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size &&
            higherPriority(heap[left], heap[smallest]))
            smallest = left;

        if (right < size &&
            higherPriority(heap[right], heap[smallest]))
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

int main() {
    // Step 3: Add the six patients
    addPatient("P1", 3);
    addPatient("P2", 1);
    addPatient("P3", 2);
    addPatient("P4", 1);
    addPatient("P5", 3);
    addPatient("P6", 2);

    printf("\n--- Treatment Order ---\n");

    // Treat the first three patients
    for (int i = 0; i < 3; i++)
        treatNextPatient();

    // Add a new Emergency patient
    printf("\n--- New Emergency Patient Arrives ---\n");
    addPatient("Emergency", 1);

    // Treat everyone remaining
    printf("\n--- Remaining Treatment Order ---\n");
    while (size > 0)
        treatNextPatient();

    return 0;
}
