package main

import (
	"bufio"
	. "fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	n, k := 0, 0
	Fscan(in, &n, &k)
	a := make([]int, n)
	for i := range a {
		Fscan(in, &a[i])
	}
	h := make([]int, n)
	for i := range h {
		Fscan(in, &h[i])
	}

	f := func(a []int) (mx int) {
		l, s := 0, 0
		for i := range a {
			s += a[i]
			for s > k {
				s -= a[l]
				l++
			}
			mx = max(mx, i-l+1)
		}
		return
	}

	ans := 0
	for i := 0; i < n-1; i++ {
		if h[i]%h[i+1] == 0 {
			j := i
			for i++; i < n && h[i-1]%h[i] == 0; i++ {
			}
			// 找[j,i)的子数组和<=k的最长子数组
			ans = max(ans, f(a[j:i]))
			i--
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
