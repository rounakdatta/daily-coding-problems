package five

import (
	"testing"
	"github.com/stretchr/testify/assert"
)

func TestCar(t *testing.T) {
	output := Car(Cons(1, 10))
	assert.Equal(t, 1, output)
}

func TestCdr(t *testing.T) {
	output := Cdr(Cons(2, 9))
	assert.Equal(t, 9, output)
}
