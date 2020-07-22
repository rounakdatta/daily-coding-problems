package nine

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func ComputeMaxNonAdjacentSum(nums []int) int {
	l := len(nums)

	memoArray := make([]int, l)
	memoArray[0] = nums[0]
	memoArray[1] = max(nums[0], nums[1])

	i := 2
	for i < l {
		memoArray[i] = max(
			memoArray[i - 2] + nums[i],
			memoArray[i - 1],
		)

		i += 1
	}

	return memoArray[l - 1]
}
