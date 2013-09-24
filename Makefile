default:
	gcc -Wall -Werror -g sorted-list.c main.c -o sorted-list

clean:
	rm sorted-list

test:
	./sorted-list
