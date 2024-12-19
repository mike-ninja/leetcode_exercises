package main

import (
	"fmt"
	"strings"
)

func addBinary(a, b string) string {
	if a == "0" && b == "0" {
		return "0"
	}

	carry := 0
	i := len(a) - 1
	j := len(b) - 1

	var builder strings.Builder

	for i >= 0 || j >= 0 {
		var n int
		var m int
		if i >= 0 {
			n = int(a[i] - '0')
		} else {
			n = 0
		}
		if j >= 0 {
			m = int(b[j] - '0')
		} else {
			m = 0
		}

		char := ((n + m + carry) % 2) + '0'
		builder.WriteRune(rune(char))
		carry = (n + m + carry) / 2
		i--
		j--
	}
	if carry > 0 {
		builder.WriteRune(rune(carry + '0'))
	}

	bin := []rune(builder.String())
	i = 0
	j = len(bin) - 1

	for i < j {
		tmp := bin[i]
		bin[i] = bin[j]
		bin[j] = tmp
		i++
		j--
	}

	return string(bin)
}

func main() {
	res := addBinary("11", "1")
	fmt.Printf("result: [%v]\n", res)
	res = addBinary("1010", "1011")
	fmt.Printf("result: [%v]\n", res)
	res = addBinary("0", "0")
	fmt.Printf("result: [%v]\n", res)
	a := "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101"
	b := "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011"
	res = addBinary(a, b)
	if res == "110111101100010011000101110110100000011101000101011001000011011000001100011110011010010011000000000" {
		fmt.Printf("PASS: [%v]\n", res)
	} else {
		fmt.Printf("FAIL: [%v]\n", res)
	}
}
