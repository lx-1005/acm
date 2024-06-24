package main

import (
	"bufio"
	. "fmt"
	"os"
	"sort"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	n, x := 0, 0
	Fscan(in, &n, &x)
	a := make([]int, n)
	for i := range a {
		Fscan(in, &a[i])
	}
	Fprintln(out, sort.Search(int(2e9), func(h int) bool {
		s := int64(0)
		for i := range a {
			s += int64(max(0, h-a[i]))
		}
		return s > int64(x)
	})-1)
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
