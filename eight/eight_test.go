package eight

import (
	"testing"
	"github.com/stretchr/testify/assert"
)

func Test1(t *testing.T) {
	tree := &Node{
		val: 0,
		left: &Node{
			val: 1,
		},
		right: &Node{
			val: 0,
			left: &Node{
				val: 1,
				left: &Node{
					val: 1,
				},
				right: &Node{
					val: 1,
				},
			},
			right: &Node{
				val: 0,
			},
		},
	}

	output := CountUnival(tree)
	assert.Equal(t, output, 5)
}

func Test2(t *testing.T) {
	tree := &Node{
		val: 0,
		left: &Node{
			val: 1,
		},
		right: &Node{
			val: 0,
			left: &Node{
				val: 1,
				left: &Node{
					val: 1,
				},
				right: &Node{
					val: 1,
				},
			},
			right: &Node{
				val: 0,
				left: &Node{
					val: 0,
				},
			},
		},
	}

	output := CountUnival(tree)
	assert.Equal(t, output, 5)
}
