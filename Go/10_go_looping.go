package main

import "fmt"

func main() {
	for index := 0; index < 5; index++ {
		fmt.Println(index)
	}
	index := 3
	for {
		fmt.Println(index)
		index++
		if index > 10 {
			break
		}
	}
}
