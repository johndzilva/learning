package main

import (
	"fmt"
	"math"
	"math/rand"
)

func foo () {
	fmt.Println("Square root of 121 is",math.Sqrt(121))
}

func random() {
	fmt.Println("Random number in range 0-100",rand.Intn(100))
}

func main() {
	foo()
	random()
}