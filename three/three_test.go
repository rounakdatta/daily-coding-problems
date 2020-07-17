package two

import (
	"testing"
	"github.com/stretchr/testify/assert"
)

func Test1(t *testing.T) {
	tree := &Node{
			val: "root",
			left: &Node{
				val: "left",
				left: &Node{
					val: "left.left",
				},
			},
		right: &Node{
			val: "right",
		},
	}

	foo := tree.SerializeTree()
	bar := DeserializeTree(foo)
	
	assert.Equal(t, bar.left.left.val, "left.left")
}
