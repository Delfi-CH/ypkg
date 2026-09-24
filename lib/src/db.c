#include "../include/private.h"
#include <sqlite3.h>
#include <stddef.h>
#include <stdio.h>

sqlite3 *open_db(char *filename) {
    sqlite3 *db;
    int rc;
    rc = sqlite3_open_v2(filename, &db, SQLITE_OPEN_CREATE, NULL);
    if ( rc ) {
        return NULL;
    } else {
        return db;
    }
}

int create_initial_tables(sqlite3 *db) {
    int rc;
    char *errmsg = NULL;
    rc = sqlite3_exec(db, REPOSITORY_SQL_CREATE_TABLE_STATEMENT, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    rc = sqlite3_exec(db, PACKAGE_SQL_CREATE_TABLE_STATEMENT, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    rc = sqlite3_exec(db, PROVIDES_SQL_CREATE_TABLE_STATEMENT, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    rc = sqlite3_exec(db, PACKAGE_PROVIDES_SQL_CREATE_TABLE_STATEMENT, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    rc = sqlite3_exec(db, PACKAGE_DEPENDENCY_SQL_CREATE_TABLE_STATEMENT, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    rc = sqlite3_exec(db, PACKAGE_CONFLICTS_SQL_CREATE_TABLE_STATEMENT, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    rc = sqlite3_exec(db, METAPACKAGE_SQL_CREATE_TABLE_STATEMENT, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    rc = sqlite3_exec(db, GROUP_SQL_CREATE_TABLE_STATEMENT, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    rc = sqlite3_exec(db, PACKAGE_GROUP_SQL_CREATE_TABLE_STATEMENT, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    return 0;
}

int close_db(sqlite3 *db) {
    return sqlite3_close(db);
}