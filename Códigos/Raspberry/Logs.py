import psutil

class Logs:
		
	def __init__(self):
		self.name ="Logs"
	def Get_Temp_CPU(self):
		return psutil.sensors_temperatures()["cpu-thermal"][0].current
	def Get_Use_CPU(self):
		CPUS = [x / psutil.cpu_count() * 100 for x in psutil.getloadavg()]
		return (CPUS[0] + CPUS[1] + CPUS[2])/3
	def Get_Use_RAM(self):
		return psutil.virtual_memory().percent
	def Get_Use_Disk(self):
		return psutil.disk_usage('/').percent
	


