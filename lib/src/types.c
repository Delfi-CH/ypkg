#include "../include/ypkg.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct package
{
    char name[128];
    char description[1024];
    uint64_t build_date;
    uint64_t release_date;
    char version[32];
    License license;
    char upstream_url[1024];
    Package *dependencies[256];
    Package *conflicts[256];
};