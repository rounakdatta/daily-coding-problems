package two

type Node struct {
	val string
	left *Node
	right *Node
}

func (n *Node) Init(value string, leftNode *Node, rightNode *Node) {
	n.val = value
	n.left = leftNode
	n.right = rightNode
}

func (n *Node) SerializeTree() string {
	// preorder - root, left, right
	if n == nil {
	 	return "_$"
	}

	leftTreeSer := n.left.SerializeTree()
	rightTreeSer := n.right.SerializeTree()

	return n.val + "$" + leftTreeSer + rightTreeSer
}

func constructTree(nodeSet []string, leftNodeStartPoint int) (*Node, int) {
	rootNode := new(Node)
	rootNode.val = nodeSet[leftNodeStartPoint]

	if nodeSet[leftNodeStartPoint + 1] == "_" && nodeSet[leftNodeStartPoint + 2] == "_" {
		return rootNode, leftNodeStartPoint + 2
	}

	var rightNodeStartPoint int
	var rightNodeEndPoint int

	if nodeSet[leftNodeStartPoint + 1] != "_" {
		// left child
		var leftNode *Node
		leftNode, rightNodeStartPoint = constructTree(nodeSet, leftNodeStartPoint + 1)
		rootNode.left = leftNode
	} else {
		rightNodeStartPoint = leftNodeStartPoint + 1
	}
	
	if nodeSet[rightNodeStartPoint + 1] != "_" {
		// right child
		var rightNode *Node
		rightNode, rightNodeEndPoint = constructTree(nodeSet, rightNodeStartPoint + 1)
		rootNode.right = rightNode
	} else {
		rightNodeEndPoint = rightNodeStartPoint + 1
	}

	return rootNode, rightNodeEndPoint
}

func DeserializeTree(serializedTree string) *Node {
	l := len(serializedTree)
	i := 0

	var nodeValues []string

	for i < l {
		j := i
		for i < l && serializedTree[i] != '$' {
			i += 1
		}

		nodeValues = append(nodeValues, serializedTree[j:i])

		i += 1
	}

	tree, _ := constructTree(nodeValues, 0)
	return tree
}
