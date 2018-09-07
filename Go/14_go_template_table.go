package main

import (
	"encoding/xml"
	"fmt"
	"html/template"
	"io/ioutil"
	"net/http"
)

type NewPageMap struct {
	Title string
	News  map[string]NewsMap
}

type Sitemapindex struct {
	Locations []string `xml:"sitemap>loc"`
}

type News struct {
	Titles    []string `xml:"url>news>title"`
	Keywords  []string `xml:"url>news>keywords"`
	Locations []string `xml:"url>loc"`
}

type NewsMap struct {
	Keyword  string
	Location string
}

func indexHandler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprint(w, "<h1> My first page in Go Lang </h1>")
}

func tabularPage(w http.ResponseWriter, r *http.Request) {
	var s Sitemapindex
	var n News
	resp, _ := http.Get("https://www.washingtonpost.com/news-sitemap-index.xml")
	bytes, _ := ioutil.ReadAll(resp.Body)
	xml.Unmarshal(bytes, &s)
	news_map := make(map[string]NewsMap)

	for _, Location := range s.Locations {
		resp, _ := http.Get(Location)
		bytes, _ := ioutil.ReadAll(resp.Body)
		xml.Unmarshal(bytes, &n)

		for idx, _ := range n.Keywords {
			news_map[n.Titles[idx]] = NewsMap{n.Keywords[idx], n.Locations[idx]}
		}
	}

	p := NewPageMap{Title: "Enthiran The Robo 2.0", News: news_map}
	t, _ := template.ParseFiles("newswebpage.html")
	t.Execute(w, p)
}
func main() {
	http.HandleFunc("/", indexHandler)
	http.HandleFunc("/tables", tabularPage)
	http.ListenAndServe(":8000", nil)
}
