package main

import (
	"bufio"
	. "fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	n, k := 0, 0
	Fscan(in, &n, &k)
	s := ""
	Fscan(in, &s)

	ans := 0
	for i := 0; i < n; {
		if s[i] == 'B' {
			ans++
			i += k
		} else {
			i++
		}
	}
	Fprintln(out, ans)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	var T int
	Fscan(in, &T)
	for ; T > 0; T-- {
		solve(in, out)
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
