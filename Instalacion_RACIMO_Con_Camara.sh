echo "POR FAVOR HABILITE LA CAMARA, CONFIGURE LA ZONA"
echo "HORARIA Y HABILITE LA CONEXION SSH"
echo "NO REINICIAR - NO REINICIAR - NO REINICIAR"
echo "NO REINICIAR - NO REINICIAR - NO REINICIAR"
echo "-------------------------------------------------"
echo "-------------------------------------------------"

#sudo raspi-config


echo "ACTUALIZAMOS NUESTRO SISTEMA"
echo "-------------------------------------------------"
echo "-------------------------------------------------"

sudo apt-get -y update

echo "DESCARGAMOS E INSTALAMOS PAQUETES"
echo "-------------------------------------------------"
echo "-------------------------------------------------"

sudo apt-get -y upgrade

echo "INSTALAMOS PYTHON"
echo "-------------------------------------------------"
echo "-------------------------------------------------"

sudo apt-get install -y python

echo "INSTALAMOS GEDIT"
echo "-------------------------------------------------"
echo "-------------------------------------------------"

sudo apt-get install -y gedit

echo "INSTALAMOS PAQUETES PARA LA CAMARA"
echo "-------------------------------------------------"
echo "-------------------------------------------------"

sudo apt-get install -y python-picamera

sudo apt-get install -y python-setuptools

echo "INSTALAMOS OPEN CV"
echo "-------------------------------------------------"
echo "-------------------------------------------------"

sudo apt-get install -y libopencv-dev python-opencv
sudo apt-get install -y python-numpy python-scipy


echo "INSTALAMOS ARDUINO "
echo "-------------------------------------------------"
echo "-------------------------------------------------"

sudo apt-get install -y arduino

echo "INSTALAMOS PYTHON-SERIAL "
echo "-------------------------------------------------"
echo "-------------------------------------------------"

sudo apt-get install -y python-serial

echo "FORZAMOS LA ACTUALIZACION DE PAQUETESE EN CASO DE QUE FALTEN"
echo "-------------------------------------------------"
echo "-------------------------------------------------"

sudo apt-get -y dist-upgrade

echo "FINALMENTE REINICIAMOS"
echo "-------------------------------------------------"
echo "-------------------------------------------------"

sudo shutdown -r now

