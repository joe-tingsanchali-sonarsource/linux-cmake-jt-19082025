#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple placeholder for T_memcpy, assuming it's a function similar to memcpy
void T_memcpy(void *dest, const void *src, size_t n) {
    memcpy(dest, src, n);
}

// Global variable declarations to make the code snippet compilable.
// In a real project, these would likely be declared differently.
unsigned long __n;
char local_248[256]; // Assuming a buffer to copy into

// The function you provided, reverted back to the original snippet.
int ike2_ProcessPayload_CERT(long param_1, long param_2)
{
    // The original logic you provided.
    if ((param_1 == 0) || (param_2 == 0)) {
        // omitted ...
        printf("Error: Null parameters provided.\n");
        return -1;
    }
    else {
        __n = (unsigned long)*(unsigned int *)(param_2 + 8);
        T_memcpy(local_248,*(void **)(param_2 + 0x10),__n);    // [1]
        // omitted ...
        printf("T_memcpy called with length: %lu\n", __n);
        return 0;
    }
}

int main() {
    // Example usage of the function.
    printf("Starting the program...\n");

    // We will now create a struct that correctly matches the one
    // being cast to inside the function to prevent the segmentation fault.
    struct MyPayload {
        int a[2];
        unsigned int length;
        void *data; // This must be a void pointer
    };

    struct MyPayload payload;
    char some_data[] = "Hello, C project!";
    payload.length = strlen(some_data) + 1; // Include null terminator
    payload.data = some_data; // Assign a valid pointer

    // Calling the function with valid pointers. This should now work without crashing.
    ike2_ProcessPayload_CERT(1, (long)&payload);

    // Calling the function with a null pointer to test the `if` condition.
    // This will still work as the null check is in place.
    ike2_ProcessPayload_CERT(0, 0);

    printf("Program finished.\n");
    return 0;
}
