package one

import (
	"testing"
)

func Test1(t *testing.T) {
	numbers := []int{1, 2, 3, 4, 5}
	k := 5

	result, err := Run(numbers, k)
	if err != nil {
		t.Errorf("Got %T, expected %T", result, true)
	}
}
