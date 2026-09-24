package libypkg

/*
#cgo LDFLAGS: -L/lib -lypkg -lsqlite3
#include <ypkg.h>
#include <sqlite3.h>
*/
import "C"
import "errors"

type YPKG_ENV_VARS struct {
	config_path string;
	local_db_path string;
	local_db *C.sqlite3;
}

func Ypkg_Init() (YPKG_ENV_VARS, error) {
	env := YPKG_ENV_VARS{}
	cerrmsg := C.CString("");
	cenv := C.YPKG_ENV_VARS{}
	rc := C.ypkg_init(&cenv, &cerrmsg)
	errmsg := C.GoString(cerrmsg)

	if (rc != 0) {
		return env, errors.New(errmsg)
	}
	env.config_path = C.GoString(cenv.config_path)
	env.local_db_path = C.GoString(cenv.local_db_path)
	env.local_db = cenv.local_db

	return env, nil
}