package four

func turnIntegerNegative(num *int) {
	if *num > 0 {
		*num = -*num
	}
}

func Run(nums []int) int {
	l := len(nums)

	// set indexes negative for every value found -> the lone positive wolf gives the answer
	i := 0
	altered := false

	for i < l {
		el := nums[i]
		if el > 0 && el <= l {
			turnIntegerNegative(&nums[el - 1])
			altered = true
		}

		i += 1
	}

	i = 0
	for i < l {
		if nums[i] >= 0 {
			return i + 1
		}

		i += 1
	}

	if !altered {
		return 1
	}
	return l + 1
}
