#ifndef CONFIG_H
#define CONFIG_H

int load_config(const char *filename);
const char* get_get_url();
const char* get_post_url();
const char* get_post_body();

#endif