package main

import (
	"bufio"
	"fmt"
	. "fmt"
	"os"
	"sort"
)

func maximumHappinessSum(happiness []int, k int) int64 {
	ans := int64(0)
	sort.Ints(sort.Reverse(happiness))

}

func solve(in *bufio.Reader, out *bufio.Writer) {

}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	var T int
	fmt.Fscan(in, &T)
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
