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
		
def main():
	nums = [5, 2, 18, 932, 155, 735, 32, 288, 733, 58]
	print(nums)
	merge_sort(nums, 0, 9)
	print(nums)
	
if __name__ == "__main__":
	main()
