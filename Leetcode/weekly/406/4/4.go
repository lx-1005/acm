package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"strings"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	a := map[string]any{
		"user_logo1": "",
		"user_logo2": "123",
	}
	if a["user_logo1"] == nil {
		Println("1")
	} else if a["user_logo2"] == nil {
		Println("2")
	} else {
		Println("3")
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
