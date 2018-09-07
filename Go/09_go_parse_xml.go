package main

import (
	"encoding/xml"
	"fmt"
	"io/ioutil"
	"net/http"
)

type SitemapIndex struct {
	Location []Location `xml:"url"`
}

type Location struct {
	Loc string `xml:"loc"`
}

func (l Location) String() string {
	return fmt.Sprintf(l.Loc)
}

func main() {
	resp, _ := http.Get("https://xmlsitemapgenerator.org/help/example-xml-sitemap.xml")
	bytes, _ := ioutil.ReadAll(resp.Body)
	resp.Body.Close()

	var s SitemapIndex
	xml.Unmarshal(bytes, &s)
	//fmt.Println(s.Location)
	for _, Location := range s.Location {
		fmt.Printf("%s\n", Location)
	}
}
