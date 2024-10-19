#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure to store phone book entries
struct PhoneBookEntry {
    char name[50];
    char phoneNumber[15];
};

// Function for binary search
int binarySearch(struct PhoneBookEntry phoneBook[], int n, const char* target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Compare middle entry with target
        int cmp = strcmp(phoneBook[mid].name, target);
        if (cmp == 0) {
            return mid; // Found
        }
        if (cmp < 0) {
            left = mid + 1; // Search right
        } else {
            right = mid - 1; // Search left
        }
    }
    return -1; // Not found
}

// Driver code
int main() {
    struct PhoneBookEntry phoneBook[MAX] = {
        {"Gauri", "9146898345"},
        {"Neha", "9123456789"},
        {"Supriya", "9876543210"},
        {"Vaishnavi", "9988776655"}
    };

    int n = 4; // Number of entries in the phone book
    char target[50];
    
    // Sorting is assumed to be done before searching
    printf("Enter a name to search: ");
    scanf("%s", target);

    int result = binarySearch(phoneBook, n, target);
    if (result != -1) {
        printf("Phone number of %s: %s\n", target, phoneBook[result].phoneNumber);
    } else {
        printf("Name not found in the phone book.\n");
    }

    return 0;
}



