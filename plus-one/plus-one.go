package main

import "fmt"

// func reverse(digits *[]int) {
// 	i := 0
// 	k := len(*digits) - 1
//
// 	for i < k {
// 		temp := (*digits)[i]
// 		(*digits)[i] = (*digits)[k]
// 		(*digits)[k] = temp
// 		i++
// 		k--
// 	}
// }
//
// func plusOne(digits []int) []int {
// 	var num int64 = 0
// 	res := []int{}
//
// 	for _, n := range digits {
// 		num = (num * 10) + int64(n)
// 	}
// 	num++
// 	for num > 0 {
// 		res = append(res, int(num)%10)
// 		num /= 10
// 	}
// 	reverse(&res)
//
// 	return res
// }

func plusOne(digits []int) []int {
	carry := 0
	k := len(digits) - 1

	digits[k]++
	for 0 <= k {
		digits[k] += carry
		val := digits[k]
		rem := val / 10
		if rem == 1 {
			carry = 1
			digits[k] = 0
		} else {
			carry = 0
		}

		k--
	}

	if carry == 1 {
		digits = append([]int{1}, digits...)
	}

	return digits
}

func main() {
	nums := []int{7, 2, 8, 5, 0, 9, 1, 2, 9, 5, 3, 6, 6, 7, 3, 2, 8, 4, 3, 7, 9, 5, 7, 7, 4, 7, 4, 9, 4, 7, 0, 1, 1, 1, 7, 4, 0, 0, 6}
	// nums := []int{9}
	res := plusOne(nums)

	fmt.Println(res)
}
