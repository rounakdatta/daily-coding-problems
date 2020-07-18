package two

import (
	"testing"
	"github.com/stretchr/testify/assert"
)

func Test1(t *testing.T) {
	setOfNumbers := []int{1, 2, 3, 4, 5}
	expectedOutput := []int{120, 60, 40, 30, 24}
	actualOutput := Run(setOfNumbers)
	assert.ElementsMatch(t, expectedOutput, actualOutput)
}
