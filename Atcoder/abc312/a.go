package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"strings"
)

func abc312A(in *bufio.Reader, out *bufio.Writer) {
	var s string
	Fscan(in, s)
	if s == "ACE" || s == "BDF" || s == "CEG" || s == "DFA" || s == "EGB" || s == "FAC" || s == "GBD" {
		Fprintln(out, "Yes")
	} else {
		Fprintln(out, "No")
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	T := 1
	// Fscan(in, &T)
	for ; T > 0; T-- {
		abc312A(in, out)
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
