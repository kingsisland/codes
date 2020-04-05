def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m
# starts here
t = int(input())
MOD = int(1e9+7)



while t>0:
	n,k = list(int(x) for x in input().split())


	for x in range(n):
		length = int(input())
		if(length == 1):
			print(1)
			continue

		if(length%2==1):
			length = length-1
		if k%2==0:
			P = pow(13- k//2, length//2, MOD) + pow(k,length//2, MOD)
			Q = pow(26,length, MOD)
		else:	# k is odd
			P = pow(26- k, length//2, MOD) + pow(2*k,length//2, MOD)
			Q = pow(26, length, MOD)*pow(2,length//2,MOD)		

	

		Qinv = modinv(Q%MOD, MOD)
		ans = ((P%MOD)* (Qinv%MOD))%MOD	
		print(ans)



	t-=1