/*
 * Author: $%U%$
 * Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
**/
package main

import (
	"bufio"
	. "fmt"
	"os"
)

func cf1873A(in *bufio.Reader, out *bufio.Writer) {

}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	var T int
	Fscan(in, &T)
	for ; T > 0; T-- {
		cf1873A(in, out)
	}
	out.Flush()
}
