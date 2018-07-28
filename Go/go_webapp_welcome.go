package main

import (
	"fmt"
	"net/http"
)

func main() {
	http.HandleFunc("/", handle_func)
	http.HandleFunc("/about", handle_about)
	http.ListenAndServe(":8000", nil)
}
func handle_about(w http.ResponseWriter, r *http.Request)  {
	fmt.Fprint(w, "from the about page")
}
func handle_func(w http.ResponseWriter, r *http.Request)  {
	fmt.Fprint(w, "Yeah, Go is awesome!")
}