// =====================================================================
// ============                 IMPORTS            =====================
// =====================================================================
import React from "react"


// =====================================================================
// ============                 ABOUT ME           =====================
// =====================================================================
	const AboutMeSpanish = {
		SayHi: <span> Hola, <b>Soy Oscar</b> </span>,
		ShowMyCV: "VER MI CURRICULUM",
		Description: (
			<span className="blue-grey-text text-darken-4">
				Nerd.

				<br />

				Computólogo, adicto a los memes y a la vida en la biblioteca,
				interesado en la programación competitiva, aunque sea un asco.
				Creo que la web es la plataforma del futuro.
				Amante de la matemática pura, mientras mas inútil mejor, economía
				y filosofía.

				<br />

				Fundador de CompilandoConocimiento.

				<br />

				Ciudadano del mundo.

				<br />
				<br />
				
				<span className="chip">Programación</span>
				<span className="chip">Matemáticas</span>
				<span className="chip">Estudiante</span>
					
			</span>
		),
	}

	const AboutMeEnglish = {
		SayHi: <span>Hi, Im <b>Oscar</b></span>,
		ShowMyCV: "SEE MY CURRICULUM",
		Description: (
			<span className="blue-grey-text text-darken-4">
				Nerd.

				<br />

				Computer scientist, addicted to memes and the life in the library,
				interested in competitive programming, even if I suck.
				I believe that the web is the platform of the future.
				Lover of pure mathematics, the more useless the better, economics
				and philosophy.

				<br />

				Founder of CompilandoConocimiento.

				<br />

				World citizen.

				<br />
				<br />
				
				<span className="chip">Computer Science </span>
				<span className="chip">Math             </span>
				<span className="chip">Student          </span>
					
			</span>
		),
	}



// =====================================================================
// ============                 PROJECTS           =====================
// =====================================================================
	const Projects = {
		CompetitiveReference: {
			Title: (<span> <b>Competitive</b>Reference</span>),
			Type: "Project",
			LinkToProject: "https://github.com/CompilandoConocimiento/Reference",
			Color: "blue-grey darken-3",
			English: (
				<span>
					This is all my personal implementations of the most famous and
					useful competitive programming algorithms.

					<br />
					<br />

					Most of the implementations are in C++, but you can also find them in
					C and even in Python & Java.

					<br />
					<br />

					Im also working on creating a Reference (Book & Website) so many more
					people can benefit from it, and get further along in this awesome mind-sport.
				</span>
			),
			Spanish: (
				<span>
					Recopilación de mis implementaciones personales de los más famosos y útiles
					algoritmos de la programación competitiva.

					<br />
					<br />

					La mayoría de las implementaciones están en C ++, pero también puedes encontrar
					algunas en C e incluso en Python y Java.

					<br />
					<br />

					También estoy trabajando en la creación de un "Refence" (libro y sitio web)
					para que así más personas puedan beneficiarse de esto y avanzar más en este
					increíble deporte mental.
				</span>
			),
			Topics: {
				English: ["C++", "Competitive Programming", "Book"],
				Spanish: ["C++", "Programación Competitiva", "Libro"],
			},
		},
		CompetitiveSolutions: {
			Title: (<span> <b>Competitive</b>Solutions</span>),
			Type: "Project",
			LinkToProject: "https://github.com/CompilandoConocimiento/CompetitiveSolutions",
			Color: "red",
			English: (
				<span>
					This is a repository to store all the solutions for 
					competitive programming problems on Judges online like
					OmegaUp, Codeforces, SPOJ, UVa and many more.

					<br />
					<br />

					Most of the solutions are in C++, because sincerely solving problems
					of this kind in this language is awesome.

					<br />
					<br />

					I work to keep my solutions as readable and clear as possible, but in
					this project I can't promise anything. I am sorry.

				</span>
			),
			Spanish: (
				<span>
					Este es un repositorio para guardar todas las soluciones para los
					problemas de programación competitiva en jueces en línea como
					OmegaUp, Codeforces, SPOJ, UVa y muchos más.

					<br />
					<br />

					La mayoría de las soluciones están en C++, porque resolver
					esa clase de problemas en este lenguaje es increíble.

					<br />
					<br />

					Trabajo para mantener mis soluciones tan legibles y claras como
					sea posible, pero en este proyecto no te puedo prometer nada.
					Lo siento.
				</span>
			),
			Topics: {
				English: ["Competitive Programming", "Solutions", "Online Judges"],
				Spanish: ["Programación Competitiva", "Soluciones", "Jueces en línea"],
			},
		},
		TdeTiendita: {
			Title: (<span> <b>T</b>de<b>Tiendita</b></span>),
			Type: "Project",
			LinkToProject: "https://github.com/SoyOscarRH/TdeTiendita",
			Color: "deep-purple lighten-1",
			English: (
				<span>
					This is a UNFINISHED mini project for a web system (Flask as BackEnd)
					that can control the local store of my family.
					<br />
					<br />
					It allow us to sell products using barcodes, sell by quantity and by price, also 
					it allows us to edit products and add keyboard shorcuts.
					<br />
					<br />
					All the code and documentation is in english, but all the text inside the app is
					in spanish (my mother tongue).
				</span>
			),
			Spanish: (
				<span>
					Mini proyecto INCOMPLETO para una sistema web (Flask como BackEnd)
					que puede controlar la tienda de abarrotes de mi familia.
					<br />
					<br />
					Permite vender productos usando un código de barras así como vender por cantidad
					o por precio.
					Manejar usuarios, editar productos y añadir atajos de teclado.
					<br />
					<br />
					Todo el código fuente esta en inglés, pero todo el texto interno de la aplicación esta
					en español.
				</span>
			),
			Topics: {
				English: ["React", "SPA", "Python-Flask", "MaterializeCSS", "MVP"],
				Spanish: ["React", "SPA", "Python-Flask", "MaterializeCSS", "MVP"],
			},
		},
		ManageYourCinema: {
			Title: (<span> <b>Manage</b>Your<b>Cinema</b> </span>),
			LinkToProject: "https://github.com/SoyOscarRH/ManageYourCinema",
			Type: "Project",
			Color: "teal",
			English: (
				<span>
					This is a UNFINISHED mini project for a web system (PHP as BackEnd)
					that can control a cinema
					
					<br />
					<br />

					Allows to create users and manage them, sell candy and popcorn, an the movie tickets.

					<br />
					<br />
					All the code and documentation is in english, but all the text inside the app is
					in spanish (my mother tongue).
				</span>
			),
			Spanish: (
				<span>
					Mini proyecto INCOMPLETO para una sistema web (PHP como BackEnd)
					que puede controlar un cine:
					
					<br />
					<br />
					
					Permite crear usuarios y administrárlos, vender dulces y palomitas, y las
					entradas para el cine.
					
					<br />
					<br />
					
					Todo el código fuente esta en inglés, pero todo el texto interno de la aplicación esta
					en español.
				</span>
			),
			Topics: {
				English: ["Javascript", "PHP", "MaterializeCSS", "MySQL", "jQuery"],
				Spanish: ["Javascript", "PHP", "MaterializeCSS", "MySQL", "jQuery"],
			},
		},
		LCS: {
			Title: (
				<React.Fragment>
					&nbsp;
					<span className="hide-on-med-and-down">
						<b>Longest</b>Common<b>Subsequence</b>
					</span>

					<span className="hide-on-large-only">
						<b>L</b>C<b>S</b>
					</span>
				</React.Fragment>
			),
			LinkToProject: "https://github.com/SoyOscarRH/LCS",
			CheckOut: "https://soyoscarrh.github.io/LCS/",
			Type: "Project",
			Color: "blue",
			English: (
				<span>
					This is a webapp made with React that can simulate the solution of the famous
					problem of the Longest Common Subsequence of any 2 strings step by step.
					This is done with a DP (dynamic programming) using a bottom-up aproach table.

					<br />
					<br />

					All the code and documentation is in english, but all the text inside the app is
					in spanish (my mother tongue).

				</span>
			),
			Spanish: (
				<span>
					Esta es una aplicación web creada con React que puede simular la solución del
					famoso problema de la Subsecuencia común más larga de cualquiera 2 cadenas
					paso por paso.

					<br />
					<br />

					Todo el código fuente esta en inglés, pero todo el texto interno de la aplicación esta
					en español.
				</span>
			),
			Topics: {
				English: ["Javascript", "React", "MaterializeCSS", "DP", "Competitive Programming"],
				Spanish: ["Javascript", "React", "MaterializeCSS", "DP", "Programación Competitiva"]
			},
		},
		AlphabetSoup: {
			Title: (<span> <b>Alphabet</b>Soup</span>),
			Type: "Project",
			LinkToProject: "https://github.com/SoyOscarRH/AlphabetSoup",
			CheckOut: "https://soyoscarrh.github.io/AlphabetSoup/",
			Color: "pink lighten-1",
			English: (
				<span>
					Simple game made with React to make people happy. Just for fun.

					<br />

					As in many projects, code is in english and text is in spanish.
					<br />
					<br />

					You can choose beetwen many categories, see a visual help of the
					words that you have not found yet, you can change
					the grid size and even activate hints to find the words.
				</span>
			),
			Spanish: (
				<span>
					Un simple juego hecho con React para hacer a la gente feliz, solo
					esta hecho por diversión.
					
					<br />

					Como muchos otros proyectos, el código fuente esta en ingles,
					pero todo el texto el las palabras a buscar estan es español.

					<br />
					<br />

					Puedes elegir entre varias categorías para elegir el tema
					de las palabras, así como cambiar el tamaño del tablero y activar
					pistas.
				</span>
			),
			Topics: {
				English: ["Javascript", "React", "MaterializeCSS", "Sideproject"],
				Spanish: ["Javascript", "React", "MaterializeCSS", "Projecto Personal"]
			},
		},
		BezierCurve: {
			Title: (<span> <b>Bezier</b>Curves</span>),
			Type: "Program",
			LinkToProject: "https://github.com/SoyOscarRH/LearningJava/tree/master/ArtWithLines",
			Color: "orange darken-3",
			English: (
				<span>
					A simple function that draws Bezier curves and some example of how to use it, and
					the results you get by changing the paramaters.

					<br />
					<br />

					Also I have examples of many figures that you can create 
					using this Curves, I assure you, they are beautiful.

				</span>
			),
			Spanish: (
				<span>
					Una simple función que dibuja las Curvas de Bezier y algunos ejemplos de cómo usarlo,
					y los resultados que obtienes al cambiar los parámetros.

					<br />
					<br />

					También tengo ejemplos de muchas figuras que puedes crear
					usando estas curvas, te lo aseguro, son hermosas.

				</span>
			),
			Topics: {
				English: ["Java", "Math", "Java Swing"],
				Spanish: ["Java", "Matemáticas", "Java Swing"],
			},
		},
		CreatingWithLaTeX: {
			Title: (<span> <b>Creating</b>With<b>LaTeX</b></span>),
			Type: "Program",
			LinkToProject: "https://github.com/CompilandoConocimiento/CreatingWithLatex/",
			Color: "cyan accent-3",
			English: (
				<span>
					This is where I put all the things that I need when working with LaTeX:
					code to insert an image, make covers, insert tables.

					<br />
					<br />

					Also, here I save a the header I use in almost all my files, which
					have many math commands for easier and higher level equations as
					\Cis, \UpperDerivate, \BigBrackets, \GenericField, etc...
				</span>
			),
			Spanish: (
				<span>
					Aquí es donde pongo todas las cosas que necesito cuando trabajo
					con LaTeX: código para insertar una imagen, hacer cubiertas,
					insertar tablas.

					<br />
					<br />

					Además, aquí guardo el encabezado que uso en casi todos mis archivos,
					que tienen muchos comandos matemáticos para un manejo más fácil y
					de mayor nivel como: 
					\Cis, \UpperDerivate, \BigBrackets, \Generic Field, etc...
				</span>
			),
			Topics: {
				English: ["LaTeX", "Math", "Reference"],
				Spanish: ["LaTeX", "Matemáticas", "Referencia"],
			},
		},
		RootFinder: {
			Title: (<span> <b>Root</b>Finder</span>),
			Type: "Program",
			LinkToProject: "https://github.com/SoyOscarRH/LearningJava/tree/master/RootFinder",
			Color: "pink lighten-2",
			English: (
				<span>
					This is a simple program in Python (Python2 :v) to find
					the n-roots of a complex number.

					<br />
					<br />

					It works, but is ugly and ... it is on Python 2
				</span>
			),
			Spanish: (
				<span>
					Este es un simple programa en Python (Python2 :v) para
					encontrar las n-raíces de un número complejo.

					<br />
					<br />

					Funciona y todo, pero es feo y ... esta en Python 2
				</span>
			),
			Topics: {
				English: ["Python3", "Math", "Complex Analysis"],
				Spanish: ["Python3", "Matemáticas", "Análisis Complejo"],
			},
		},
		LinearRegression: {
			Title: (<span> <b>Linear</b>Regression</span>),
			Type: "Program",
			LinkToProject: "https://github.com/CompilandoConocimiento/ThingsWithPython/tree/master/LinearRegression",
			Color: "green lighten-1",
			English: (
				<span>
					This is a program in Python using Matplotlib to calculate and graph the linear regression
					over a data set. It also give you the Pearson Coefficient
				</span>
			),
			Spanish: (
				<span>
					Este es un programa en Python usando Matplotlib para calcular  y grafica la regresión lineal
					sobre un conjunto de datos. También te da el coeficiente de Pearson
				</span>
			),
			Topics: {
				English: ["Python2", "Matplotlib", "LinearRegression"],
				Spanish: ["Python2", "Matplotlib", "Regresión Líneal"],
			},
		},
		Fractals: {
			Title: (<span><b>Fractals</b></span>),
			Type: "Program",
			LinkToProject: "https://github.com/CompilandoConocimiento/ThingsWithPython/tree/master/Fractals",
			Color: "yellow accent-4",
			English: (
				<span>
					This is a program in Python to graph a simple fractal, for now is only
					the Sierpinkski Triangle
				</span>
			),
			Spanish: (
				<span>
					Este es un programa en Python para graficar un simple fractal, por
					ahora solo he implementado el triangulo de Sierpinkski
				</span>
			),
			Topics: {
				English: ["Python", "Turtle", "Fractals"],
				Spanish: ["Python", "Turtle", "Fractales"],
			},
		},
		PlayPoker: {
			Title: (<span><b>Play</b>Poker</span>),
			Type: "Program",
			LinkToProject: "https://github.com/CompilandoConocimiento/ThingsWithPython/tree/master/PlayPoker",
			Color: "indigo lighten-1",
			English: (
				<span>
					This is a program in Python to "play poker", well, sort of, because I have never play
					poker... Is just a weird school exercise.
				</span>
			),
			Spanish: (
				<span>
					Este es un programa en Python para "jugar al póquer", bueno, más o menos,
					porque nunca he jugado al póquer ... Es solo un ejercicio escolar extraño.
				</span>
			),
			Topics: {
				English: ["Python", "Weird", "MVP"],
				Spanish: ["Python", "Raro", "MVP"],
			},
		},
	}



// =====================================================================
// ============                 BOOKS              =====================
// =====================================================================

const AboutBooks = {
	English: (
		<div className="blue-grey-text text-darken-3" style={{textAlign: "justify"}}>
			
			<br />
			<h6 style={{textAlign: "center"}}><b>Books, "Compilados" or Notes?</b></h6>
			<br />

			<span>
				First of all, I have to admit that many of these texts have been written together with
				a lot of people, people who without them I could not have gotten that far, thanks Alan,
				Laura, Abbi, Leilan and all my teachers.

				<br />
				<br />

				<b> So... What the hell are these texts? </ b>

				<br />
				<br />

				The most immediate answer is that these texts (or "Compilados" as I like to tell them)
				Are a compilation of theorems, ideas, examples and important concepts that we learned throughout
				of time on each of the topics.

				<br />
				<br />

				On a regular basis we will be updating these texts with everything new that we learn
				trying to deepen in all these topics and close possible doubts in these pages.
				These "Compilados" try to be as strict as possible, although we are human (and students)
				and it is possible (and even probable) that we make small mistakes from time to time.
				I hope you take these pages as a gift created by imperfect beings with hopes to make
				the world a better place.
			</span>
		</div>
	),
	Spanish: (
		<div className="blue-grey-text text-darken-3" style={{textAlign: "justify"}}>
			
			<br />
			<h6 style={{textAlign: "center"}}><b>¿Libros, Compilados o Apuntes?</b></h6>
			<br />

			<span>
				Antes que nada, tengo que admitir que muchos de estos textos los he escrito con conjunto con
				un montón de gente, gente que sin ellos no podría haber llegado tan lejos, gracias Alan,
				Laura, Abbi, Leilan y a todos mis profesores.

				<br />
				<br />

				<b>Ahora, ¿Qué demonios son estos textos?</b>

				<br />
				<br />

				La respuesta mas inmediata es que estos texto (o compilado como a mí me gusta decirles)
				son una recopilación de teoremas, ideas, ejemplos y conceptos importantes que aprendímos a lo largo
				del tiempo sobre cada uno de los temas.
				
				<br />
				<br />

				De manera regular estaremos actualizando estos textos con todo aquello nuevo que aprendamos
				intentando profundizar en todos estos temas y cerrar posibles dudas en estas páginas.
				Estos Compilados intentamos ser lo más estrictos posible, aunque somos humanos (y estudiantes)
				y es posible(e incluso probable) que cometamos pequeños errores de vez en cuando.
				Espero que tomes estas páginas como un regalo creado por seres imperfectos pero con muchos
				ánimos de hacer del mundo un lugar mejor, ahora si, abróchate los cinturones que esto acaba de
				empezar.
			</span>

		</div>
	),
}


const BooksData = {
	AnalisisComplejo: {
		Title: {
			English: <span><b>Complex</b> Analysis</span>,
			Spanish: <span><b>Análisis</b> Complejo</span>,
		},
		SimpleTitle: {
			English: "Complex Analysis",
			Spanish: "Análisis Complejo",
		},
		LinkToProject: "https://github.com/CompilandoConocimiento/LibroAnalisisComplejo",
		Color: "red lighten-1",
		Intro: {
			English: (
				<span>
					This is the book contains the bases of all the mathematics necessary for complex analysis,
					we talk about complex numbers, how to operate with them and the various forms that
					we have to represent them.

					<br />
					<br />

					We see how we can extend the idea of the calculation on complex functions, we will see the
					complex integrals and as they are often easier than "normal" ones.
					We see the residuals and the power series and how to simplify all these operations even more.

					<br />
					<br />

					We finally see Fourier, how to make his series, how to make his transform and how it is
					that with solve differential equations is the simplest thing in the world.

					<br />
					<br />

					This book is in Spanish only. Sorry :(
				</span>
			),
			Spanish: (
				<span>
					Este es libro contiene las bases de toda la matemática necesaria para el análisis complejo,
					hablaremos sobre los números complejos, como operar con ellos y las diversas formas que
					tenemos de representarlos.

					<br />
					<br />

					Veremos como podemos extender la idea del Cálculo sobre funciones complejas, veremos las
					integrales complejas y como muchas veces resultan más faciles que las “normales”. 
					Veremos los residuos y las series de potencias y como simplificar aun más todas las operaciones.

					<br />
					<br />

					Veremos finalmente a gran Fourier, como hacer sus series y como hacer su transformada y como es
					que con ella resolver ecuaciones diferenciales es de lo más sencillo del mundo
				</span>
			),
		},
		Topics: {
			Spanish: [
				{
					Name: "Números Complejos",
					SubTopics: [
						"Heaviside",
						"Funciones Trigonometricos",
						"Definición de i",
						"Definición del Campo de los Complejos",
					]
				},
				{
					Name: "Aritmética Compleja",
					SubTopics: [
						"Operaciones Básicas",
						"Elemento Identidad",
						"Inverso Multiplicativo",
						"Conjugado",
						"Valor Absoluto",
						"Producto Punto y Cruz",
					]
				},
				{
					Name: "Forma Polar",
					SubTopics: [
						"Forma Polar",
						"Argumento de z",
					]
				},
				{
					Name: "Forma de Euler y Raíces",
					SubTopics: [
						"Forma de Euler",
						"Identidad de Lagrange",
						"Ley de Moivre",
						"Raíces",
					]
				},
				{
					Name: "Funciones Complejas",
					SubTopics: [
						"Definición",
						"Fn Hiperbolicas",
						"Fn Trigonometricas",
						"Límites",
					]
				},
				{
					Name: "Derivación",
					SubTopics: [
						"Funciones Analíticas",
						"Continuidad",
						"Ecuaciones de Cauchy-Riemann",
						"Funciones Armónicas",
					]
				},
				{
					Name: "Integración",
					SubTopics: [
						"Teorema de la Deformación",
						"Teorema de Cauchy-Goursat",
						"Teorema de la Integral de Cauchy",
						"Teorema de la Derivación",
					]
				},
				{
					Name: "Series Complejas",
					SubTopics: [
						"Serie Geométrica",
						"Serie de Potencias",
						"Serie de Taylor",
						"Serie de Maclaurin",
						"Serie de Laurent",
						"Polos y Singularidades",
					]
				},
				{
					Name: "Residuos",
					SubTopics: [
						"Definición",
						"Como encontrarlos",
						"Teorema del Residuo de Cauchy",
					]
				},
				{
					Name: "Serie de Fourier",
					SubTopics: [
						"Teorema de Fourier",
						"Coeficientes de Fourier",
						"Serie Compleja",
						"Aplicaciones",
					]
				},
				{
					Name: "Transformada de Fourier",
					SubTopics: [
						"Definición",
						"Integral Compleja de Fourier",
						"Transformadas por Definición",
						"Transformadas de Derivadas",
						"Transformadas de Desplazamientos",
						"Teorema de la Simetría",
						"Teorema de la Escalamiento",
						"Teorema de la Modulación",
						"Transformada Inversa",
						"Convolución",
						"Ecuaciones Diferenciales",
					]
				},
			],
			English: [
				{
					Name: "Complex Numbers",
					SubTopics: [
						"Heaviside",
						"Trigonometric functions",
						"Definition of i",
						"Definition of the Complex Field",
					]
				},
				{
					Name: "Complex Arithmetic",
					SubTopics: [
						"Basic operations",
						"Identity Element",
						"Inverse multiplicative",
						"Conjugate",
						"Absolute value",
						"Point y Cross Product",
					]
				},
				{
					Name: "Polar Form",
					SubTopics: [
						"Polar Form",
						"Argument of z",
					]
					},
				{
					Name: "Form of Euler and Roots",
					SubTopics: [
						"Form of Euler",
						"Lagrange Identity",
						"Law of Moivre",
						"Estate",
					]
				},
				{
					Name: "Complex Functions",
					SubTopics: [
						"Definition",
						"Hyperbolic Fn",
						"Fn Trigonometric",
						"Limits",
					]
				},
				{
					Name: "Derivation",
					SubTopics: [
						"Analytical functions",
						"Continuity",
						"Cauchy-Riemann equations",
						"Harmonic functions",
					]
				},
				{
					Name: "Integration",
					SubTopics: [
						"Deformation Theorem",
						"Cauchy-Goursat Theorem",
						"Cauchy's Integral Theorem",
						"Derivation Theorem",
					]
				},
				{
					Name: "Complex Series",
					SubTopics: [
						"Geometric Series",
						"Power Series",
						"Taylor series",
						"Maclaurin Series",
						"Laurent Series",
						"Poles and Singularities",
					]
				},
				{
				Name: "Waste",
					SubTopics: [
						"Definition",
						"How to find them",
						"Cauchy Residue Theorem",
					]
				},
				{
					Name: "Fourier Series",
					SubTopics: [
						"Fourier's Theorem",
						"Fourier coefficients",
						"Complex Series",
						"Applications",
					]
				},
				{
					Name: "Fourier Transform",
					SubTopics: [
						"Definition",
						"Complex Fourier Integral",
						"Transformed by Definition",
						"Transformed Derivatives",
						"Transfers of Transfers",
						"Symmetry Theorem",
						"Escalation Theorem",
						"Modulation Theorem",
						"Reverse Transform",
						"Convolution",
						"Differential equations",
					]
				},
			]
		},
		Tags: {
			English: ["Complex Analysis and Calculus", "Fourier", "Complex Numbers"],
			Spanish: ["Análisis y Cálculo Complejo", "Fourier", "Números Complejos"],
		},
		CoAuthors: "Ángel López Manríquez",
		LinkToReadOnline: "https://github.com/CompilandoConocimiento/LibroAnalisisComplejo/blob/master/AnalisisComplejo.pdf",
		LinkToDownload:"https://github.com/CompilandoConocimiento/LibroAnalisisComplejo/raw/master/AnalisisComplejo.pdf",
	},
	TeoriaDeNumeros: {
		Title: {
			English: <span><b>Number</b> Theory</span>,
			Spanish: <span><b>Teoría</b> de Números</span>,
		},
		SimpleTitle: {
			English: "Number Theory",
			Spanish: "Teoría de Números",
		},
		LinkToProject: "https://github.com/CompilandoConocimiento/LibroTeoriaDeNumeros",
		Color: "green lighten-1",
		Intro: {
			English: (
				<span>
					Come on, you have to admit that this book has the coolest name in the world,
					Here you will learn everything about the integers, their cousins and their mysteries.

					<br />
					<br />

					Above all, this text focuses on divisibility, we will talk about Euclid's algorithms,
					as well as the classical GCD, LCM, the diofantic equations, as well as the Phi function.

					<br />
					<br />

					Finally we will see everything you need to know about congruences, how to use them to solve problems,
					Modular Arithmetic and important Theorems such as Wilson's, Chinese Residual Theorem or one of Fermat's.

					<br />
					<br />

					This book is in Spanish only. Sorry :(
				</span>
			),
			Spanish: (
				<span>
					Vamos, tienes que admitir que esta materia tiene el nombre mas genial del mundo,
					Aquí aprenderas todo sobre los enteros, los primos y sus misterios.

					<br />
					<br />

					Sobretodo este texto se enfoca en la divisibilidad, hablaremos de los
					algoritmos de Euclides, así como del clásico GCD, LCM, las ecuaciones
					diofanticas, así como la función de Phi.

					<br />
					<br />

					Finalmente veremos todo lo que necesitas saber de las congruencias, como
					usarlas para resolver problemas, la Aritmética Modular y Teoremas importantes 
					como el de Wilson, Teorema Chino del Residuo o alguno de Fermat.
				</span>
			),
		},
		Topics: {
			Spanish: [
				{
					Name: "Enteros",
					SubTopics: [
						"Construcción de los Enteros",
						"Operaciones con los Enteros",
					]
				},
				{
					Name: "Divisibilidad",
					SubTopics: [
						"Algoritmo de la División",
						"Divisibilidad",
						"Máximo Común Divisor",
						"Algoritmo de Euclides",
						"Mínimo Común Múltiplo",
						"Ecuaciones Diofanticas",
						"Función Phi de Euler",
					]
				},
				{
					Name: "Números Primos",
					SubTopics: [
						"Definición",
						"Proposiciones Importantes",
						"Teorema Fundamental de la Aritmética",
						"Factorización",
					]
				},
				{
					Name: "Congruencias",
					SubTopics: [
						"Congruencias Módulo N",
						"Aritmetica Modular",
						"Teoremas Importantes",
						"Teorema de Wilson",
						"Teorema Chino del Residuo",
						"Ecuaciones Modulares",
					]
				},
				{
					Name: "Polinomios",
					SubTopics: [
						"Cosas Básicas",
					]
				},
			],
			English: [
				{
					Name: "Integers",
					SubTopics: [
						"Construction of the Integers",
						"Operations with the Integers",
					]
				},
				{
					Name: "Divisibility",
					SubTopics: [
						"Algorithm of the Division",
						"Divisibility",
						"Greatest common divisor",
						"Algorithm of Euclid",
						"Minimum Common Multiple",
						"Diofantic equations",
						"Phi function of Euler",
					]
				},
				{
					Name: "Prime Numbers",
					SubTopics: [
						"Definition",
						"Important Proposals",
						"The fundamental theorem of arithmetic",
						"Factoring",
					]
				},
				{
					Name: "Congruences",
					SubTopics: [
						"Congruences Module N",
						"Modular Arithmetic",
						"Important Theorems",
						"Wilson's Theorem",
						"Chinese Theorem of the Residue",
						"Modular equations",
					]
				},
				{
					Name: "Polynomials",
					SubTopics: [
						"Basic things",
					]
				},
			]
		},
		Tags: {
			English: ["Number Theory", "Divisibility", "Congruences"],
			Spanish: ["Teoría de Número", "Divisibilidad", "Congruencias"],
		},
		CoAuthors: "",
		LinkToReadOnline: "https://github.com/CompilandoConocimiento/LibroTeoriaDeNumeros/blob/master/TeoriaDeNumeros.pdf",
		LinkToDownload:"https://github.com/CompilandoConocimiento/LibroTeoriaDeNumeros/raw/master/TeoriaDeNumeros.pdf",
	},
	MatematicasDiscretas: {
		Title: {
			English: <span><b>Discrete</b> Math</span>,
			Spanish: <span><b>Matemáticas</b> Discretas</span>,
		},
		SimpleTitle: {
			English: "Discrete Math",
			Spanish: "Matemáticas Discretas",
		},
		LinkToProject: "https://github.com/CompilandoConocimiento/LibroMatematicasDiscretas",
		Color: "blue lighten-1",
		Intro: {
			English: (
				<span>
					This book contains the bases of all the mathematics, at least a small introduction,
					starting with Logic, induction and inferences.

					<br />
					<br />

					It contains the bases of the most famous mathematical object and perhaps the most important of all,
					sets, sets and sets, learn something Sets!

					<br />
					<br />

					Finally we will learn about relations and functions, the real base of Calculus.

					<br />
					<br />

					This book is in Spanish only. Sorry :(
				</span>
			),
			Spanish: (
				<span>
					Este libro contiene las bases de todas las matemáticas, al menos una pequeña introducción,
					comenzando con la Lógica. Inducción e inferencias.

					<br />
					<br />

					Contiene las bases del objeto matemático más famoso y tal vez el más importante de todos,
					conjuntos, conjuntos y conjuntos, ¡Aprende algo Conjunto!

					<br />
					<br />

					Finalmente, aprenderemos sobre las relaciones y funciones, la base real de Cálculo.
				</span>
			),
		},
		Topics: {
			Spanish: [
				{
					Name: "Lógica Matemática",
					SubTopics: [
						"Proposiciones",
						"Conectores Lógicos",
						"Equivalentes Lógicos",
						"Leyes de Lógica",
						"Inferencias Lógicas",
					]
				},
				{
					Name: "Cuantificadores Lógicos",
					SubTopics: [
						"Cuantificadores Y Sentencias Abiertas",
						"Cuantificador Universal",
						"Cuantificador Existencial",
						"Leyes",
					]
				},
				{
					Name: "Conjuntos",
					SubTopics: [
						"Definición",
						"¿Cómo definirlo?",
						"Clasificación",
						"Conjunto Vacío",
						"Conjunto Universo",
					]
				},
				{
					Name: "Álgebra de Conjuntos",
					SubTopics: [
						"Equivalencia",
						"Subconjunto",
						"Intersección",
						"Unión",
						"Resta",
						"Complemento",
						"Producto Potencia",
						"Producto Cartesiano",
						"Leyes de Conjuntos",
						"Cardinalidad y sus propiedades",
					]
				},
				{
					Name: "Relaciones",
					SubTopics: [
						"Definición",
						"Dominio, Contradominio e Imágen",
						"Relación Inversa",
						"Relación Compuesta",
						"Relación Identidad",
						"Reflexiva, Simétrica y Transitiva",
						"Relación Equivalencia",
					]
				},
				{
					Name: "Funciones",
					SubTopics: [
						"Definición",
						"Dominio e Imágen",
						"Inyectivas, Suprayectivas y Biyectivas",
						"Función Inversa",
						"Conjuntos Equipotentes",
						"Cardinalidad",
					]
				},
				{
					Name: "Cosas Fueras de Lugar",
					SubTopics: [
						"Inducción",
						"Grupos",
						"Anillos",
						"Campos",
					]
				},
			],
			English: [
				{
					Name: "Mathematical Logic",
					SubTopics: [
						"Propositions",
						"Logical connectors",
						"Logical Equivalents",
						"Logic Laws",
						"Logical Inferences",
					]
				},
				{
					Name: "Logical Quantifiers",
					SubTopics: [
						"Quantifiers and Open Sentences",
						"Universal Quantifier",
						"Existential Quantifier",
						"Laws",
					]
				},
				{
					Name: "Sets",
					SubTopics: [
						"Definition",
						"How to define it?",
						"Classification",
						"Empty Set",
						"Universe Set",
					]
				},
				{
					Name: "Set Operations",
					SubTopics: [
						"Equivalence",
						"Subset",
						"Intersection",
						"Union",
						"Subtraction",
						"Complement",
						"Product Power",
						"Cartesian product",
						"Laws of Sets",
						"Cardinality and its properties",
					]
				},
				{
					Name: "Relations",
					SubTopics: [
						"Definition",
						"Domain, Condominium and Image",
						"Inverse Relations",
						"Composite Relations",
						"Identity Relations",
						"Reflective, Symmetric and Transitive",
						"Equivalence Relation",
					]
				},
				{
					Name: "Functions",
					SubTopics: [
						"Definition",
						"Domain and Image",
						"Injectives, Suprayectives and Bijectives",
						"Reverse Function",
						"Equipotent Sets",
						"Cardinality",
					]
				},
				{
					Name: "Thing out of Place",
					SubTopics: [
						"Induction",
						"Groups",
						"Rings",
						"Fields",
					]
				},
			]
		},
		Tags: {
			English: ["Math", "Sets", "Functions", "Logics"],
			Spanish: ["Matemáticas", "Conjuntos", "Funciones", "Lógica"],
		},
		CoAuthors: "",
		LinkToReadOnline: "https://github.com/CompilandoConocimiento/LibroMatematicasDiscretas/blob/master/MatematicasDiscretas.pdf ",
		LinkToDownload:"https://raw.githubusercontent.com/CompilandoConocimiento/LibroMatematicasDiscretas/master/MatematicasDiscretas.pdf",
	},
}







// =====================================================================
// ============                 SIDE BAR           =====================
// =====================================================================

const ProjectsAndPrograms = [] 
Object.entries(Projects).forEach( ([Key, Values]) => {
	ProjectsAndPrograms.push(
		[<span>&nbsp;&nbsp;{Key}</span>, Key, Values.Type]
	)
})

const BooksNames = [] 
Object.entries(BooksData).forEach( ([Key, Values]) => {
	BooksNames.push(
		[Values.SimpleTitle, Key]
	)
})

const SideMenuSpanish = {
	AboutMe: {
		Title: "Personal",
		Links: [
			[<span>&nbsp;&nbsp;&nbsp;Sobre Mi</span>, "AboutMe"],
			[<span>&nbsp;&nbsp;&nbsp;Curriculum</span>, "AboutMe"],
		]
	},
	Projects: {
		Title: "Proyectos",
		Links: ProjectsAndPrograms.filter( e => e[2] === "Project" )
	},
	Programs: {
		Title: "Programas",
		Links: ProjectsAndPrograms.filter( e => e[2] === "Program" )
	},
	Books: {
		Title: "Libros",
		Links: BooksNames.map( e => [<span>&nbsp;&nbsp;{e[0].Spanish}</span>, e[1]] )
	}
}

const SideMenuEnglish = {
	AboutMe: {
		Title: "Personal",
		Links: [
			[<span>&nbsp;&nbsp;&nbsp;About Me</span>, "AboutMe"],
			[<span>&nbsp;&nbsp;&nbsp;Curriculum</span>, "AboutMe"],
		]
	},
	Projects: {
		Title: "Projects",
		Links: ProjectsAndPrograms.filter( e => e[2] === "Project" )
	},
	Programs: {
		Title: "Programs",
		Links: ProjectsAndPrograms.filter( e => e[2] === "Program" )
	},
	Books: {
		Title: "Books",
		Links: BooksNames.map( e => [<span>&nbsp;&nbsp;{e[0].English}</span>, e[1]] )
	}
}







// =====================================================================
// ============                EXPORT              =====================
// =====================================================================


export const Data = {
	AboutMe: {
		Spanish: AboutMeSpanish,
		English: AboutMeEnglish,
	},
	Projects: Projects,
	Books: {
		Books: BooksData,
		AboutBooks,
	},
	SideMenu: {
		Spanish: SideMenuSpanish,
		English: SideMenuEnglish,
	}

}