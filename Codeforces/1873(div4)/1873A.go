package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"strings"
)

func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	solve := func(curCase int) (_res bool) {
		var s string
		Fscan(in, &s)
		return s != "cab" && s != "bca"
	}

	cases := 1
	Fscan(in, &cases)
	for curCase := 1; curCase <= cases; curCase++ {
		ans := solve(curCase)
		if ans {
			Fprintln(out, "YES")
		} else {
			Fprintln(out, "NO")
		}
	}

	leftData, _ := io.ReadAll(in)
	if s := strings.TrimSpace(string(leftData)); s != "" {
		panic("有未读入的数据：\n" + s)
	}
}

func main() { run(os.Stdin, os.Stdout) }
