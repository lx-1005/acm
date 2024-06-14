package main

import (
	"bufio"
	. "fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	s := ""
	Fscan(in, &s)

	cnt := make(map[rune]int)
	for _, r := range s {
		cnt[r]++
	}

	more := 0 // s自身
	ans := 0
	sum := 0
	for _, c := range cnt {
		if c > 1 {
			more = 1
		}
		ans += c * sum
		sum += c
	}
	ans += more
	Fprintln(out, ans)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	T := 1
	// Fscan(in, &T)
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
