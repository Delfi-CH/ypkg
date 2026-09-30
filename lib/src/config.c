#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <iniparser/iniparser.h>
#include "../include/ypkg.h"

static char iniparser_error_message[1024];

static int callback(const char *format, ...) {
    va_list args;
    va_start(args, format);

    vsnprintf(iniparser_error_message, sizeof(iniparser_error_message), format, args);

    va_end(args);

    return 0;
}

int init_config(YPKG_ENV_VARS *env_vars, char **errmsg) {
    iniparser_set_error_callback(callback);
    int rc = 0;
    FILE *config_file = fopen(env_vars->config_path, "r");
    if (config_file == NULL) {
        config_file = fopen(env_vars->config_path, "w");
        if (config_file == NULL) {
            rc = asprintf(errmsg, "error: could not create file %s: %s", env_vars->config_path, strerror(errno));
            if (rc) {
                fprintf(stderr, "%s", *errmsg);
                return 1;
            } 
            return 1;
        }
    }
    dictionary *config_dict = iniparser_load_file(config_file, env_vars->config_path);
    if (config_dict == NULL) {
        rc = asprintf(errmsg, "error: could not parse configuration file %s: %s", env_vars->config_path, iniparser_error_message);
        if (rc) {
            fprintf(stderr, "%s", *errmsg);
            return 1;
        } 
        iniparser_freedict(config_dict);
        return 1;
    }
    iniparser_freedict(config_dict);
    return 0;
}

YPKG_Config *read_config(YPKG_ENV_VARS *env_vars, char **errmsg) {
    int rc = 0;
    iniparser_set_error_callback(callback);
    YPKG_Config *config = calloc(1, sizeof(*config));
    dictionary *config_file = iniparser_load(env_vars->config_path);
    if (config_file == NULL) {
        rc = asprintf(errmsg, "error: could not parse configuration file %s: %s", env_vars->config_path, iniparser_error_message);
        if (rc) {
            fprintf(stderr, "%s", *errmsg);
            return NULL;
        } 
        iniparser_freedict(config_file);
        return NULL;
    }
    config->parallel_downloads = iniparser_getuint64(config_file, "general:parallel_downloads", 5);

    return config;
} 

int ypkg_config_exists(YPKG_ENV_VARS *env_vars) {
    struct stat st = {0};
    if (stat(env_vars->config_base_dir, &st) == -1) {
        mkdir(env_vars->config_base_dir, 0644);
    }
    FILE *config_file = fopen(env_vars->config_path, "r");
    if (config_file == NULL) {
        return 0;
    } else {
        return 1;
    }
}