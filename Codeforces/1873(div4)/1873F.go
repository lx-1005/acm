package main

import (
	"bufio"
	"fmt"
	. "fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	n, k := 0, 0
	Fscan(in, &n, &k)
	a, h := make([]int, n), make([]int, n)
	for i := range a {
		Fscan(in, &a[i])
	}
	for i := range h {
		Fscan(in, &h[i])
	}

	ans := 0
	f := func(a []int) {
		s := 0
		l := 0
		for i := range a {
			s += a[i]
			for l <= i && s > k {
				s -= a[l]
				l++
			}
			ans = max(ans, i-l+1)
		}
	}
	for i := 0; i < n; {
		j := i
		for i++; i < n && h[i-1]%h[i] == 0; i++ {
		}
		f(a[j:i])
	}
	Fprintln(out, ans)
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
