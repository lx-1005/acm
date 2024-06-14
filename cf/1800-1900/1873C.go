package main

import (
	"bufio"
	. "fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	a := make([]string, 10)
	ans := 0
	for i := range a {
		Fscan(in, &a[i])
		for j, c := range a[i] {
			if c == 'X' {
				d := int(1e9)
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
