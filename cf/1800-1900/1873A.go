package main

import (
	"bufio"
	. "fmt"
	"os"
)

func cf1873A(in *bufio.Reader, out *bufio.Writer) {
	s, t := "", "abc"

	Fscan(in, &s)

	cnt := 0
	for i := range s {
		if t[i] != s[i] {
			cnt++
		}
	}
	if cnt > 2 {
		Fprintln(out, "NO")
	} else {
		Fprintln(out, "YES")
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	var T int
	Fscan(in, &T)
	for ; T > 0; T-- {
		cf1873A(in, out)
	}
	out.Flush()
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
