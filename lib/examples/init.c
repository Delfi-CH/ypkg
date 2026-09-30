#include <ypkg.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    YPKG_ENV_VARS env_vars = {0};
    char *errmsg;
    int rc = ypkg_init(&env_vars, &errmsg);
    if (rc) {
        fprintf(stderr, "%s", errmsg);
        free(errmsg);
        return 1;
    } else {
        printf("all ok");
        free(errmsg);
    }
    return 0;
}