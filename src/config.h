#ifndef CONFIG_H
#define CONFIG_H

#include "common.h"
#include "log.h"

#define N_NAMES (int)(sizeof(names)/sizeof(names[0]))

static char *names[] = {
    "reg_info",
    "reg_host",
    "reg_user",
    "reg_pass",
    "reg_timeout",
    "program_name",
    "max_concurrent_calls",
};

#define CONFIG_REGINFO 0
#define CONFIG_REGHOST 1
#define CONFIG_REGUSER 2
#define CONFIG_REGPASS 3
#define CONFIG_TIMEOUT 4
#define CONFIG_PROGRAM 5
#define CONFIG_MAXCALLS 6


typedef struct {
    char *val[N_NAMES];
    const char *config_file;
} cdata_t;

extern cdata_t config;

int config_init(const char *filename);
void config_reload(void);

void config_free(void);
int config_readint(uint8_t pos);
const char *config_readstring(uint8_t pos);
#endif
