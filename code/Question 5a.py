import sys

def main():
	if (len(sys.argv) != 3):
		print("Incorrect number of arguments")
		return
	if (len(sys.argv[1]) >= len(sys.argv[2])):
		print(sys.argv[1])
	if (len(sys.argv[1]) <= len(sys.argv[2])):
		print(sys.argv[2])

main()