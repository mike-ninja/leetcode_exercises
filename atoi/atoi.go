package main

import (
	"fmt"
	"math"
	"strings"
)

func myAtoi(s string) int {
	i := 0
	res := 0
	sign := 1
	trimmedStr := strings.TrimSpace(s)
	strlen := len(trimmedStr)

	for i < strlen {
		if trimmedStr[i] >= '0' && trimmedStr[i] <= '9' {
			res = (res * 10) + int(trimmedStr[i]-'0')

			if res*sign < math.MinInt32 {
				return math.MinInt32
			} else if res*sign > math.MaxInt32 {
				return math.MaxInt32
			}

		} else if trimmedStr[i] == '-' || trimmedStr[i] == '+' {
			if i == 0 {
				if trimmedStr[i] == '-' {
					sign = -1
				}
			} else {
				break
			}
		} else {
			break
		}

		i++
	}

	return res * sign
}

func main() {
	// digit := myAtoi("              125334")
	// fmt.Println(digit)
	// digit = myAtoi("42")
	// fmt.Println(digit)
	// digit = myAtoi("-042")
	// fmt.Println(digit)
	// digit = myAtoi("1337c0d3")
	// fmt.Println(digit)
	digit := myAtoi("-2147483648")
	fmt.Println(digit)
	digit = myAtoi("-91283472332")
	fmt.Println(digit)
}
