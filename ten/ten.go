package ten

import (
	"time"
)

type passableFunc func()

func Schedule(f passableFunc, n int) {
	time.Sleep(time.Duration(n) * time.Millisecond)
	go f()
}
