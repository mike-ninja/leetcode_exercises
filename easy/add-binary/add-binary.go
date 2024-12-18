package main

import (
	"fmt"
	"strings"
)

func binToInt(bin string) int {
	res := 0
	for _, c := range bin {
		res = (res * 2) + int(c-'0')
	}
	return res
}

func intToBin(num int) string {
	var builder strings.Builder

	for num > 0 {
		builder.WriteRune(rune((num % 2) + '0'))
		num /= 2
	}

	bin := []rune(builder.String())
	k := len(bin) - 1
	i := 0

	for i < k {
		tmp := bin[i]
		bin[i] = bin[k]
		bin[k] = tmp
		i++
		k--
	}

	return string(bin)
}

func addBinary(a, b string) string {
	if a == "0" && b == "0" {
		return "0"
	}

	aInt := binToInt(a)
	bInt := binToInt(b)
	res := aInt + bInt

	return intToBin(res)
}

func main() {
	res := addBinary("11", "1")
	fmt.Printf("result: [%v]", res)
	res = addBinary("1010", "1011")
	fmt.Printf("result: [%v]", res)
	res = addBinary("0", "0")
	fmt.Printf("result: [%v]", res)

	a := "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101"
	b := "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011"
	res = addBinary(a, b)
	fmt.Printf("result: [%v]", res)
}
