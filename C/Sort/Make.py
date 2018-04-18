import os
import subprocess
import numpy as np
import matplotlib.pyplot as plt

'''/*================================================================
==================    METADATA OF THE FILE      =====================
===================================================================*/
/**
 * @author  Rosas Hernandez Oscar Andres
 * @author  Alan Enrique Ontiveros Salazar
 * @author  Laura Andrea Morales 
 * @version 0.1
 * @team    CompilandoConocimiento
 * @date    4/03/2018
 * @run     "python3.6 Make.py"
 * @require numpy, matplotlib
 */
'''

DataSize = [
	100, 1000, 5000, 10000, 50000, 100000,
	200000, 400000, 600000, 800000, 1000000, 2000000,
	3000000, 4000000, 5000000, 6000000, 7000000,
	8000000, 9000000, 10000000
] 

DataExtra = [50000000, 100000000, 500000000,
1000000000, 5000000000]

Algorithms = [
	"BubbleSortv1", 
	"BubbleSortv2", 
	"BubbleSortv3", 
	"SelectionSort", 
	"InsertionSort", 
	"ShellSort", 
	"SortWithBST"
] 

Degrees = [1, 2, 3, 4, 8]

ProgramName = "TestSortAlgorithms"
Input       = "Input10Million.txt"
Flags       = "-std=c11 Time.c"

os.system("reset")
os.system(F"gcc {Flags} {ProgramName}.c -o {ProgramName}")

def graficar(data_x, data_y, legends, label_x, label_y, title, file, marker):
	for i in range(0, len(data_x)):
		plt.plot(data_x[i], data_y[i], label = legends[i], marker = marker)
	plt.grid(True)
	plt.xlabel(label_x)
	plt.ylabel(label_y)
	plt.title(title)
	plt.legend(loc='upper center', bbox_to_anchor=(0.5, -0.1), shadow=True, ncol=4)
	plt.savefig(file, bbox_inches='tight')
	plt.clf()

x_real_all = []
y_real_all = []
x_poly_all = []
y_poly_all = []
poly_all   = []

file = open("../outputs/info.txt", "w")

for NumAlgorithm in range(0, len(Algorithms)):

	AlgorithmName = Algorithms[NumAlgorithm]

	x = [];
	y_real = [];
	y_cpu = [];
	y_es = [];
	
	for n in DataSize:

		if NumAlgorithm >= 5 or n <= 1000000:

			OutputPlace = f"../outputs/Out-{AlgorithmName}-N={n}"

			print(f"Running Algorithm {AlgorithmName} for n = {n}")

			OutputProgram = subprocess.check_output(
				f'./{ProgramName} {n} {NumAlgorithm} {OutputPlace} < {Input}',
				shell = True,
				universal_newlines = True)

			Data = [float(i) for i in OutputProgram.split()]
			RealTime = Data[0]
			UserTime = Data[1]
			SysTime = Data[2]
			CPUWall = (UserTime + SysTime) / RealTime;

			x.append(n)
			y_real.append(RealTime)
			y_cpu.append(UserTime)
			y_es.append(SysTime)

			print(f"Real:     {RealTime}s")
			print(f"User:     {UserTime}s")
			print(f"Sys:      {SysTime}s")
			print(f"CPU/Wall: {CPUWall * 100}%")
			print("")

	graficar([x, x, x], [y_real, y_cpu, y_es], ["Tiempo real", "Tiempo CPU", "Tiempo E/S"],
		"Tamaño del problema (n)", "Tiempo (s)", AlgorithmName,
		f"../graphics/{AlgorithmName}-ExperimentalTimes.png", 'o')

	file.write("===" + AlgorithmName + "===\n")
	file.write(" Real times:\n")
	for i in range(0, len(x)):
		file.write(f"({x[i]}, {y_real[i]})\n")
	file.write(" User times:\n")
	for i in range(0, len(x)):
		file.write(f"({x[i]}, {y_cpu[i]})\n")
	file.write(" Sys times:\n")
	for i in range(0, len(x)):
		file.write(f"({x[i]}, {y_es[i]})\n")
	file.write("\n")
	
	x_real_all.append(x)
	y_real_all.append(y_real)

	polynomials_x = []
	polynomials_y = []
	for degree in Degrees:
		xp = np.linspace(0, x[-1], 1000)
		polynomials_x.append(xp)
		polynomial = np.poly1d(np.polyfit(x, y_real, degree))
		evaluations = polynomial(xp)
		polynomials_y.append(evaluations)
		if (NumAlgorithm <= 4 and degree == 2) or (NumAlgorithm >= 5 and degree == 1):
			x_poly_all.append(xp)
			y_poly_all.append(evaluations)
			poly_all.append(polynomial)
	plt.plot(x, y_real, 'o')
	graficar(polynomials_x, polynomials_y, [f"Polinomio grado {Degrees[i]}" for i in range(0, len(Degrees))],
		"Tamaño del problema (n)", "Tiempo (s)", AlgorithmName,
		f"../graphics/{AlgorithmName}-Polynomials.png", '')
	print(end = "\n\n")

file.close()

info_poly = open("../outputs/polynomials.txt", "w")
for i in range(0, len(Algorithms)):
	info_poly.write(Algorithms[i] + "\n")
	info_poly.write("+".join([str(poly_all[i].c[j]) + "x^" + str(poly_all[i].order - j) for j in range(0, poly_all[i].order + 1)]) + "\n")
	for j in range(0, len(DataExtra)):
		info_poly.write(f"{DataExtra[j]}: {str(poly_all[i](DataExtra[j]))}s\n")
	info_poly.write("\n")
info_poly.close()

graficar(x_real_all[0:7], y_real_all[0:7], Algorithms[0:7], "Tamaño del problema (n)", "Tiempo (s)",
	"Comparativa global de tiempos reales", "../graphics/globalComparativeTimes1.png", 'o')

graficar(x_real_all[0:5], y_real_all[0:5], Algorithms[0:5], "Tamaño del problema (n)", "Tiempo (s)",
	"Comparativa global de tiempos reales", "../graphics/globalComparativeTimes2.png", 'o')

graficar(x_real_all[5:7], y_real_all[5:7], Algorithms[5:7], "Tamaño del problema (n)", "Tiempo (s)",
	"Comparativa global de tiempos reales", "../graphics/globalComparativeTimes3.png", 'o')


graficar(x_poly_all[0:7], y_poly_all[0:7], Algorithms[0:7], "Tamaño del problema (n)", "Tiempo (s)",
	"Comparativa global de aproximaciones por polinomio", "../graphics/globalComparativePolynomial1.png", '')

graficar(x_poly_all[0:5], y_poly_all[0:5], Algorithms[0:5], "Tamaño del problema (n)", "Tiempo (s)",
	"Comparativa global de aproximaciones por polinomio", "../graphics/globalComparativePolynomial2.png", '')

graficar(x_poly_all[5:7], y_poly_all[5:7], Algorithms[5:7], "Tamaño del problema (n)", "Tiempo (s)",
	"Comparativa global de aproximaciones por polinomio", "../graphics/globalComparativePolynomial3.png", '')
