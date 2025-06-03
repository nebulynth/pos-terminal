#include <stdio.h>
#include <json-c/json.h>
#include "include/http_client.h"
#include "include/card_reader.h"
#include "include/config.h"

void handle_get() {
    struct string response;
    if (http_get(get_get_url(), &response) == 0) {
        struct json_object *parsed = json_tokener_parse(response.ptr);
        struct json_object *title;
        if (json_object_object_get_ex(parsed, "title", &title)) {
            printf("\n[GET] Title: %s\n", json_object_get_string(title));
        } else {
            printf("[GET] Title field not found.\n");
        }
        json_object_put(parsed);
        free(response.ptr);
    } else {
        fprintf(stderr, "[GET] Request failed.\n");
    }
}

void handle_post() {
    struct string response;
    long code;
    if (http_post(get_post_url(), get_post_body(), &response, &code) == 0) {
        printf("\n[POST] HTTP Status: %ld\n[POST] Body: %s\n", code, response.ptr);
        free(response.ptr);
    } else {
        fprintf(stderr, "[POST] Request failed.\n");
    }
}

void handle_card_read() {
    char buffer[256];
    if (read_card_data(buffer, sizeof(buffer)) == 0) {
        printf("\n[Card Reader] Data: %s\n", buffer);
        struct string response;
        if (http_post(get_post_url(), buffer, &response, NULL) == 0) {
            printf("[Card Reader] Response: %s\n", response.ptr);
            free(response.ptr);
        } else {
            fprintf(stderr, "[Card Reader] POST failed.\n");
        }
    } else {
        fprintf(stderr, "[Card Reader] Failed to read card.\n");
    }
}

int main() {
    if (load_config("config.json") != 0) {
        fprintf(stderr, "Failed to load config.json\n");
        return 1;
    }

    handle_get();
    handle_post();
    handle_card_read();

    return 0;
}