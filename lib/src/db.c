#include "../include/ypkg.h"
#include <sqlite3.h>
#include <stddef.h>

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

}

int close_db(sqlite3 *db) {
    return sqlite3_close(db);
}