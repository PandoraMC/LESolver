PROJECT=App
INCLUDE=includes
OBJS=objs
SOURCES=sources

$(PROJECT): $(SOURCES)/$(PROJECT).c $(OBJS)/LESolver.o
	gcc -o $@ $^ -I$(INCLUDE)/

$(OBJS)/LESolver.o: $(SOURCES)/LESolver.c
	gcc -c -o $@ $^ -I$(INCLUDE)/

clear:
	rm $(OBJS)/*.o $(PROJECT)
