package main

import (
	"fmt"
	"html/template"
	"net/http"
)

type NewPage struct {
	Title string
	News  string
}

func indexHandler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprint(w, "<h1> My first page in Go Lang </h1>")
}

func aggPage(w http.ResponseWriter, r *http.Request) {
	p := NewPage{Title: "Enthiran The Robo 2.0", News: "Releasing in December"}
	t, _ := template.ParseFiles("enthiran2.html")
	t.Execute(w, p)
}
func main() {
	http.HandleFunc("/", indexHandler)
	http.HandleFunc("/agg", aggPage)
	http.ListenAndServe(":8000", nil)
}
