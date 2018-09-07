package main

import (
	"fmt"
	"time"
)

func run(s string) {
	for i := 0; i < 5; i++ {
		fmt.Println(s)
		time.Sleep(time.Millisecond * 100)
	}
}

func main() {
	go run("Hello")
	go run("DJ!")
	time.Sleep(time.Second)
}
