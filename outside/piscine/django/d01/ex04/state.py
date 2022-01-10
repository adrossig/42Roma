#!/usr/bin/python3

import sys

def dict_get_key_from_value(dict: dict, value):
	for key, item in dict.items():
		if item == value:
			return key
	return None


def states_func(key: str):
	states = {
		"Oregon": "OR",
		"Alabama": "AL",
		"New Jersey": "NJ",
		"Colorado": "CO"
	}
	capital_cities = {
		"OR": "Salem",
		"AL": "Montgomery",
		"NJ": "Trenton",
		"CO": "Denver"
	}

	key = dict_get_key_from_value(capital_cities, key)
	if not key:
		print("Unknown capital city")
		return
	print(dict_get_key_from_value(states, key))


def main():
	if len(sys.argv) == 2:
		states_func(sys.argv[1])


if __name__ == '__main__':
	main()
