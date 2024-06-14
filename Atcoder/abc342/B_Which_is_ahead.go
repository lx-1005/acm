package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"strings"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, q int
	Fscan(in, &n)
	pos := make(map[int]int, 0)
	for i := 1; i <= n; i++ {
		p := 0
		Fscan(in, &p)
		pos[p] = i
	}

	Fscan(in, &q)
	for i := 1; i <= q; i++ {
		var a, b int
		Fscan(in, &a, &b)
		if pos[a] < pos[b] {
			Fprintln(out, a)
		} else {
			Fprintln(out, b)
		}
	}
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

	leftData, _ := io.ReadAll(in)
	if s := strings.TrimSpace(string(leftData)); s != "" {
		panic("有未读入的数据：\n" + s)
	}
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
