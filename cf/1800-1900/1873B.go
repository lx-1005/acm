package main

import (
	"bufio"
	. "fmt"
	"os"
	"sort"
)

func cf1873B(in *bufio.Reader, out *bufio.Writer) {
	n := 0
	Fscan(in, &n)
	a := make([]int, n)
	for i := range a {
		Fscan(in, &a[i])
	}

	sort.Ints(a)
	a[0] += 1
	for i := 1; i < n; i++ {
		a[0] *= a[i]
	}
	Fprintln(out, a[0])
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	var T int
	Fscan(in, &T)
	for ; T > 0; T-- {
		cf1873B(in, out)
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
