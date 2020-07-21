package eight

type Node struct {
	val int
	left *Node
	right *Node
}

func CountUnival(root *Node) int {
	if root == nil {
		return 0
	}

	univalCount := CountUnival(root.left) + CountUnival(root.right)
	if root.left == nil && root.right == nil {
		return univalCount + 1
	}

	
	if root.left != nil && root.right != nil {
		if root.left.val == root.right.val {
			return univalCount + 1
		}
	}

	return univalCount
}
