#ifndef YPKG_H

#define YPKG_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <sqlite3.h>

// Consts

extern const char *YPKG_CONFIG_PATH;
extern const char *YPKG_LOCAL_DB;

// Enums

typedef enum license {
    UNKNOWN = 0,

    GPL_V2_ONLY,
    GPL_V2_OR_LATER,
    GPL_V3_ONLY,
    GPL_V3_OR_LATER,

    LGPL_V2_ONLY,
    LGPL_V2_OR_LATER,
    LGPL_V2_1_ONLY,
    LGPL_V2_1_OR_LATER,
    LGPL_V3_ONLY,
    LGPL_V3_OR_LATER,

    AGPL_V3_ONLY,
    AGPL_V3_OR_LATER,

    BSD_0_CLAUSE,
    BSD_2_CLAUSE,
    BSD_3_CLAUSE,
    BSD_4_CLAUSE,

    MIT,

    APACHE_1_1,
    APACHE_2_0,

    MPL_1_0,
    MPL_1_1,
    MPL_2_0,

    EPL_1_0,
    EPL_2_0,

    ISC,
    ZLIB,
    POSTGRESQL,
    PYTHON_2_0,
    CURL,
    BOOST_1_0,
    UNLICENSE,

    ARTISTIC_1_0,
    ARTISTIC_2_0,

    CDDL_1_0,
    CDDL_1_1,
    EUPL_1_1,
    EUPL_1_2,

    MS_PL,
    MS_RL,
    AFL_3_0,
    CPL_1_0,
    OSL_3_0,

    CC0_1_0,
    CC_BY_4_0,
    CC_BY_SA_4_0,
    CC_BY_NC_4_0,
    CC_BY_NC_SA_4_0,
    CC_BY_ND_4_0,
    CC_BY_NC_ND_4_0,

    PROPRIETARY,
    COMMERCIAL,
    NO_LICENSE,
    CUSTOM
} YPKG_License;

typedef enum arch {
    ANY = 0,
    X86,
    X86_64,
    ARM,
    ARM32,
    ARM64,
    RISCV,
    RISCV32,
    RISCV64,
    RISCV128,
    PPC,
    PPC32,
    PPC32_LE,
    PPC64,
    PPC64_LE,
    POWERISA,
    IBM_Z,
    M68K,   
} YPKG_MachineArch;

// Structs

typedef struct package YPKG_Package;

typedef struct metapackage YPKG_MetaPackage;

typedef struct packagegroup YPKG_PackageGroup;

typedef struct repository YPKG_Repository;

typedef struct env_vars YPKG_ENV_VARS;

struct package {
    char name[128];
    char description[1024];
    YPKG_MachineArch architecture;
    uint64_t published_date;
    char version[32];
    YPKG_License license;
    char upstream_url[1024];
    char provides[128][128];
    YPKG_Package *dependencies[256];
    YPKG_Package *conflicts[256];
    YPKG_Repository *repository;
};

/* 
A package with diffrent providers that the user can choose between.
eg: both linux and linux-lts provide the linux kernel
*/
struct metapackage {
    char name[128];
    char description[1024];
    YPKG_MachineArch architecture;
    uint64_t published_date;
    char version[32];
    YPKG_Package *options[256];
    YPKG_Repository *repository;
};

struct packagegroup {
    char name[128];
    char description[1024];
    YPKG_MachineArch architecture;
    uint64_t published_date;
    char version[32];
    YPKG_Package *contents[256];
    YPKG_Repository *repository;
};

struct repository {
    char name[128];
    char description[1024];
    bool local;
    char url[1024];
    size_t package_count;
    YPKG_Package packages[];
};

struct env_vars {
    char *config_path;
    char *local_db_path;
    sqlite3 *local_db;
};

// Functions

int ypkg_init(YPKG_ENV_VARS *env_vars, char **errmsg);

#endif