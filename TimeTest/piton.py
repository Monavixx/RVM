import time
start_time = time.time()
arr = []
for i in range(1, 100000):
	arr.append(i)
print()
print((time.time() - start_time) * 1000)