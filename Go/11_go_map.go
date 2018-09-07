package main

import (
	"fmt"
)

func main() {
	hobbies := make(map[string]string)
	hobbies["John"] = "music"
	hobbies["DJ"] = "programming"
	hobbies["franklin"] = "sport"

	dj_hobbies := hobbies["DJ"]
	delete(hobbies, "John")
	fmt.Println(hobbies)
	fmt.Println(dj_hobbies)
	for k, v := range hobbies {
		fmt.Println(k, ":", v)
	}
}
