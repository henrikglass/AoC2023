WARNINGS := -Wall -Wextra -Wpedantic

day1:
	gcc -Iinclude -O3 -march=native $(WARNINGS) src/day1.c -o day1

clean:
	rm ./day*
