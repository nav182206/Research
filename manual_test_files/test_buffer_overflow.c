// Manual Testing Buffer Overflow Verification
#include <stdio.h>
#include <string.h>

void test_vulnerability(char *user_input) {
    char buffer[64];
    strcpy(buffer, user_input); // CWE-120 Unbounded Copy
}

int main(int argc, char **argv) {
    if (argc > 1) test_vulnerability(argv[1]);
    return 0;
}
