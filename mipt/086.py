class Num:
    def __init__(self, n):

        if isinstance(n, type([])):
            self.l = n
            self.l.reverse()
        else:
            self.l = []
            while n > 0:
                self.l.append(n % 10)
                n /= 10

    def __imul__(self, other):

        tmp = [0] * (len(self.l) + len(other.l))

        for i in range(len(self.l)):
            t = 0
            for j in range(len(other.l)):
                tmp[i + j] += self.l[i] * other.l[j] + t
                t = tmp[i + j] / 10
                tmp[i + j] %= 10
            if t > 0:
                tmp[i + j + 1] += t

        while len(tmp) > 0 and tmp[-1] == 0:
            del tmp[-1]

        self.l = tmp

        return self

    def __eq__(self, other):
        return self.l == other.l


def main():

    a = Num(map(int,list(raw_input())))
    num = Num(1)
    i = 2

    while not a == num:
        num *= Num(i)
        i += 1

    print (i - 1)

main()