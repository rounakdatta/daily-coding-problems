class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def constructInorderSerialBuffer(relaxed, myBuffer):
    if relaxed is None:
        myBuffer = myBuffer + "," + "null"
        return myBuffer

    myBuffer = constructInorderSerialBuffer(relaxed.left, myBuffer)
    myBuffer = myBuffer + "," + relaxed.val
    myBuffer = constructInorderSerialBuffer(relaxed.right, myBuffer)
    return myBuffer

def constructPreorderSerialBuffer(relaxed, myBuffer):
    if relaxed is None:
        myBuffer = myBuffer + "," + "null"
        return myBuffer

    myBuffer = myBuffer + "," + relaxed.val
    myBuffer = constructPreorderSerialBuffer(relaxed.left, myBuffer)
    myBuffer = constructPreorderSerialBuffer(relaxed.right, myBuffer)
    return myBuffer

def serialize(relaxed): # relaxed is a Node
    return constructPreorderSerialBuffer(relaxed, "") + "+" + constructInorderSerialBuffer(relaxed, "")

def treeBuilder(ioBuffer, proBuffer, inS, inE, preS, preE):
    # handle the empty array case here
    if inS > inE or preS > preE or inS < 0 or inE < 0 or preS < 0 or preE < 0:
        return None

    rootData = proBuffer[preS]
    rootIndex = ioBuffer.index(rootData)

    lInS = inS
    lInE = rootIndex - 1
    lPreS = preS + 1
    lPreE = lInE - lInS + lPreS
    rInS = rootIndex + 1
    rInE = inE
    rPreS = lPreE + 1 # dependent
    rPreE = preE

    return Node(rootData, treeBuilder(ioBuffer, proBuffer, lInS, lInE, lPreS, lPreE), treeBuilder(ioBuffer, proBuffer, rInS, rInE, rPreS, rPreE))

def deserialize(compact): # compact is a string
    proBuffer = compact.split("+")[0].split(",")[1: ]
    ioBuffer = compact.split("+")[1].split(",")[1: ]

    treeBuilder(ioBuffer, proBuffer, 0, len(ioBuffer) - 1, 0, len(proBuffer) - 1)


# the test case
node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'