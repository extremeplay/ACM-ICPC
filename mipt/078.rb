str = gets.chomp.split(//)

k = str.length - 1
while k > 0 and str[k] <= str[k - 1]
  k -= 1
end

if k == 0
  puts 'no word'
else

  i = k
  j = k
  while j < str.length
    if str[j] >  str[k - 1] and str[i] > str[j]
      i = j
    end
    j += 1
  end

  str[i], str[k - 1] = str[k - 1], str[i]

  str = str.slice(0..k - 1) + str.slice(k..-1).sort!

  puts str.join('')
end