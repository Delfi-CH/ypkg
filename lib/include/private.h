#ifndef YPKG_PRIVATE_H

#define YPKG_PRIVATE_H

#include <sqlite3.h>

// consts

extern const char *SQL_CREATE_REPOSITORY;
extern const char *SQL_CREATE_PACKAGE_IDENTIFIER;
extern const char *SQL_CREATE_PACKAGE_IDENTIFIER_REPOSITORY;
extern const char *SQL_CREATE_PROVIDES;
extern const char *SQL_CREATE_PACKAGE;
extern const char *SQL_CREATE_PACKAGE_PROVIDES;
extern const char *SQL_CREATE_PACKAGE_DEPENDS;
extern const char *SQL_CREATE_PACKAGE_CONFLICTS;
extern const char *SQL_CREATE_METAPACKAGE;
extern const char *SQL_CREATE_PACKAGE_METAPACKAGE;
extern const char *SQL_CREATE_GROUP;
extern const char *SQL_CREATE_PACKAGE_GROUP;

// functions

sqlite3 *open_db(char *filename);

int create_initial_tables(sqlite3 *db);

int close_db(sqlite3 *db);

#endif