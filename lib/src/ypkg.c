#define _GNU_SOURCE

#include "../include/ypkg.h"
#include "../include/private.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int ypkg_init(YPKG_ENV_VARS *env_vars, char **errmsg) {
    if (env_vars == NULL || errmsg == NULL)
        return 1;

    int rc = 0;
    env_vars->config_path = secure_getenv("YPKG_CONFIG_PATH");
    if (env_vars->config_path == NULL) {
        env_vars->config_path = (char*)YPKG_CONFIG_PATH;
    }

    env_vars->local_db_path = secure_getenv("YPKG_LOCAL_DB");
    if (env_vars->local_db_path == NULL) {
        env_vars->local_db_path = (char*)YPKG_LOCAL_DB;
    }

    env_vars->config_base_dir = secure_getenv("YPKG_CONFIG_BASE_DIR");
    if (env_vars->config_base_dir == NULL) {
        env_vars->config_base_dir = (char*)YPKG_CONFIG_BASE_DIR;
    }

    env_vars->local_db_base_dir = secure_getenv("YPKG_LOCAL_DB_BASE_DIR");
    if (env_vars->local_db_base_dir == NULL) {
        env_vars->local_db_base_dir = (char*)YPKG_LOCAL_DB_BASE_DIR;
    }

    if (!ypkg_local_db_exists(env_vars) && geteuid()) {
        asprintf(errmsg, "please run this program as root to initialise all the configuration file");
        return 1;
    }

    env_vars->local_db = open_db(env_vars);
    if (env_vars->local_db == NULL) {
        asprintf(errmsg, "cannot open local database %s", env_vars->local_db_path);
        return 1;
    }

    if (!ypkg_config_exists(env_vars) && geteuid()) {
        asprintf(errmsg, "please run this program as root to initialise all the configuration file");
        return 1;
    }

    rc = init_config(env_vars, errmsg);
    if ( rc ) {
        return rc;
    }

    env_vars->config = read_config(env_vars, errmsg);
    if (env_vars->config == NULL) {
        return 1;
    }

    rc = create_initial_tables(env_vars->local_db);
    if ( rc ) {
        return rc;
    }

    return 0;
}
