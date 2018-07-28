package main

import ("fmt")

func add(x, y float32) float32 {
	return x+y
}

func stradd(a string, b string) (string, string) {
	return a, b
}

func main() {
	var num1, num2 float32 = 1.2, 3.4
	var str1, str2 string = "Hey", "machi"

	fmt.Println("addition func out ",add(num1, num2))
	fmt.Println(stradd(str1, str2))
}

