test:
	go test ./...

test-verbose:
	go test -v ./...

clean:
	go clean -testcache
