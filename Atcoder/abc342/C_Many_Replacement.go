package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"strings"
)

func abc342C(in *bufio.Reader, out *bufio.Writer) {
	var (
		n, q int
		S    string
		c, d string
	)
	Fscan(in, &n, &S, &q)

	change := make([]byte, 26)
	for i := range change {
		change[i] = byte('a' + i)
	}
	for i := 1; i <= q; i++ {
		Fscan(in, &c, &d)

		for j := range change {
			if change[j] == c[0] {
				change[j] = d[0]
			}
		}
	}

	for _, c := range S {
		Fprintf(out, "%c", change[c-'a'])
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	T := 1
	//Fscan(in, &T)
	for ; T > 0; T-- {
		abc342C(in, out)
	}
	out.Flush()

	leftData, _ := io.ReadAll(in)
	if s := strings.TrimSpace(string(leftData)); s != "" {
		panic("有未读入的数据：\n" + s)
	}
}

func max(a, b int) int {
	if b > a {
		return b
	}
	return a
}
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
