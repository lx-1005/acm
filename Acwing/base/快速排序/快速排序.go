package main

import (
	"bufio"
	. "fmt"
	"io"
	"math/rand"
	"os"
	"strings"
)

func quick_sort(a []int, l, r int) {
	if l >= r {
		return
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
	quick_sort(a, l, j)
	quick_sort(a, j+1, r)
}

func solve(in *bufio.Reader, out *bufio.Writer) {
	n := 0
	Fscan(in, &n)
	a := make([]int, n)
	for i := range a {
		Fscan(in, &a[i])
	}

	quick_sort(a, 0, n-1)
	for _, x := range a {
		Fprint(out, x, " ")
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
