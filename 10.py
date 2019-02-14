import time

def waitForSomeTime(ms):
    time.sleep(ms / 1000)

def jobScheduler(fn, interval):
    while True:
        fn()
        waitForSomeTime(interval)
    

def getGoogle():
    import requests
    response = requests.get('https://google.co.in')
    print(response)


myCustomFunction = getGoogle
jobScheduler(myCustomFunction, 300)