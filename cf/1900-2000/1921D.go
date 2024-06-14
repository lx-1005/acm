package main

import (
	"bufio"
	"fmt"
	. "fmt"
	"os"
	"sort"
)

func cf1921D(in *bufio.Reader, out *bufio.Writer) {
	n, m := 0, 0
	Fscan(in, &n, &m)
	a := make([]int, n)
	for i := range a {
		Fscan(in, &a[i])
	}
	c := make([]int, m)
	for i := range c {
		Fscan(in, &c[i])
	}
	sort.Ints(a)
	sort.Slice(c, func(c1, c2 int) bool {
		return c[c1] < c[c2]
	})

	ans := int64(0)
	for i, j:=0,0; i<n && j<m; i++, j++ {
		ans += abs(a[i] - c[i])
	}
	FPrintln(out, ans)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	var T int
	fmt.Fscan(in, &T)
	for ; T > 0; T-- {
		cf1921D(in, out)
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
