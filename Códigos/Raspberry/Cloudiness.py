#-----------------------------------------------------------------
#      ___     ___ 
#     |   |   |   |
#     |   |   |   |
#     |   |___|   |
#     |    ___    |
#     |   |   |   |
#     |   |   |   |
#     |___|   |___| alley, Universidad Industrial de Santander
#                   Copyright, Jesus Pe#a Rodriguez, 2014
#-----------------------------------------------------------------
""" Algorithm to measure the cloudiness by means of image segmentation
"""

import cv2
import picamera
import time
import datetime 
import numpy as np

Cloudiness = open('Nubosidad.txt','w')
Cloudiness.close()

camera = picamera.PiCamera()
umbral = np.zeros((768, 1024))

slope = 1.5248
intercept = -77.45

## Funcion de compresion
def resizeImage(img, factor):
	dst = cv2.resize(img, None, fx = factor, fy = factor, interpolation = cv2.INTER_LINEAR)
	return dst

## Funcion de umbral adaptativo
def umbral(B, Ancho, Alto):
	suma = 0
	for i in range (Alto):
		for j in range (Ancho):
			suma = suma + B[i, j]

	um = suma /(Ancho*Alto)
	return um

## Funcion de nubosidad
def nubosidad(C, Ancho, Alto):
	cont = 0
	for i in range (Alto):
		for j in range (Ancho):
			if C[i, j] == 255:
				cont = cont + 1
	porc = cont*100/(Ancho*Alto)
	return porc

def adaptativo (R, G, B, minR, maxR, minG, maxG, minB, maxB, Ancho, Alto):
	out = np.zeros((Alto, Ancho))
	for i in range(Alto):
		for j in range (Ancho):
			if (R[i, j] >= minR and R[i, j] <= maxR and G[i, j] >= minG and G[i, j] <= maxG and B[i , j] >= minB and B[i, j] <= maxB):
				out [i, j] = 0
			else:
				out [i, j] = 255
	return out

def ExtractHSV (HSV, Ancho, Alto):
	H = np.zeros((Alto,Ancho))
	S = np.zeros((Alto, Ancho))
	V = np.zeros((Alto, Ancho))
	for i in range(Alto):
		for j in range(Ancho):
			H[i,j] = HSV[i,j,0]
			S[i,j] = HSV[i,j,1]
			V[i,j] = HSV[i,j,2] 
 	return H, S, V

while True:

## Toma la imagen con la Raspberry Pi camera
	time_name = time.mktime(datetime.datetime.now().timetuple())
	Name = "Fotos/" + str(int(time_name)) + ".jpg"
	camera.resolution = (1024, 768)
	camera.start_preview()
	time.sleep(2)
	camera.capture(Name)
	camera.stop_preview()

## Carga las imagenes
	imagen = cv2.imread(Name) 
	imagen = resizeImage(imagen, 0.25)
	
## Transformacion de la imagen a array
	arr = cv2.cv.fromarray(imagen)
	tam = cv2.cv.GetSize(arr)
        Ancho = tam[0]
        Alto = tam[1]

	r = cv2.cv.CreateImage(cv2.cv.GetSize(arr), cv2.cv.IPL_DEPTH_8U, 1) 	
	g = cv2.cv.CreateImage(cv2.cv.GetSize(arr), cv2.cv.IPL_DEPTH_8U, 1)
	b = cv2.cv.CreateImage(cv2.cv.GetSize(arr), cv2.cv.IPL_DEPTH_8U, 1)

## Extraccion de los canales RGB
	cv2.cv.Split(arr, b, g, r, None)
 
	RU = np.asarray(r[:,:])
	GU = np.asarray(g[:,:])
	BU = np.asarray(b[:,:])

## Umbral dinamico

	R = cv2.cv.fromarray(RU)
	G = cv2.cv.fromarray(GU)
	B = cv2.cv.fromarray(BU)
	
	## HSV channels

	HSV = cv2.cvtColor(imagen,cv2.COLOR_BGR2HSV)
	
	H, S, V = ExtractHSV(HSV,Ancho,Alto)

	
	Feature = cv2.cv.fromarray(V) 
	U = umbral(Feature, Ancho, Alto)

	Th = U*slope + intercept	# Compute the threshold depending on the brightness value
	UMB = adaptativo(R, G, B, 0, Th, 0, Th, 0, Th, Ancho, Alto)


## Umbralizar el canal Blue
	nub = nubosidad(UMB, Ancho, Alto)
	
	cv2.imwrite('Fotos/Um.jpg',UMB)
	
	Cloudiness = open('Nubosidad.txt','w')
	Cloudiness.write(str(nub))
	Cloudiness.close()
	
