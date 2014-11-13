# # the following code outputs max product of entire array
# n, a = gets.to_i, gets.chomp.split.collect { |x| x.to_i }
# pmin, pmax, maxv = a[0], a[0], a[0]
# for i in 1..n - 1
#   pmin, pmax = [a[i], pmin * a[i], pmax * a[i]].min, [a[i], pmin * a[i], pmax * a[i]].max
#   maxv = [pmin, pmax, maxv].max
# end
# print maxv

n, a = gets.to_i, gets.chomp.split.collect { |x| x.to_i }
a.sort!

l = [a[-1]]
if a[0] * a[1] * a[-1] > a[-1] * a[-2] * a[-3]
  l << a[0] << a[1]
else
  l << a[-2] << a[-3]
end
print l.join(' ').to_s