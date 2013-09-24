default:
	gcc -Wall -Werror -g src/sorted-list.c src/main.c -o sorted-list

clean:
	rm sorted-list

test:
	./sorted-list
