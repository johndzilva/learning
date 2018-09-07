package main

import (
	"fmt"
	"net/http"
)

func httpHandle(w http.ResponseWriter, r *http.Request) {
	fmt.Fprint(w, "<h1>Hey There!</h1>")
	fmt.Fprint(w, "<p>This is my first para in go</p>")

	fmt.Fprint(w, `<h1>Hey There!</h1>
<p>This is my first para in go</p>`)
}

func main() {
	http.HandleFunc("/", httpHandle)
	http.ListenAndServe(":8000", nil)
}
