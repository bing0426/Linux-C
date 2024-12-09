OBJ_H := $(wildcard *.h)

final_objective:$(patsubst %.c, %.o, $(wildcard *.c))
	cc $^ -o $@

%.o:%.c ${OBJ_H}
	cc -c $< -o $@

.PHONY:clean
clean:
	rm -rf *.o final_objective