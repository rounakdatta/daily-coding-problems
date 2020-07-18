package two

func Run(numbers []int) []int {
	l := len(numbers)
	product := make([]int, l)

	productGuy := 1
	i := 1

	product[0] = 1
	for i < l {
		productGuy *= numbers[i - 1]
		product[i] = productGuy

		i += 1
	}
	
	productGuy = 1
	i = l - 2

	product[l - 1] *= 1
	for i >= 0 {
		productGuy *= numbers[i + 1]
		product[i] *= productGuy

		i -= 1
	}

	return product
}
