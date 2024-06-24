package main

import (
	"bufio"
	. "fmt"
	"os"
	"strings"
)

/*

操作1：B可以不断吃掉左侧的A，并排出C
操作2：B可以不断吃掉右侧的A，并排出C

*/

func solve(in *bufio.Reader, out *bufio.Writer) {
	s := ""
	Fscan(in, &s)

	ca := strings.Count(s, "A")
	// 没有A
	if ca == 0 {
		Fprintln(out, 0)
		return
	}
	// B一定可以向右吃掉所有A
	if s[0] == 'B' || s[len(s)-1] == 'B' || strings.Contains(s, "BB") {
		Fprintln(out, ca)
		return
	}

	// 只能被迫放弃最短的一组A
	mn := int(3e5)
	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
			cnt := 0
			for ; i < len(s) && s[i] == 'A'; i++ {
				cnt++
			}
			mn = min(mn, cnt)
			i--
		}
	}
	Fprintln(out, ca-mn)
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
