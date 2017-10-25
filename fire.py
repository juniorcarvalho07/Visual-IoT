import serial
import time
import requests
import json
firebase_url = 'https://minicursoifpi.firebaseio.com/'
#Connect to Serial Port for communication
objeto_porta = serial.Serial('COM3', 9600)
objeto_porta.flushInput();
fixed_interval = 10
while 1:
	try:
		def split1000(s, sep=','):
            return s if len(s) <= 2 else split1000(s[:-2], sep) + sep + s[-2:]
		
		ultrasonic1 = str(objeto_porta.readline())
		
		time_hhmmss = time.strftime('%H:%M:%S')
		date_mmddyyyy = time.strftime('%d/%m/%Y')
		
		ata = {'Distancia sensor 1':tempF2}
		result = requests.post(firebase_url + '#', data=json.dumps(data))#preciso  criar um arquivo json 

		
		
		
		
		
    time.sleep(fixed_interval)
  except IOError:
    print('Error! Something went wrong.')
  time.sleep(fixed_interval)