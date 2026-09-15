class Solution:
    def isHappy(self, n: int) -> bool:
        done = set()

        while n != 1:
            if n in done:
                return False

            done.add(n)
            total = 0

            while n > 0:
                digit = n % 10
                total += digit * digit
                n //= 10

            n = total

        return True
        