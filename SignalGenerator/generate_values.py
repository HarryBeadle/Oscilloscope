
import math
pi = math.pi

MAX = 130
N = 32
values = [0]*(N)

# sinusoid parameters
mid = MAX/2
half_range = 60
incr = 2*pi/N

def sinusoid():
	def toPWM(sine_v):
		return int(sine_v * half_range + mid)

	rad = 0
	for i in range(N):
		values[i] = toPWM(math.cos(rad))
		assert 0 <= values[i] <= 255
	 	rad += incr

incr = 255/(N-1)
print incr
def sawtooth():
	values[0] = 0
	for i in range(1,N):
		values[i] = values[i-1] + incr

sawtooth()
print values
print len(values)
