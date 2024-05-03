#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* generate_id() {
    static char id_string[20]; // Make sure this array is large enough to hold your ID as a string
    time_t t;
    srand((unsigned) time(&t));
    int id = rand();
    sprintf(id_string, "%d", id);
    return id_string;
}

int main() {
    char* id = generate_id();
    printf("Generated ID: %s\n", id);
    return 0;
}
