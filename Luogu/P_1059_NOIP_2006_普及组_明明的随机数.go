package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"strings"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	n, x := 0, 0
	Fscan(in, &n)
	a := make([]int, 1001)
	ans := 0
	for i := 0; i < n; i++ {
		Fscan(in, &x)
		if a[x] == 0 {
			ans++
		}
		a[x] = 1
	}
	Fprintln(out, ans)
	for i := range a {
		if a[i] == 1 {
			Fprint(out, i, " ")
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
