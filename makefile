all: main

main:

	gcc main1.c  `pkg-config --libs --cflags opencv` `pkg-config --cflags --libs gtk+-2.0` -ldl -lm 
