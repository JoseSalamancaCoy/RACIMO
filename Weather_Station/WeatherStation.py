# IMPORTAMOS LIBRERIAS
##########################################

import serial
import time
import datetime
import os.path

# APERTURA DEL PUERTO
##########################################
ser = serial.Serial('/dev/ttyAMA0', 9600,timeout=1)


# BUFFER - HACEMOS VARIAS LECTURAS DEL PUERTO PARA LIMPIARLO DE SIMBOLOS EXTRAnOS
##########################################

for i in range (20):
	line = ser.readline()


# DEFINIMOS LA FUNCION QUE DETERMINARA LO MAXIMOS Y MINIMOS
##########################################

def Max_Min_Valor(Max, Min, Val):

	if ( Val >= Max ):
		Maximo = Val
	if ( Val < Max ):
		Maximo = Max
	if ( Val <= Min ):
		Minimo = Val 
	if (Val > Min):
		Minimo =  Min

	return (Maximo,Minimo)


# INICIALIZAMOS LOS NOMBRE DE ALGUNAS VARIABLES
##########################################

Metadata = "Metadata.txt"
Nubosidad = 'Nubosidad.txt'
Folder = "Data/"
tiempo = datetime.datetime.now()
t = tiempo.timetuple()
Data_File = Folder + 'Datos_' + str(t.tm_year) + '_' + str(t.tm_mon) + '_' + str(t.tm_mday) + '_' + str(t.tm_hour) + '.txt'
hora = t.tm_hour


# CREACION DE ARCHIVO DE DATOS Y METADATA

if os.path.isfile(Metadata):
	bool = True
	archivo = open(Data_File,'a')
	archivo.close()
else:
	bool = False
	archivo = open(Data_File,'w')
	archivo.close()

if bool == False:

	name = raw_input('Nombre de la estacion: ')
	version = 'Version 2.0'
	location = raw_input('Ubicacion: ')
	sensors = raw_input('Sensores conectados: ')
	power = raw_input('Fuente de voltaje: ')
	zone = raw_input ('Zona horaria: ')
	
	file = open('Metadata.txt','a')
	file.write('# Name = ' + name + '\n' + '# Version = ' + version + '\n' + '# Location = ' + location + '\n' + '# Sensors = ' + sensors + '\n' + '# Power = ' +  power + '\n' + '# Time Zone = ' + zone + '\n')
	file.write('#UTCtime Nubosidad Presion Temperatura Humedad Irradiancia Iluminancia  Ruido Lluvia \n')
	file.close()
        
	with open(Metadata, 'r') as F1:
		with open(Data_File, 'a') as F2:
			for line in F1:
				F2.write(line)  
	F1.close()
	F2.close()
	

print 'Estacion Meteorologica Adquiriendo ...'

NUB = 0
PRE = 0
TEM = 0
HUM = 0
IRR = 0
ILU = 0
RUI = 0
LLU = 0
cnt = 0

Cloudiness_file = open(Nubosidad, 'r')		# Load cloudiness data
lines = Cloudiness_file.readlines()
Cloudiness = lines[-1] #Cloudiness_file.readline()
Data = ser.readline()
DS = Data.split('\t')

try:
    Max_Nub = round(int(Cloudiness),1)
    Min_Nub = round(int(Cloudiness),1)

    Max_Pre = round(float(DS[0]),2)
    Min_Pre = round(float(DS[0]),2)

    Max_Tem = round(float(DS[1]),2)
    Min_Tem = round(float(DS[1]),2)

    Max_Hum = round(float(DS[2]),2)
    Min_Hum = round(float(DS[2]),2)

    Max_Irr = round(float(DS[3]),2)
    Min_Irr = round(float(DS[3]),2)

    Max_Ilu = round(float(DS[4]),2)
    Min_Ilu = round(float(DS[4]),2)

    Max_Rui = round(float(DS[5]),2)
    Min_Rui = round(float(DS[5]),2)

    Max_Llu = round(float(DS[6]),2)
    Min_Llu = round(float(DS[6]),2)
    
except ValueError:
    #break
    print ('No entro al ciclo While')
    
Bandera = 1

while 1:	

	Data = ser.readline()				# Load the sensors data from Arduino
	n = datetime.datetime.now()
	Cloudiness_file = open(Nubosidad, 'r')		# Load cloudiness data
	lines = Cloudiness_file.readlines()
	Cloudiness = lines[-1] #Cloudiness_file.readline()
	unix_time = time.mktime(n.timetuple())		# Set unix time stamp
	dt = datetime.datetime(n.year,n.month,n.day,n.hour,n.minute)
	Com = time.mktime(dt.timetuple())
	DS = Data.split('\t')
	Up = unix_time <= (Com+60)
	Down = unix_time > Com
	
	if (Bandera == 1):
            try:
                Max_Nub = round(int(Cloudiness),1)
                Min_Nub = round(int(Cloudiness),1)

                Max_Pre = round(float(DS[0]),2)
                Min_Pre = round(float(DS[0]),2)

                Max_Tem = round(float(DS[1]),2)
                Min_Tem = round(float(DS[1]),2)

                Max_Hum = round(float(DS[2]),2)
                Min_Hum = round(float(DS[2]),2)

                Max_Irr = round(float(DS[3]),2)
                Min_Irr = round(float(DS[3]),2)

                Max_Ilu = round(float(DS[4]),2)
                Min_Ilu = round(float(DS[4]),2)

                Max_Rui = round(float(DS[5]),2)
                Min_Rui = round(float(DS[5]),2)

                Max_Llu = round(float(DS[6]),2)
                Min_Llu = round(float(DS[6]),2)
        
            except ValueError:
                #break
                print ('New Try')
                
            #print ('Pase por aqui')
            Bandera = 0
            

	if ( Up and Down ):
                try:
                    cnt = cnt + 1
                    NUB = NUB + int(Cloudiness)
                    [Max_Nub,Min_Nub] = Max_Min_Valor(Max_Nub, Min_Nub, round(int(Cloudiness),1))
                    PRE = PRE + float(DS[0])
                    [Max_Pre,Min_Pre] = Max_Min_Valor(Max_Pre, Min_Pre, round(float(DS[0]),2))
                    TEM = TEM + float(DS[1])
                    [Max_Tem,Min_Tem] = Max_Min_Valor(Max_Tem, Min_Tem, round(float(DS[1]),2))
                    HUM = HUM + float(DS[2])
                    [Max_Hum,Min_Hum] = Max_Min_Valor(Max_Hum, Min_Hum, round(float(DS[2]),2))
                    IRR = IRR + float(DS[3])
                    [Max_Irr,Min_Irr] = Max_Min_Valor(Max_Irr, Min_Irr, round(float(DS[3]),2))
                    ILU = ILU + float(DS[4])
                    [Max_Ilu,Min_Ilu] = Max_Min_Valor(Max_Ilu, Min_Ilu, round(float(DS[4]),2))
                    RUI = RUI + float(DS[5])
                    [Max_Rui,Min_Rui] = Max_Min_Valor(Max_Rui, Min_Rui, round(float(DS[5]),2))
                    LLU = LLU + float(DS[6])
                    [Max_Llu,Min_Llu] = Max_Min_Valor(Max_Llu, Min_Llu, round(float(DS[6]),2))

                    Line_Data = unix_time+1, Min_Nub, round(NUB/cnt,1), Max_Nub, Min_Pre, round(PRE/cnt,2), Max_Pre, Min_Tem ,round(TEM/cnt,2),Max_Tem, Min_Hum ,round(HUM/cnt,2),Max_Hum, Min_Irr,round(IRR/cnt,2),Max_Irr, Min_Ilu, round(ILU/cnt,2),Max_Ilu, Min_Rui, round(RUI/cnt,2),Max_Rui,Min_Llu, round(LLU/cnt,2),Max_Llu
                    #print (unix_time)
		   # print (Line_Data)
                
                except ValueError:
                    print ('New try')

#	Datos = str(unix_time)+ '\t' + str(Data) 	# Append the data
#	archivo = open(Data_File,'a')
#	archivo.write(Datos)
#	archivo.close()
	else:
		try:
                    archivo = open(Data_File,'a')
                    Variables_Data = str(Line_Data)
                    Final_Line = Variables_Data[1:-1] + '\n'
                    print (Final_Line)
                    archivo.write(Final_Line)
                    archivo.close()
                    time.sleep(2)
                    #print ('END')
                    NUB = 0
                    PRE = 0
                    TEM = 0
                    HUM = 0
                    IRR = 0
                    ILU = 0
                    RUI = 0
                    LLU = 0
                    cnt = 0
                    Bandera = 1
                    
                except NameError:
                    print ('New Try')
	
	tiempo = datetime.datetime.now()
	t = tiempo.timetuple()
	if t.tm_hour != hora:

		Data_File = Folder + 'Datos_' + str(t.tm_year) + '_' + str(t.tm_mon) + '_' + str(t.tm_mday) + '_' +  str(t.tm_hour) + '.txt'
		
		with open(Metadata, 'r') as F1:
	                with open(Data_File, 'a') as F2:
        	                for line in F1:
                	        	F2.write(line)

		F1.close()
		F2.close()
		hora = t.tm_hour




