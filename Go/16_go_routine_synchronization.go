package main

import (
	"fmt"
	"sync"
	"time"
)

var wg sync.WaitGroup

func command(s string) {
	//defer wg.Done()
	for i := 0; i < 3; i++ {
		fmt.Println(s)
		time.Sleep(time.Millisecond * 100)
	}
	wg.Done()
}

func main() {
	wg.Add(1)
	go command("Hey")
	wg.Add(1)
	go command("DJ!")
	//wg.Wait()
	wg.Add(1)
	go command("What is up!")
	wg.Wait()
}
