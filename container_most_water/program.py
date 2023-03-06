# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    program.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 19:12:30 by mbarutel          #+#    #+#              #
#    Updated: 2023/03/03 19:49:03 by mbarutel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Solution:
    def maxArea(self, height):
        i = 0
        max_area = 0
        k = len(height) - 1
        while i != k:
            if height[i] <= height[k]:
                if height[i] * (k - i) > max_area:
                    max_area = height[i] * (k - i) 
                i += 1
            else:
                if height[k] * (k - i) > max_area:
                    max_area = height[k] * (k - i) 
                k -= 1
        return max_area

if __name__ == "__main__":
    solution = Solution()
    print(solution.maxArea([1,8,6,2,5,4,8,3,7]))
        