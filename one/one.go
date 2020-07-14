package one

import (
	"errors"
)

func Run(numbers []int, k int) (bool, error) {
	presentMapper := make(map[int]bool)

	for _, i := range numbers {
		presentMapper[i] = true
		isPresent, _ := presentMapper[k - i]
		if isPresent {
			return true, nil
		}
	}

	return false, errors.New("error")
}
