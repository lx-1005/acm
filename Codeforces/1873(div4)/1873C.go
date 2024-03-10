package main

import (
	"bufio"
	"fmt"
	. "fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	a := make([]string, 10)
	ans := 0
	for i := 0; i < 10; i++ {
		Fscan(in, &a[i])
		for j, v := range a[i] {
			if v == 'X' {
				// 将最中间的四个格子看做一点，计算'X'离中心差几圈
				d := 5
				for x := 4; x <= 5; x++ {
					for y := 4; y <= 5; y++ {
						d = min(d, max(abs(i-x), abs(j-y)))
					}
				}
				ans += 5 - d
			}
		}
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
