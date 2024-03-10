package main

import (
	"bufio"
	"fmt"
	. "fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, k int
	var s string
	Fscan(in, &n, &k, &s)

	ans := 0
	for i := 0; i < n; i++ {
		if s[i] == 'B' {
			ans++
			i += k - 1
		}
	}
	Fprintln(out, ans)
	return
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	var T int
	fmt.Fscan(in, &T)
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
