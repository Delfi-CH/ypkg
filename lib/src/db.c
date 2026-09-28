#include "../include/private.h"
#include <sqlite3.h>
#include <stddef.h>
#include <stdio.h>

sqlite3 *open_db(char *filename) {
    sqlite3 *db;
    int rc;
    rc = sqlite3_open_v2(filename, &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
    if ( rc ) {
        return NULL;
    } else {
        return db;
    }
}

int create_initial_tables(sqlite3 *db) {
    int rc;
    char *errmsg = NULL;
    rc = sqlite3_exec(db, SQL_CREATE_REPOSITORY, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    rc = sqlite3_exec(db, SQL_CREATE_PACKAGE_IDENTIFIER, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    rc = sqlite3_exec(db, SQL_CREATE_PACKAGE_IDENTIFIER_REPOSITORY, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    rc = sqlite3_exec(db, SQL_CREATE_PROVIDES, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    rc = sqlite3_exec(db, SQL_CREATE_PACKAGE, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    rc = sqlite3_exec(db, SQL_CREATE_PACKAGE_PROVIDES, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    rc = sqlite3_exec(db, SQL_CREATE_PACKAGE_DEPENDS, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    rc = sqlite3_exec(db, SQL_CREATE_PACKAGE_CONFLICTS, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    rc = sqlite3_exec(db, SQL_CREATE_METAPACKAGE, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    rc = sqlite3_exec(db, SQL_CREATE_PACKAGE_METAPACKAGE, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    rc = sqlite3_exec(db, SQL_CREATE_GROUP, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    rc = sqlite3_exec(db, SQL_CREATE_PACKAGE_GROUP, NULL, NULL, &errmsg);
    if ( rc ) {
        fprintf(stderr, "create_initial_tables: sqlite error: %s\n", errmsg);
        return rc;
    }
    return 0;
}

int close_db(sqlite3 *db) {
    return sqlite3_close(db);
}