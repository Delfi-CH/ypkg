#ifndef YPKG_H

#define YPKG_H

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
} License;

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
} MachineArch;

// Structs

typedef struct package Package;

typedef struct metapackage MetaPackage;

typedef struct packagegroup PackageGroup;

typedef struct repository Repository;

// Functions

void hello();

#endif