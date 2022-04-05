class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = [-1]
        # stack is maintained in increasing order
        # -1 is put into the stack to facilitate distance calculation as (right_smaller - left_smaller + 1)
        # and not to worry about stack being empty at any time
        heights.append(0)
        # 0 is appended to run the loop for the last time for the elements remaining in the stack
        
        length = len(heights)
        max_area = 0
        
        for i in range(length):
            while heights[stack[-1]] > heights[i]:
                # if the top of the stack is greater than the current element,
                # pop the element and calculate the area with left_smaller being the next element on the stack and 
                # right_smaller as the current element
                idx = stack.pop()
                right_smaller = i
                left_smaller = stack[-1]
                
                height = heights[idx]
                width = right_smaller - left_smaller - 1
                area = height * width
                max_area = max(area, max_area)
            stack.append(i)
        
        heights.pop()
        return max_area