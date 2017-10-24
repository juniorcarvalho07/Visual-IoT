import serial
import time
import requests
import json
firebase_url = 'https://minicursoifpi.firebaseio.com/'
#Connect to Serial Port for communication
objeto_porta = serial.Serial('COM3', 9600)
objeto_porta.flushInput();
#Setup a loop to send Temperature values at fixed intervals
#in seconds
fixed_interval = 10