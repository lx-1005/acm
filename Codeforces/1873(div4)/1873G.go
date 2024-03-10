package main

import (
	"bufio"
	"fmt"
	. "fmt"
	"os"
	"strings"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	s := ""
	Fscan(in, &s)

	n := len(s)
	ca := strings.Count(s, "A")
	mn := int(1e9)
	if ca == n {
		Fprintln(out, 0)
		return
	}
	if s[0] == 'B' || s[n-1] == 'B' || strings.Contains(s, "BB") {
		Fprintln(out, ca)
		return
	}

	for i := 0; i < n-1; i++ {
		if s[i] == 'B' && s[i+1] == 'A' {
			j := i + 1
			for i++; i < n && s[i] == 'A'; i++ {
			}
			mn = min(mn, i-j)
			i--
		}
	}
	Fprintln(out, ca-mn)
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
