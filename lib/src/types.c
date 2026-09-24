#include "../include/ypkg.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

struct package {
    char name[128];
    char description[1024];
    MachineArch architecture;
    uint64_t published_date;
    char version[32];
    License license;
    char upstream_url[1024];
    char provides[128][128];
    Package *dependencies[256];
    Package *conflicts[256];
    Repository *repository;
};

const char* PROVIDES_SQL_CREATE_TABLE_STATEMENT = 
"CREATE TABLE IF NOT EXISTS provides ("
"id INTEGER PRIMARY KEY,"
"name TEXT NOT NULL"
")"
;

const char* PACKAGE_PROVIDES_SQL_CREATE_TABLE_STATEMENT = 
"CREATE TABLE IF NOT EXISTS package_provides ("
"package_id INTEGER NOT NULL,"
"provides_id INTEGER NOT NULL,"
"FOREIGN KEY(package_id) REFRENCES package(id),"
"FOREIGN KEY(provides_id) REFRENCES provides(id)"
")"
;

const char* PACKAGE_SQL_CREATE_TABLE_STATEMENT = 
"CREATE TABLE IF NOT EXISTS package ("
"id INTEGER PRIMARY KEY,"
"name TEXT NOT NULL,"
"architecture INTEGER,"
"published_date INTEGER NOT NULL,"
"version TEXT NOT NULL,"
"license INTEGER,"
"upstream_url TEXT,"
"repository_id INT NOT NULL,"
"FOREIGN KEY(repository_id) REFRENCES repository(id)"
")"
;

const char* PACKAGE_DEPENDENCY_SQL_CREATE_TABLE_STATEMENT = 
"CREATE TABLE IF NOT EXISTS package_dependeny ("
"package_id INTEGER NOT NULL,"
"dependency_id INTEGER NOT NULL,"
"PRIMARY KEY (package_id, dependency_id),"
"FOREIGN KEY(package_id) REFRENCES package(id),"
"FOREIGN KEY(dependency_id) REFRENCES package(id)"
")"
;

const char* PACKAGE_CONFLICTS_SQL_CREATE_TABLE_STATEMENT = 
"CREATE TABLE IF NOT EXISTS package_dependeny ("
"package_id INTEGER NOT NULL,"
"conflicts_id INTEGER NOT NULL,"
"PRIMARY KEY (package_id, conflicts_id),"
"FOREIGN KEY(package_id) REFRENCES package(id),"
"FOREIGN KEY(conflicts_id) REFRENCES package(id)"
")"
;

/* 
A package with diffrent providers that the user can choose between.
eg: both linux and linux-lts provide the linux kernel
*/
struct metapackage {
    char name[128];
    char description[1024];
    MachineArch architecture;
    uint64_t published_date;
    char version[32];
    Package *options[256];
};

const char* METAPACKAGE_SQL_CREATE_TABLE_STATEMENT = 
"CREATE TABLE IF NOT EXISTS metapackage"
"id INTEGER PRIMARY KEY,"
"name TEXT NOT NULL,"
"architecture INTEGER,"
"published_date INTEGER NOT NULL,"
"version TEXT NOT NULL,"
;

struct packagegroup {
    char name[128];
    char description[1024];
    MachineArch architecture;
    uint64_t published_date;
    char version[32];
    Package *contents[256];
    Package *conflicts[256];
};

struct repository {
    char name[128];
    char description[1024];
    bool local;
    char url[1024];
    size_t package_count;
    Package packages[];
};
