# def count(cnt, i, k, j, l)
#   return cnt[j][l] - cnt[j][k - 1] - cnt[i - 1][l] + cnt[i - 1][k - 1]
# end
#
# n = gets.to_i
#
# cnt = Array.new(101) { Array.new(101) {0} }
# bl = Array.new(101) { Array.new(101) {0} }
#
# n.times {
#   a,b = gets.split
#   bl[a.to_i][b.to_i] = 1
# }
#
# 100.times {|i|
#   100.times {|j|
#     cnt[i + 1][j + 1] = cnt[i][j + 1] + cnt[i + 1][j] - cnt[i][j] + bl[i + 1][j + 1]
#   }
# }
#
# max = 100
#
# for i in 0..100
#   for j in i + 2 .. 100
#     for k in 0..100
#       for l in k + 2 .. 100
#         if count(cnt, i + 1, k + 1, j - 1, l - 1) == 0
#           max = [(l - k) * (j - i), max].max
#         end
#       end
#     end
#
#   end
#
# end
#
# puts max

def my_comparator(a, b)
  a[0] <=> b[0]
end

n = gets.to_i
l = []
n.times {
  l << gets.split.map{|x| x.to_i}
}

l << [0, 0]
n += 1
l << [100, 100]
n += 1

l.sort! { |a1, a2 | my_comparator(a1, a2) }

max = 0
n.times { |i|
  n.times { |j|

    if i != j and l[i][1] < l[j][1]
      last = 0
      (1..(n - 1)).each { |k|
        max = [max, (l[j][1] - l[i][1]) * (l[k][0] - l[last][0])].max
        if l[k][1] > l[i][1] and l[k][1] < l[j][1]
          last = k
        end
      }
    end
  }
}

puts max