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
 * @date    2/04/2018
 * @run     "python3.6 Make.py"
 * @require numpy, matplotlib
 */
'''

'''=======================================================
==================    DATA    ============================
======================================================='''

DataSize = [
    100, 1000, 5000, 10000, 50000, 100000, 
    200000, 400000, 600000, 800000, 1000000, 
    2000000, 3000000, 4000000, 5000000, 
    6000000, 7000000, 8000000, 9000000, 
    10000000 
] 

DataExtra = [
    50000000, 100000000, 500000000,
    1000000000, 5000000000
]

Algorithms = [
    "LinealSearch", 
    "ParalellLinealSearch", 
    "BinarySearch", 
    "ParalellBinarySearch", 
    "SearchWithBST"
]


'''=======================================================
============      COMPILE THE PROGRAM     ================
======================================================='''

CasesFile = "Inputs/RealCases.txt"
CasesSize = 20

ProgramName = "TestSearchAlgorithms"
Input       = "Inputs/Input10MillionSorted.txt"
Flags       = "-std=c11 -pthread Time.c"

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


'''=======================================================
============      RUN THE PROGRAM         ================
======================================================='''

x_all = []
y_all = []
x_poly_all = []
y_poly_all = []
poly_all = []

file = open("Outputs/info.txt", "w")

for NumAlgorithm in range(0, len(Algorithms)):

    AlgorithmName = Algorithms[NumAlgorithm]

    x = []
    y = []

    for n in DataSize:

        OutputPlace = f"Outputs/Out-{AlgorithmName}-N={n}"

        print(f"*********** Running Algorithm {AlgorithmName} for n = {n} ****************")

        OutputProgram = subprocess.check_output(
            f'./{ProgramName} {n} {NumAlgorithm} {CasesSize} {CasesFile} {OutputPlace} < {Input}',
            shell = True,
            universal_newlines = True)

        RealTimeAverage = 0
        UserTimeAverage = 0
        SysTimeAverage  = 0

        print(f"*********** Each Number ****************")
        for Line in OutputProgram.splitlines(False):
            Data = [float(i) for i in Line.split()]
            RealTime = Data[0]
            UserTime = Data[1]
            SysTime = Data[2]

            RealTimeAverage += RealTime
            UserTimeAverage += UserTime
            SysTimeAverage  += SysTime

            CPUWall = (UserTime + SysTime) / RealTime;

            print(f"Real:     {RealTime}s")
            print(f"User:     {UserTime}s")
            print(f"Sys:      {SysTime}s")
            print(f"CPU/Wall: {CPUWall * 100}%")
            print("")

        print(f"*********** Average Time ****************")
        RealTimeAverage /= CasesSize
        UserTimeAverage /= CasesSize
        SysTimeAverage  /= CasesSize
        CPUWallAverage  = (UserTimeAverage + SysTimeAverage) / RealTimeAverage

        x.append(n)
        y.append(RealTimeAverage)

        print(f"Real:     {RealTimeAverage}s")
        print(f"User:     {UserTimeAverage}s")
        print(f"Sys:      {SysTimeAverage}s")
        print(f"CPU/Wall: {CPUWallAverage * 100}%")
        print("")

    graficar([x], [y], ["Tiempo real promedio"],
        "Tamaño del problema (n)", "Tiempo (s)", AlgorithmName,
        f"Graphics/{AlgorithmName}-AvgTimes.png", 'o')

    file.write("===" + AlgorithmName + "===\n")
    file.write(" Average times:\n")
    for i in range(0, len(x)):
        file.write(f" ({x[i]}, {y[i]})\n")
    file.write("\n")

    x_all.append(x)
    y_all.append(y)

    xp = np.linspace(0, x[-1], 1000)
    polynomial = np.poly1d(np.polyfit(x, y, 1))
    evaluations = polynomial(xp)
    x_poly_all.append(xp)
    y_poly_all.append(evaluations)
    poly_all.append(polynomial)
    plt.plot(x, y, 'o')
    graficar([xp], [evaluations], ["Polinomio grado 1"],
        "Tamaño del problema (n)", "Tiempo (s)", AlgorithmName,
        f"Graphics/{AlgorithmName}-Polynomial.png", '')

for i in range(0, len(Algorithms)):
    file.write(Algorithms[i] + "\n")
    file.write("+".join([str(poly_all[i].c[j]) + "x^" + str(poly_all[i].order - j) for j in range(0, poly_all[i].order + 1)]) + "\n")
    for j in range(0, len(DataExtra)):
        file.write(f"{DataExtra[j]}: {str(poly_all[i](DataExtra[j]))}s\n")
    file.write("\n")
file.close()

graficar(x_all[0:5], y_all[0:5], Algorithms[0:5], "Tamaño del problema (n)", "Tiempo (s)",
    "Comparativa global de tiempos reales", "Graphics/globalComparativeTimes1.png", 'o')

graficar(x_all[0:2], y_all[0:2], Algorithms[0:2], "Tamaño del problema (n)", "Tiempo (s)",
    "Comparativa global de tiempos reales", "Graphics/globalComparativeTimes2.png", 'o')

graficar(x_all[2:5], y_all[2:5], Algorithms[2:5], "Tamaño del problema (n)", "Tiempo (s)",
    "Comparativa global de tiempos reales", "Graphics/globalComparativeTimes3.png", 'o')


graficar(x_poly_all[0:5], y_poly_all[0:5], Algorithms[0:5], "Tamaño del problema (n)", "Tiempo (s)",
    "Comparativa global de aproximaciones por polinomio", "Graphics/globalComparativePolynomial1.png", '')

graficar(x_poly_all[0:2], y_poly_all[0:2], Algorithms[0:2], "Tamaño del problema (n)", "Tiempo (s)",
    "Comparativa global de aproximaciones por polinomio", "Graphics/globalComparativePolynomial2.png", '')

graficar(x_poly_all[2:5], y_poly_all[2:5], Algorithms[2:5], "Tamaño del problema (n)", "Tiempo (s)",
    "Comparativa global de aproximaciones por polinomio", "Graphics/globalComparativePolynomial3.png", '')
