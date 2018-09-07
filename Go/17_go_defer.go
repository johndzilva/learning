package main

import (
	"fmt"
)

func main() {
	defer fmt.Println("Done!")
	defer fmt.Println("Are we done?")
	fmt.Println("Cornerstone!")
}
