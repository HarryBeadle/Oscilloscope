import serial
# import matplotlib.pyplot as mp

s = serial.Serial("/dev/tty.usbserial-FTVTCYMO", 9600)
print "Attached"


def read():
    return ord(s.read())

trigger = int(255 * (1.25/3.3))

y = [read() for x in range(2000)]
t = [i for i in range(2000)]

y = y[::-1]

while not (y[0] < trigger < y[1]):
    y.insert(0, read())
for x in range(2000):
    print str(x) + ", " + str(y[x])
