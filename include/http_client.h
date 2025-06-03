#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <curl/curl.h>

struct string {
    char *ptr;
    size_t len;
};

void init_string(struct string *s);
int http_get(const char *url, struct string *response);
int http_post(const char *url, const char *json_data, struct string *response, long *http_code);

#endif

