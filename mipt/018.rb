# # Slow solution O(N^2)
# def gcd(a, b)
#   if b == 0
#     return a
#   else
#     return gcd(b, a % b)
#   end
# end
#
# n = gets.to_i
#
# cnt = 0
# (2..n).each { |i|
#   (1..i - 1).each { |j|
#     if gcd(i, j) == 1
#       cnt += 1
#     end
#   }
# }
#
# le, ri = 0, cnt - 1
# sol = 0
# while le < ri
#   sol += 1
#   mid = (le + ri + 1) / 2
#   if mid - le > ri - mid + 1
#     ri = mid - 1
#   else
#     le = mid
#   end
# end
#
# puts sol


# Faster solution O(N sqrt(N))

def phi(k)

  res = 1
  i = 2
  while i * i <= k

    pow = 1

    if k % i == 0

      while k % i == 0
        k /= i
        pow *= i
      end
      res *= pow / i * (i - 1)
    end

    i += 1
  end

  if k > 1
    res *= k - 1
  end

  res
end

n = gets.to_i

cnt = 0
(2..n).each { |k|
  cnt += phi(k)
}

le, ri = 0, cnt - 1
sol = 0
while le < ri
  sol += 1
  mid = (le + ri + 1) / 2
  if mid - le > ri - mid + 1
    ri = mid - 1
  else
    le = mid
  end
end

puts sol
