package main

import (
	"bufio"
	"fmt"
	. "fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	Fscan(in, &n)
	a := make([]int, n)
	for i := range a {
		Fscan(in, &a[i])
	}

	ans := 0
	for i := range a { // 枚举+1的那个数
		mul := 1
		for j, v := range a {
			if j != i {
				mul *= v
			} else {
				mul *= v + 1
			}
		}
		ans = max(ans, mul)
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
