#include <stdio.h>
#include <string.h>
#include "card_reader.h"

// Simulated card data (in real life, use USB/serial communication)
int read_card_data(char *buffer, size_t max_len) {
    const char *simulated = "{\"card_number\": \"4111111111111111\", \"expiry\": \"12/26\", \"cvv\": \"123\"}";
    if (strlen(simulated) >= max_len) return -1;
    strcpy(buffer, simulated);
    return 0;
}

