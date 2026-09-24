#define _GNU_SOURCE

#include "../include/ypkg.h"
#include "../include/private.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ypkg_init(ENV_VARS *env_vars) {
    env_vars->config_path = secure_getenv("YPKG_CONFIG_PATH");
    if (env_vars->config_path == NULL) {
        env_vars->config_path = (char*)YPKG_CONFIG_PATH;
    }

    env_vars->local_db_path = secure_getenv("YPKG_LOCAL_DB");
    if (env_vars->local_db_path == NULL) {
        env_vars->local_db_path = (char*)YPKG_LOCAL_DB;
    }

    env_vars->local_db = open_db(env_vars->local_db_path);
     if (env_vars->local_db == NULL) {
        fprintf(stderr, "init: could not open database %s\n", env_vars->local_db_path);
        return 1;
    }

    return 0;
}
