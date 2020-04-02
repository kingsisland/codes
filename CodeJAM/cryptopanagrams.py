from sys import stdin,stdout
def gcd_euclid(a,b):	
	if b==0 or a==b:
		return a
	return gcd_euclid(b, a%b)


t = int(stdin.readline())

test_no = 1


while test_no <= t:
	# reads N and L
	input()

	#reads L vals i.e, cipher products
	prods = list(map(int, stdin.readline().split(' ')))

	primes = [0] * (len(prods)+1)

	i = -1
	for idx in range(1, len(prods)):
		val = gcd_euclid(prods[idx], prods[idx-1])
		if(val < prods[idx] and val > 1):
			primes[idx] = val
			i = idx
			break

			
	assert i > 0	
	j = i-1
	while j >=0:
		primes[j] = prods[j]//primes[j+1]
		j = j-1

	j = i+1

	while j < len(primes):
		primes[j] = prods[j-1]//primes[j-1]
		j = j+1


	keys = list(sorted(set(primes)))
	

	value = 'A'
	dictionary = dict()

	for key in keys:
		dictionary[key] = value
		value = chr(ord(value) + 1)

	print('Case #'+ str(test_no)+': ')
	sol = ""
	for prime in primes:
		sol+=dictionary[prime]

	print(sol+'\n')
	test_no+=1




