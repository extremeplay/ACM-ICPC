def ok(l, m, k)

  index = 0
  k.times do
    len = l.length
    l.delete_at( (index + m) % len )
    index = (index + m) % len
  end

  l
end

k = gets.to_i
l = []
(2*k).times { |i|
  l << i
}

me = []
k.times { |i|
  me << i
}

m = 0
until ok(l.dup, m, k) == me
  m += 1
end

puts m + 1

