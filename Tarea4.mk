
all: Resultados_hw4.tex plots.o
	pdflatex Resultados_hw4.tex
	
plots.o: Plots_Temperatura.py datos.o
	python Plots_Temperatura.py

datos.o: Difusion.x rutina.o
	./Difusion.x	

rutina.o: DifusionTemperatura.c
	cc  DifusionTemperatura.c -lm -o Difusion.x

