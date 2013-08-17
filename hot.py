import json
import urllib2
import serial
import time
from secrets import API_KEY

lat = '33.8303'
lon = '-116.5303'

url = 'https://api.forecast.io/forecast/%s/%s,%s?exclude=minutely,daily,alerts,hourly,flags' % (API_KEY, lat, lon)

ser = serial.Serial('/dev/tty.usbmodemfd121', 9600)

while True:

    f = urllib2.urlopen(url)
    data = json.load(f)

    temp = data['currently']['temperature']

    if temp > 80:
        ser.write('1')
    else:
        ser.write('0')

    time.sleep(1)
