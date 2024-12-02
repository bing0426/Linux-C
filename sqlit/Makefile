OBJ_C := $(wildcard *.c)
OBJ_H := $(wildcard *.h)
OBJ_O := $(OBJ_C:.c=.o)


all:final_objective

final_objective:$(OBJ_O)
	cc $^ -o $@

%.o:%.c $(OBJ_H)
	cc -c $< -o $@

clean:
	rm -rf final_objective $(OBJ_O)