#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>
#include "config.h"

static char get_url[256];
static char post_url[256];
static char post_body[512];

int load_config(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return -1;

    fseek(fp, 0, SEEK_END);
    long len = ftell(fp);
    rewind(fp);

    char *data = malloc(len + 1);
    if (!data) return -2;
    fread(data, 1, len, fp);
    data[len] = '\0';
    fclose(fp);

    struct json_object *root = json_tokener_parse(data);
    if (!root) return -3;

    struct json_object *get_url_obj, *post_url_obj, *post_body_obj;
    if (!json_object_object_get_ex(root, "get_url", &get_url_obj)) return -4;
    if (!json_object_object_get_ex(root, "post_url", &post_url_obj)) return -5;
    if (!json_object_object_get_ex(root, "post_body", &post_body_obj)) return -6;

    strncpy(get_url, json_object_get_string(get_url_obj), sizeof(get_url));
    strncpy(post_url, json_object_get_string(post_url_obj), sizeof(post_url));
    strncpy(post_body, json_object_to_json_string(post_body_obj), sizeof(post_body));

    json_object_put(root);
    free(data);
    return 0;
}

const char* get_get_url() {
    return get_url;
}

const char* get_post_url() {
    return post_url;
}

const char* get_post_body() {
    return post_body;
}