#!/usr/bin/python3

import sys
import antigravity

def main():
	if (len(sys.argv) == 4):
		try:
			latitude = float(sys.argv[3])
		except:
			return print("latitude required type: float")
		try:
			longitude = float(sys.argv[2])
		except:
			return print("longitude required type: float")
		try:
			date = sys.argv[1].encode('utf-8')
		except:
			return print("date required type: string")
		antigravity.geohash(latitude, longitude, date)
	else:
		print("Three arguments is required -> date / longitude / latitude")


if __name__ == '__main__':
	main()
