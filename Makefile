PROJECT=App
INCLUDE=includes
OBJS=objs
SOURCES=sources

$(PROJECT): $(SOURCES)/$(PROJECT).c $(OBJS)/LESolver.o $(OBJS)/MatFileHandler.o
	gcc -o $@ $^ -I$(INCLUDE)/

$(OBJS)/LESolver.o: $(SOURCES)/LESolver.c
	gcc -c -o $@ $^ -I$(INCLUDE)/

$(OBJS)/MatFileHandler.o: $(SOURCES)/MatFileHandler.c
	gcc -c -o $@ $^ -I$(INCLUDE)/

clear:
	rm $(OBJS)/*.o $(PROJECT)

exe: $(PROJECT)
	./$(PROJECT) x.m
