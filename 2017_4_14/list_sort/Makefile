CC=gcc
FLAG=-c
OUTPUT=-o
OBJ=test
ALL=main.o common.o 

$(OBJ):$(ALL)
	$(CC) $^ $(OUTPUT) $@ 
%.o:%.c
	$(CC) $(FLAG) $< $(OUTPUT) $@
.PHONY:clean
clean:
	rm -rf *.o test
	
