{\rtf1\ansi\ansicpg1252\cocoartf2709
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 Public class AbecedarioHilos\{\
	public static void main(String[] args)\{\
		Runnable mayusculasRunn = new ImprimirAbc(\'91A\'92, \'91Z\'92);\
		Runnable minusculesRunn = new ImprimirAbc(\'91a\'92, \'91z\'92);\
\
		Thread hiloMayusculas = new Thread(mayusculasRunn);\
		Thread hiloMinusculas = new Thread(minusculasRunn);\
\
		hiloMayusculas.start();\
		hiloMinusculas.starrt();\
	\}\
\}\
\
Class ImprimirAbc implements Runnable \{\
	private char inicio;\
	private char fin;\
\
	public ImprimirAbc(char inicio, char fin) \{\
		this.inicio = inicio;\
		this.fin = fin;\
	\}\
\
	public void run() \{\
		for (char letra = inicio; letra <= fin; letra++) \{\
			System.out.print(letra + \'93 \'93);\
		\}\
	\}\
\}}