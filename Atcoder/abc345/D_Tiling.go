package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"strings"
)

// TODO
func solve(in *bufio.Reader, out *bufio.Writer) {
	n, h, w := 0, 0, 0
	Fscan(in, &n, &h, &w)
	tiles := make([]Pair, n)
	for i := 0; i < n; i++ {
		Fscan(in, &tiles[i].a, &tiles[i].b)
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

type Pair struct{ a, b int }
