#ifndef YPKG_PRIVATE_H

#define YPKG_PRIVATE_H

#include <sqlite3.h>

// consts

extern const char* PROVIDES_SQL_CREATE_TABLE_STATEMENT;

extern const char* PACKAGE_PROVIDES_SQL_CREATE_TABLE_STATEMENT;

extern const char* PACKAGE_SQL_CREATE_TABLE_STATEMENT;

extern const char* PACKAGE_DEPENDENCY_SQL_CREATE_TABLE_STATEMENT;

extern const char* PACKAGE_CONFLICTS_SQL_CREATE_TABLE_STATEMENT;

extern const char* METAPACKAGE_SQL_CREATE_TABLE_STATEMENT;

extern const char* PACKAGE_GROUP_SQL_CREATE_TABLE_STATEMENT;

extern const char* GROUP_SQL_CREATE_TABLE_STATEMENT;

extern const char* REPOSITORY_SQL_CREATE_TABLE_STATEMENT;

// functions

sqlite3 *open_db(char *filename);

int create_initial_tables(sqlite3 *db);

int close_db(sqlite3 *db);

#endif