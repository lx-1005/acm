package main

import (
	"bufio"
	. "fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	s := ""
	Fscan(in, &s)
	if len(s) >= 2 && s[0] == '<' && s[len(s)-1] == '>' {
		for i := 1; i < len(s)-1; i++ {
			if s[i] != '=' {
				Fprintln(out, "No")
				return
			}
		}
		Fprintln(out, "Yes")
		return
	}
	Fprintln(out, "No")
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
