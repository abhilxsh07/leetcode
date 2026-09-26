# [1. Two Sum](https://leetcode.com/problems/two-sum/)

**Difficulty:** Easy · **Topics:** Array, Hash Table

## Approach

One pass with a hash map: for each number, check whether its complement (`target - num`) has already been seen.

- **Time:** O(n)
- **Space:** O(n)
