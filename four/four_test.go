package four

import (
	"testing"
	"github.com/stretchr/testify/assert"
)

func Test1_Simple(t *testing.T) {
	setOfNumbers := []int{1, 2, 4, 5, 6}
	missingNum := Run(setOfNumbers)
	assert.Equal(t, 3, missingNum)
}

func Test2_MultiMissing(t *testing.T) {
	setOfNumbers := []int{7, -1, 0, 4, -5, -6, 4, 6, 2, 1}
	missingNum := Run(setOfNumbers)
	assert.Equal(t, 3, missingNum)
}

func Test3_CorrespondingNegativePresent(t *testing.T) {
	setOfNumbers := []int{7, -1, 0, 4, -3, -6, 4, 6, 2, 1}
	missingNum := Run(setOfNumbers)
	assert.Equal(t, 3, missingNum)
}

func Test4_AllPresent(t *testing.T) {
	setOfNumbers := []int{1, 2, 2, 3, 4, 4, 4}
	missingNum := Run(setOfNumbers)
	assert.Equal(t, 5, missingNum)
}

func Test5_AllNegative(t *testing.T) {
	setOfNumbers := []int{-3, -2, -1}
	missingNum := Run(setOfNumbers)
	assert.Equal(t, 1, missingNum)
}
