import random
import time
import sys

def merge_sort(nums, low, high):
	if low < high:
		mid = (low + high) // 2
		merge_sort(nums, low, mid)
		merge_sort(nums, mid + 1, high)
		merge(nums, low, mid, high)
		
def merge(nums, low, mid, high):
	left_len = (mid - low) + 1
	right_len = high - mid
	left = []
	right = []
	
	for index in range(low, mid + 1):
		left.append(nums[index])
	for index in range(mid + 1, high + 1):
		right.append(nums[index])
		
	left_index = 0
	right_index = 0
	num_index = low
	while left_index < left_len and right_index < right_len:
		if left[left_index] < right[right_index]:
			nums[num_index] = left[left_index]
			left_index += 1
		else:
			nums[num_index] = right[right_index]
			right_index += 1
		num_index += 1
	while left_index < left_len:
		nums[num_index] = left[left_index]
		left_index += 1
		num_index += 1
	while right_index < right_len:
		nums[num_index] = right[right_index]
		right_index += 1
		num_index += 1

def create_random_number_array(n):
	random_number_array = []
	for index in range(n):
		random_number_array.append(random.randint(-n, n))
	return random_number_array
	
def main():

	size = int(sys.argv[1])
	
	test_array = create_random_number_array(size)

	start = time.time_ns()
	merge_sort(test_array, 0, size - 1)
	stop = time.time_ns()

	print("Python mergeSort() took", (stop-start)/1000000000, "seconds to execute for", size,"elements")
	
if __name__ == "__main__":
	main()

