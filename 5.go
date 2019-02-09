package main

import "fmt"

type pairOfNumbersReturningSomething func(int, int) int

type decisionFunctionPlaceholder func(pairOfNumbersReturningSomething) int

func cons(a, b int) decisionFunctionPlaceholder {
	thisReturnsThePair := func(somePair pairOfNumbersReturningSomething) int {
		return somePair(a, b)
	}

	return thisReturnsThePair
}

func car(fChoice decisionFunctionPlaceholder) int {
	thisReturnsTheFirstChoice := func(a, b int) int {
		return a
	}

	return fChoice(thisReturnsTheFirstChoice)
}

func cdr(lChoice decisionFunctionPlaceholder) int {
	thisReturnsTheSecondChoice := func(a, b int) int {
		return b
	}

	return lChoice(thisReturnsTheSecondChoice)
}

func main() {

	carVar := car(cons(1000, 9999))
	cdrVar := cdr(cons(1000, 9999))

	fmt.Println(carVar)
	fmt.Println(cdrVar)

}
