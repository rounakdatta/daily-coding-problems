package five

type PairOperator func(interface{}, interface{}) interface{}

type PairFunc func(PairOperator) interface{}

func Cons(a, b interface{}) PairFunc {
	return func(f PairOperator) interface{} {
		return f(a, b)
	}
}

func Car(pair PairFunc) interface{} {
	return pair(func(a, b interface{}) interface{} {
		return a
	})
}

func Cdr(pair PairFunc) interface{} {
	return pair(func(a, b interface{}) interface{} {
		return b
	})
}
