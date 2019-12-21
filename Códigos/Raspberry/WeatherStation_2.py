
import serial
import time
import datetime
import os.path
from Logs import *
import json
import datetime
import requests
import csv
import threading 
import sys
import logging
import sys

class StreamToLogger(object):
   """
   Fake file-like stream object that redirects writes to a logger instance.
   """
   def __init__(self, logger, log_level=logging.INFO):
      self.logger = logger
      self.log_level = log_level
      self.linebuf = ''

   def write(self, buf):
      for line in buf.rstrip().splitlines():
         self.logger.log(self.log_level, line.rstrip())

logging.basicConfig(
   level=logging.DEBUG,
   format='%(asctime)s:%(levelname)s:%(name)s:%(message)s',
   filename="out.log",
   filemode='a'
)
#Definicion de Funciones
####################################################
def Obtener_structurarData(arduinoPort):
	global timer
	arduinoPort.write("k")
	getSerialValue = arduinoPort.readline()

	try:
		Data = json.loads(getSerialValue)
		Data["fecha_hora_med"] = (datetime.datetime.now() +  datetime.timedelta(hours=5)).strftime("%Y-%m-%dT%H:%M:%S.000z")
		logs = Logs() #Objeto para adquirir Logs de la raspberry
		Data["t_CPU"] = logs.Get_Temp_CPU()
		Data["u_P"] = logs.Get_Use_CPU()
		Data["u_R"] = logs.Get_Use_RAM()
		Data["u_D"] = logs.Get_Use_Disk()
		print("fecha de ultima medicion = {}".format(datetime.datetime.now()))
		return Data
		
	except ValueError:
		print("No es un Json \n Se repite la solicitud")
		return json.loads('{ "error":"No_Json"}') # Retorna Json con error
	else:
		print("Pailas")
		
	
def Monitoreo():
	global timer
	Data = Obtener_structurarData(arduinoPort)
	
	if("error" in Data.keys()):
		return
	with open('Datos.csv', 'a') as csvfile:
		Keys = Data.keys()
		writer = csv.DictWriter(csvfile, fieldnames=Keys)
		writer.writerow(Data)

	timer.cancel() 
	timer = threading.Timer(15*60, Monitoreo)
	timer.start()

	
#Funcion Main

def main():
		
	# Iniciando conexion serial
		
	global arduinoPort
	arduinoPort = serial.Serial('/dev/ttyS0', 9600, timeout=1)
	time.sleep(1.8) 
	
	
	Data = Obtener_structurarData(arduinoPort)

	with open('Datos.csv', 'a') as csvfile:
		Keys = Data.keys()
		writer = csv.DictWriter(csvfile, fieldnames=Keys)
		writer.writeheader()
	


	global timer
	timer = threading.Timer(15*60, Monitoreo)
	timer.start()
	

	while True:			
		print("Corriendo")
		time.sleep(10)
	# Cerrando puerto serial
	arduinoPort.close()


if __name__ == '__main__':
	#Se adiciona errores a archivo out.log
	stderr_logger = logging.getLogger('STDERR')
	sl = StreamToLogger(stderr_logger, logging.ERROR)
	sys.stderr = sl
	#############################
	main()
		
	
	

	#print "Test to standard out"
	#raise Exception('Test to standard error')
	#print(sys.stderr.write)
	#sys.exit()
	
	
	
