package ten

import (
	"fmt"
	"testing"
)

func printHelloWorld() {
	fmt.Println("Hello World")
}

func printFooBar() {
	fmt.Println("Foo Bar")
}

func Test1(t *testing.T) {
	go Schedule(printHelloWorld, 10000)
	go Schedule(printFooBar, 5000)
	go Schedule(printHelloWorld, 15000)
	go Schedule(printFooBar, 1000)
}
