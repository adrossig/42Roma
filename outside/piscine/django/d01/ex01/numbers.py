#!/usr/bin/python3

def read_file():
	f = open("numbers.txt", "r")
	for lines in f.readlines():
		print_lines(lines.strip())
	f.close()


def print_lines(line: str):
	lines = line.split(",")
	for temp in lines:
		print(temp)


if __name__ == "__main__":
	read_file()
