package main

import (
	"delfi.dev/libypkg"
	"fmt"
)

func main() {
	env, err := libypkg.Ypkg_Init()
	if (err != nil) {
		fmt.Println("error: " + err.Error())
	}
	fmt.Println(env)
}