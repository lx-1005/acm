package main

import (
	"bufio"
	"fmt"
	. "fmt"
	"os"
	"sort"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, x int
	Fscan(in, &n, &x)
	a := make([]int, n)
	for i := range a {
		Fscan(in, &a[i])
	}

	// 返回[0, n)中首个使得f[i]为真的数
	ans := sort.Search(2e9, func(h int) bool {
		h++
		sum := int64(0)
		for _, v := range a {
			if v < h {
				sum += int64(h - v)
			}
		}
		return sum > int64(x)
	})
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
