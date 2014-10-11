class LRUCache:
	def __init__(self, capacity):
		self.capacity = capacity
		self.lrucache = {}

	def get(self, key):
		if self.lrucache.has_key(key):
			self.lrucache[key][1] += 1
			return self.lrucache[key][0]
		else:
			return -1

	def set(self, key, value):
		if len(self.lrucache) >= self.capacity:
			min = 1000000
			for item in self.lrucache.items():
				if item[1][1] < min:
					min = item[1][1]
					k = item[0]
			del self.lrucache[k]
		self.lrucache[key] = [value, 1]


def testlru(lc):
	for i in range(2018):
		lc.set(i, i)
	for j in range(10000):
		lc.set(j, j)
		print lc.get(j),

lc = LRUCache(2)
testlru(lc)