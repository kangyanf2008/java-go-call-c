package main

/*
#cgo CFLAGS: -I.
#cgo LDFLAGS: -L. -ltest
#include "test.h"
*/
import "C"
import (
	"fmt"
	"time"
	"unsafe"
)

func main() {
	test()
	//test2()
}

func test() {
	var va1 = "1234"
	var va2 = "456789"
	temV1 :=C.CString(va1)
	temV2 := C.CString(va2)
	arrLen := len(va2) + len(va1)
	result := make([]byte, arrLen + 1)
	begin := time.Now().UnixNano() / 1000000
	for i := 0; i < 100000000; i++ {
		result = result[:0]
		C.CharJoin((*C.char)(unsafe.Pointer(&result)), temV1, temV2)
	}
	fmt.Println(time.Now().UnixNano()/1000000 - begin)
	fmt.Println(C.GoString((*C.char)(unsafe.Pointer(&result))))
}

func JoinString(var1, var2 string) string {
	return var1 + var2
}
func test2() {
	begin := time.Now().UnixNano() / 1000000
	var result string
	for i := 0; i < 1000000000; i++ {
		//result = JoinString("abcdef", "ghxi")
		JoinString("abcdef", "ghxi")
	}
	fmt.Println(time.Now().UnixNano()/1000000 - begin)
	fmt.Println(result)
}

