package nine

import (
	"testing"
	"github.com/stretchr/testify/assert"
)

func Test1(t *testing.T) {
	testNums := []int{2, 4, 6, 2, 5}
	output := ComputeMaxNonAdjacentSum(testNums)

	assert.Equal(t, output, 13)
}
