package main

import (
	"bufio"
	. "fmt"
	"io"
	"math/rand"
	"os"
	"strings"
)

func quick_select(a []int, l, r, k int) int {
	if l == r {
		return a[l]
	}

	i, j := l-1, r+1
	base := a[rand.Int()%(r-l+1)+l]
	for i < j {
		for i++; a[i] < base; i++ {
		}
		for j--; a[j] > base; j-- {
		}
		if i < j {
			a[i], a[j] = a[j], a[i]
		}
	}
	sl := j - l + 1
	if sl >= k {
		return quick_select(a, l, j, k)
	} else {
		return quick_select(a, j+1, r, k-sl)
	}
}

func solve(in *bufio.Reader, out *bufio.Writer) {
	n, k := 0, 0
	Fscan(in, &n, &k)
	a := make([]int, n)
	for i := range a {
		Fscan(in, &a[i])
	}

	Fprintln(out, quick_select(a, 0, n-1, k))
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
