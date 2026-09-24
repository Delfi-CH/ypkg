package main

/*
#cgo LDFLAGS: -L/lib -lypkg
#include "../../lib/include/ypkg.h"
*/
import "C"
import "fmt"

func main() {
	fmt.Println("hello, go");
	C.hello()
}