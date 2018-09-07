package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
)

func main() {
	resp, _ := http.Get("https://xmlsitemapgenerator.org/help/example-xml-sitemap.xml")
	bytes, _ := ioutil.ReadAll(resp.Body)
	string_body := string(bytes)
	fmt.Println(string_body)
	resp.Body.Close()
}
